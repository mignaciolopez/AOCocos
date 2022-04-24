#include "UISystem.h"

USING_NS_CC;

UISystem::UISystem(cocos2d::Scene* scene, entt::registry* registry)
	: m_scene(scene), m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[UISystem] Constructor");
#endif
	m_director = cocos2d::Director::getInstance();
	m_signalsManager = ECS::SignalsManager::getInstance();
	sfCache = SpriteFrameCache::getInstance();

	m_graphics = Graphics::getInstance();

	m_localEntt = entt::null;
	m_spellCasted = false;

	m_touchListener = EventListenerTouchOneByOne::create();
	m_touchListener->setSwallowTouches(false);
	m_touchListener->onTouchBegan = CC_CALLBACK_2(UISystem::onTouchBegan, this);
	m_touchListener->onTouchMoved = CC_CALLBACK_2(UISystem::onTouchMoved, this);
	m_touchListener->onTouchEnded = CC_CALLBACK_2(UISystem::onTouchEnded, this);
	m_touchListener->onTouchCancelled = CC_CALLBACK_2(UISystem::onTouchCancelled, this);
	m_scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_touchListener, m_scene);

	m_signalsManager->connect<&UISystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_signalsManager->connect<&UISystem::graphicsReload>(Signals::GRAPHICS_RELOAD_INSTANCE, this);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
	m_signalsManager->connect<&UISystem::toogleFullscreen>(Signals::UI_TOGGLE_FULLSCREEN, this);
	m_signalsManager->connect<&UISystem::toggleVSync>(Signals::UI_TOGGLE_VSYNC, this);
#endif // !Desktop Platform

	m_signalsManager->connect<&UISystem::toggleDebugInfo>(Signals::UI_TOGGLE_DEBUG, this);
	m_signalsManager->connect<&UISystem::setlblNetwork>(Signals::UI_LBL_NETWORK, this);

	m_signalsManager->connect<&UISystem::updateDebugInfo>(Signals::UI_UPDATE_DEBUG, this);
	
	m_showDebug = false;	
	m_vsync = false;

	m_director->setDisplayStats(m_showDebug);

	m_registry->on_construct<HudDebugComponent>().connect<&UISystem::onConstructHudDebugC>(this);

	m_registry->on_destroy<TBSpellsComponent>().connect<&UISystem::onDestroyTableSpellsC>(this);
	m_registry->on_destroy<HudDebugComponent>().connect<&UISystem::onDestroyHudDebugC>(this);
	m_registry->on_destroy<HudComponent>().connect<&UISystem::onDestroyHudC>(this);
}

UISystem::~UISystem()
{
#if _DEBUG
	cocos2d::log("[UISystem] Destructor");
#endif

	ECS::SignalsManager::getInstance()->disconnectAll(this);

	if (m_registry->valid(m_localEntt))
	{
		m_registry->remove_if_exists<HudDebugComponent>(m_localEntt);
		m_registry->remove_if_exists<TBSpellsComponent>(m_localEntt);
		m_registry->remove_if_exists<HudComponent>(m_localEntt);
		m_localEntt = entt::null;
	}

	m_registry->on_construct<HudDebugComponent>().disconnect<&UISystem::onConstructHudDebugC>(this);

	m_registry->on_destroy<TBSpellsComponent>().disconnect<&UISystem::onDestroyTableSpellsC>(this);
	m_registry->on_destroy<HudDebugComponent>().disconnect<&UISystem::onDestroyHudDebugC>(this);
	m_registry->on_destroy<HudComponent>().disconnect<&UISystem::onDestroyHudC>(this);
}

void UISystem::update(float dt)
{
	if (!m_registry->valid(m_localEntt))
		return;

	updatelblPosition();
}

void UISystem::onConstructHudDebugC(entt::registry & registry, entt::entity entity)
{
	auto hudC = m_registry->try_get<HudComponent>(entity);
	auto hudDC = m_registry->try_get<HudDebugComponent>(entity);
	if (!hudC || !hudDC)
	{
		return;
	}
	
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Size clippingSize = cocos2d::Size(544, 417);
	cocos2d::Vec2 clippingPos = cocos2d::Vec2(10, 45);

	//HUD NODE
	hudDC->_hudDebugNode = cocos2d::Node::create();
	hudC->_hudNode->addChild(hudDC->_hudDebugNode, 10);

	hudDC->_nodeBodyInfo = cocos2d::Node::create();
	hudDC->_nodeBodyInfo->setContentSize(clippingSize);
	hudDC->_nodeBodyInfo->setAnchorPoint(cocos2d::Vec2::ZERO);
	hudDC->_nodeBodyInfo->setIgnoreAnchorPointForPosition(false);
	hudDC->_nodeBodyInfo->setPosition(clippingPos);
	hudDC->_hudDebugNode->addChild(hudDC->_nodeBodyInfo, 5);

	//HUD GRID for debugging
	hudDC->_grid = cocos2d::DrawNode3D::create();
	//draw x
	for (int x = 0; x <= 13; x++)
	{
		hudDC->_grid->drawLine(cocos2d::Vec3(-0, 32 * x, 0), cocos2d::Vec3(544, 32 * x, 0), cocos2d::Color4F::RED);
	}
	//draw y
	for (int y = 0; y <= 17; y++)
	{
		hudDC->_grid->drawLine(cocos2d::Vec3(32 * y, 0, 0), cocos2d::Vec3(32 * y, 416, 0), cocos2d::Color4F::BLUE);
	}
	hudDC->_grid->setPosition(clippingPos);
	hudDC->_grid->setAnchorPoint(cocos2d::Vec2(0.0f, 0.0f));
	hudDC->_grid->setVisible(true);
	hudDC->_hudDebugNode->addChild(hudDC->_grid, 2);

	//HUD label Network
	cocos2d::TTFConfig ttf1("fonts/American Typewriter.ttf", 16.0f);
	ttf1.bold = false;
	hudDC->_lblNetwork = cocos2d::Label::createWithTTF(ttf1, "- -", cocos2d::TextHAlignment::LEFT);
	hudDC->_lblNetwork->setAnchorPoint(cocos2d::Vec2::ZERO);
	hudDC->_lblNetwork->setIgnoreAnchorPointForPosition(false);
	hudDC->_lblNetwork->setPosition(cocos2d::Vec2(10, clippingSize.height + clippingPos.y + 5));
	hudDC->_lblNetwork->setVisible(true);
	hudDC->_hudDebugNode->addChild(hudDC->_lblNetwork, 3);


	cocos2d::TTFConfig ttfGears("fonts/American Typewriter.ttf", 16.0f);
	ttfGears.bold = false;

	//HUD Debug Label Body
	hudDC->_lblBody = cocos2d::Label::createWithTTF(ttfGears, "Body: ", cocos2d::TextHAlignment::LEFT);
	hudDC->_lblBody->setAnchorPoint(cocos2d::Vec2::ZERO);
	hudDC->_lblBody->setIgnoreAnchorPointForPosition(false);
	hudDC->_lblBody->setPosition(cocos2d::Vec2(1, clippingSize.height - 16));
	hudDC->_lblBody->setVisible(true);
	hudDC->_nodeBodyInfo->addChild(hudDC->_lblBody);

	hudDC->_lblHead = cocos2d::Label::createWithTTF(ttfGears, "Head: ", cocos2d::TextHAlignment::LEFT);
	hudDC->_lblHead->setAnchorPoint(cocos2d::Vec2::ZERO);
	hudDC->_lblHead->setIgnoreAnchorPointForPosition(false);
	hudDC->_lblHead->setPosition(cocos2d::Vec2(1, clippingSize.height - 31));
	hudDC->_lblHead->setVisible(true);
	hudDC->_nodeBodyInfo->addChild(hudDC->_lblHead);

	hudDC->_lblHelmet = cocos2d::Label::createWithTTF(ttfGears, "Helmet: ", cocos2d::TextHAlignment::LEFT);
	hudDC->_lblHelmet->setAnchorPoint(cocos2d::Vec2::ZERO);
	hudDC->_lblHelmet->setIgnoreAnchorPointForPosition(false);
	hudDC->_lblHelmet->setPosition(cocos2d::Vec2(1, clippingSize.height - 46));
	hudDC->_lblHelmet->setVisible(true);
	hudDC->_nodeBodyInfo->addChild(hudDC->_lblHelmet);

	hudDC->_lblShield = cocos2d::Label::createWithTTF(ttfGears, "Shield: ", cocos2d::TextHAlignment::LEFT);
	hudDC->_lblShield->setAnchorPoint(cocos2d::Vec2::ZERO);
	hudDC->_lblShield->setIgnoreAnchorPointForPosition(false);
	hudDC->_lblShield->setPosition(cocos2d::Vec2(1, clippingSize.height - 61));
	hudDC->_lblShield->setVisible(true);
	hudDC->_nodeBodyInfo->addChild(hudDC->_lblShield);

	hudDC->_lblWeapon = cocos2d::Label::createWithTTF(ttfGears, "Weapon: ", cocos2d::TextHAlignment::LEFT);
	hudDC->_lblWeapon->setAnchorPoint(cocos2d::Vec2::ZERO);
	hudDC->_lblWeapon->setIgnoreAnchorPointForPosition(false);
	hudDC->_lblWeapon->setPosition(cocos2d::Vec2(1, clippingSize.height - 76));
	hudDC->_lblWeapon->setVisible(true);
	hudDC->_nodeBodyInfo->addChild(hudDC->_lblWeapon);
}

void UISystem::onDestroyHudDebugC(entt::registry & registry, entt::entity entity)
{
	if (!cocos2d::Director::getInstance()->getRunningScene())
		return;

	if (!cocos2d::Director::getInstance()->getRunningScene()->getUserData())
		return;

	auto hudC = m_registry->try_get<HudComponent>(m_localEntt);

	if (!hudC)
		return;

	auto hudDC = m_registry->try_get<HudDebugComponent>(m_localEntt);

	if (hudDC->_hudDebugNode)
	{
		hudDC->_hudDebugNode->removeAllChildren();

		if (hudDC->_hudDebugNode->getParent())
			hudDC->_hudDebugNode->getParent()->removeChild(hudDC->_hudDebugNode);
	}
}

void UISystem::onDestroyTableSpellsC(entt::registry & registry, entt::entity entity)
{
	if (!cocos2d::Director::getInstance()->getRunningScene())
		return;

	if (!cocos2d::Director::getInstance()->getRunningScene()->getUserData())
		return;

	auto hudC = m_registry->try_get<HudComponent>(m_localEntt);

	if (!hudC)
		return;

	auto tbSpellsC = m_registry->try_get<TBSpellsComponent>(m_localEntt);

	if (tbSpellsC->_tableSpells)
	{
		tbSpellsC->_tableSpells->removeAllChildren();

		if (tbSpellsC->_tableSpells->getParent())
			tbSpellsC->_tableSpells->getParent()->removeChild(tbSpellsC->_tableSpells);
	}
}

void UISystem::onDestroyHudC(entt::registry & registry, entt::entity entity)
{
	if (!cocos2d::Director::getInstance()->getRunningScene())
		return;

	if (!cocos2d::Director::getInstance()->getRunningScene()->getUserData())
		return;

	auto hudC = m_registry->try_get<HudComponent>(m_localEntt);

	if (hudC->_hudNode)
	{
		hudC->_hudNode->removeAllChildren();

		if (hudC->_hudNode->getParent())
			hudC->_hudNode->getParent()->removeChild(hudC->_hudNode);
	}
}

void UISystem::setLocalEntity(entt::entity entity,  SLNet::BitStream* bs)
{
	m_localEntt = entity;
}

void UISystem::graphicsReload(entt::entity entity, SLNet::BitStream * bs)
{
	m_graphics = Graphics::getInstance();
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
void UISystem::toogleFullscreen(entt::entity entity, SLNet::BitStream* bs)
{
	cocos2d::GLViewImpl* glview = dynamic_cast<cocos2d::GLViewImpl*>(m_director->getOpenGLView());
	if (glview->isFullscreen())
	{
		glview->setWindowed(glview->getDesignResolutionSize().width, glview->getDesignResolutionSize().height);
	}
	else
	{
		glview->setFullscreen();
	}
}

void UISystem::toggleVSync(entt::entity entity,  SLNet::BitStream* bs)
{
	if (m_vsync)
	{
		//m_director->getOpenGLView()->setSwapInterval(0);
		m_director->setAnimationInterval(1.0f / 5000);
		m_vsync = false;
	}
	else
	{
		//m_director->getOpenGLView()->setSwapInterval(1);
		m_director->setAnimationInterval(1.0f / 60); //to delete when setswapInterval implemented
		m_vsync = true;
	}
}
#endif // !Desktop Platform

void UISystem::toggleDebugInfo(entt::entity entity,  SLNet::BitStream* bs)
{
	m_showDebug = !m_showDebug;

	m_director->setDisplayStats(m_showDebug);

	if (!m_registry->valid(m_localEntt))
		return;

	auto hudDC = m_registry->try_get<HudDebugComponent>(m_localEntt);

	if (hudDC)
	{
		m_registry->remove_if_exists<HudDebugComponent>(m_localEntt);
	}
	else
	{
		m_registry->assign<HudDebugComponent>(m_localEntt);
		updateDebugInfo(m_localEntt, nullptr);
	}
}

void UISystem::setlblNetwork(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!bs)
		return;

	if (!m_registry->valid(m_localEntt))
		return;

	auto hudDC = m_registry->try_get<HudDebugComponent>(m_localEntt);

	if (!hudDC)
		return;

	bool online = false;
	int latency = -1;
	bs->Read(online);
	bs->Read(latency);

	if (online)
	{
		hudDC->_lblNetwork->setTextColor(Color4B::GREEN);
		hudDC->_lblNetwork->setString("LATENCY: " + std::to_string(latency));
	}
	else
	{
		hudDC->_lblNetwork->setTextColor(Color4B::RED);
		hudDC->_lblNetwork->setString("O F F L I N E");
	}
}

void UISystem::updateDebugInfo(entt::entity entity,  SLNet::BitStream* bs)
{
	if (!m_registry->valid(m_localEntt))
		return;

	if (!m_registry->has<HudDebugComponent>(m_localEntt))
		return;

	if (!m_registry->has<PlayerComponent>(m_localEntt))
		return;

	auto hudDC = m_registry->try_get<HudDebugComponent>(m_localEntt);
	auto playerC = m_registry->try_get<PlayerComponent>(m_localEntt);

	hudDC->_lblBody->setString("Body: " + std::to_string(playerC->_body));
	hudDC->_lblHead->setString("Head: " + std::to_string(playerC->_head));
	hudDC->_lblShield->setString("Shield: " + std::to_string(playerC->_shield));
	hudDC->_lblHelmet->setString("Helmet: " + std::to_string(playerC->_helmet));
	hudDC->_lblWeapon->setString("Weapon: " + std::to_string(playerC->_weapon));
}

bool UISystem::onTouchBegan(const cocos2d::Touch * touch, cocos2d::Event * ccEvnt)
{
	float x = touch->getLocation().x;
	float y = touch->getLocation().y;
#if _DEBUG
	cocos2d::log("[UISystem] Touch: (%f, %f).", x, y);
#endif
	if (x > 10 && y > 48 && x < 554 && y < 466) //with spell casted it needs to check on touchend
	{
		return true;
	}
	else if (x > 590 && x < 765 && y > 449 && y < 475) //toggle inventory
	{
		return true;
	}
	else if (x > 587 && x < 669 && y > 214 && y < 249) //castSpell
	{
		castSpell(x, y);
		return true;
	}

	return false;
}

void UISystem::onTouchMoved(const cocos2d::Touch * touch, cocos2d::Event * ccEvnt)
{

}

void UISystem::onTouchEnded(const cocos2d::Touch * touch, cocos2d::Event * ccEvnt)
{
	float x = touch->getLocation().x;
	float y = touch->getLocation().y;

	if (x > 10 && y > 48 && x < 554 && y < 466)
	{
		if (m_spellCasted)
		{
			SLNet::BitStream bsInt;
			bsInt.Write(x);
			bsInt.Write(y);
			m_director->getOpenGLView()->setDefaultCursor();
			m_signalsManager->publish(Signals::UI_SPELL_TRHOUW, m_localEntt, &bsInt);
			m_spellCasted = false;
		}
	}
	else if (x > 590 && x < 765 && y > 449 && y < 475) //toggle inventory
	{
		toggleInventory(x, y);
	}
}

void UISystem::onTouchCancelled(const cocos2d::Touch * touch, cocos2d::Event * ccEvnt)
{
}

void UISystem::updatelblPosition()
{
	if (!m_registry->valid(m_localEntt))
		return;

	auto hudC = m_registry->try_get<HudComponent>(m_localEntt);

	if (!hudC)
		return;

	auto mapC = m_registry->try_get<MapComponent>(m_localEntt);

	if (!mapC)
		return;

	auto posC = m_registry->try_get<PositionComponent>(m_localEntt);

	if (!posC)
		return;
	
	hudC->_lblPosition->setString("Mapa: " + std::to_string(mapC->_tag) +
		" (" + std::to_string(posC->_x) + ", " + std::to_string(posC->_y) + ")");
}

void UISystem::toggleInventory(float x, float y)
{
	if (!m_registry->valid(m_localEntt))
		return;

	if (!m_registry->has<HudComponent>(m_localEntt))
		return;

	if (!m_registry->has<TBSpellsComponent>(m_localEntt))
		return;

	auto hudC = m_registry->try_get<HudComponent>(m_localEntt);

	auto tbSpellsC = m_registry->try_get<TBSpellsComponent>(m_localEntt);

	auto inventoryC = m_registry->try_get<InventoryComponent>(m_localEntt);

	if (!hudC || !tbSpellsC || !inventoryC)
		return;

	if (x > 590 && x < 675 &&
		y > 449 && y < 475)
	{
		hudC->_sprInventory->setVisible(true);
		inventoryC->_node->setVisible(true);
		hudC->_sprSpells->setVisible(false);
		tbSpellsC->_tableSpells->setVisible(false);

		if (m_registry->has<FXComponent>(m_localEntt))
			m_registry->replace<FXComponent>(m_localEntt, [](auto &fxC) { fxC._FXs.push_back(FXS::Click_01); });
	}
	else if (x > 670 && x < 765 &&
		y > 449 && y < 475)
	{
		hudC->_sprInventory->setVisible(false);
		inventoryC->_node->setVisible(false);
		hudC->_sprSpells->setVisible(true);
		tbSpellsC->_tableSpells->setVisible(true);

		if (m_registry->has<FXComponent>(m_localEntt))
			m_registry->replace<FXComponent>(m_localEntt, [](auto &fxC) { fxC._FXs.push_back(FXS::Click_01); });
	}
}

void UISystem::castSpell(float x, float y)
{
	if (!m_registry->valid(m_localEntt))
		return;

	auto intC = m_registry->try_get<IntervalComponent>(m_localEntt);

	if (!intC)
		return;

	if (intC->_dtLastCastSpell < intC->_constCastSpell)
	{
		//show u cant attack yet
		return;
	}

	auto hudC = m_registry->try_get<HudComponent>(m_localEntt);

	if (!hudC)
		return;

	if (!hudC->_sprSpells->isVisible())
		return;

	if (!m_registry->has<TBSpellsComponent>(m_localEntt))
		return;
	auto tbSpellsC = m_registry->try_get<TBSpellsComponent>(m_localEntt);

	if (!tbSpellsC)
		return;

	if (tbSpellsC->_selected == -1 || m_spellCasted)
	{
#ifdef _DEBUG
		cocos2d::log("[UISystem] spell not selected: (%f, %f)", x, y);
#endif
		return;
	}
	
	if (x > 587 && x < 669 &&
		y > 214 && y < 249)
	{
		m_director->getOpenGLView()->setCursor("cursor2.png", Vec2::ANCHOR_MIDDLE);
		m_spellCasted = true;
		intC->_dtLastCastSpell = 0.0f;
	}
}
