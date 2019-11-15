#include "UISystem.h"

USING_NS_CC;

UISystem::UISystem(cocos2d::Scene* scene) : m_scene(scene)
{
	cocos2d::log("%s Constructor", "[UI SYSTEM]");

	m_director = cocos2d::Director::getInstance();
	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();
	sfCache = SpriteFrameCache::getInstance();

	m_localeid = -1;

	TP::Interface::addSpriteFramesToCache();

	auto s = m_director->getWinSize();

	auto camera = Camera::create();
	camera->retain();
	camera->setCameraFlag(CameraFlag::USER1);

	m_layer = Layer::create();
	m_layer->addChild(camera);
	m_layer->setCameraMask(static_cast<int>(CameraFlag::USER1));
	m_scene->addChild(m_layer, 1);


	Sprite* mainWindow = Sprite::createWithSpriteFrameName(TP::Interface::ventanaPrincipal);
	mainWindow->setAnchorPoint(Vec2(0.0f, 0.0f));
	mainWindow->setCameraMask(static_cast<int>(CameraFlag::USER1));
	m_layer->addChild(mainWindow);

	m_eventManager->Subscribe(EVENTS::MY_EID, &UISystem::setLocaleid, this);

	m_eventManager->Subscribe(EVENTS::MOUSE_PRESSED, &UISystem::clicked, this);
	m_eventManager->Subscribe(EVENTS::MOUSE_RELEASED, &UISystem::clicked, this);
	m_eventManager->Subscribe(EVENTS::UI_TOGGLE_FULLSCREEN, &UISystem::toogleFullscreen, this);

	m_eventManager->Subscribe(EVENTS::MOUSE_SCROLL, &UISystem::scroll, this);
	//m_eventManager->Subscribe(EVENTS::MOUSE_MOVE, &UISystem::clicked, this);

	m_eventManager->Subscribe(EVENTS::UI_TOGGLE_DEBUG, &UISystem::toggleDebugInfo, this);
	m_eventManager->Subscribe(EVENTS::UI_LBL_NETWORK, &UISystem::setlblNetwork, this);

	m_eventManager->Subscribe(EVENTS::UI_TOGGLE_VSYNC, &UISystem::toggleVSync, this);
	
#if _DEBUG
	m_showDebug = true;
#else
	m_showDebug = false;
#endif
	
	m_vsync = false;

	createLabels();
	createInventoryAndSpells();

	m_layer->setCameraMask(static_cast<int>(CameraFlag::USER1));
}

UISystem::~UISystem()
{
	TP::Interface::removeSpriteFramesFromCache();
#if _DEBUG
	cocos2d::log("%s Destructor", "[UI SYSTEM]");
#endif
}

void UISystem::Update()
{
	if (m_localeid == -1)
		return;

	updatelblPosition();

	if (m_showDebug)
	{
		m_lblNetwork->setVisible(true);
		m_director->setDisplayStats(true);
	}
	else
	{
		m_lblNetwork->setVisible(false);
		m_director->setDisplayStats(false);
	}
}

void UISystem::setLocaleid(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_localeid = eid;
}

void UISystem::clicked(int eid, cocos2d::Event * ccevnt, SLNet::BitStream* bs)
{
	cocos2d::EventMouse* mouseEvent;
	try
	{
		mouseEvent = dynamic_cast<cocos2d::EventMouse*>(ccevnt);
	}
	catch (std::bad_cast& e)
	{
		cocos2d::log("%s onMouse##Event: %s", "[INPUT SYSTEM]", e.what());
		return;
	}

	toggleInventory(mouseEvent->getLocation().x, mouseEvent->getLocation().y);

	cocos2d::log("Entity: %i | Mouse Button: %i | X: %f, Y: %f",
		eid, mouseEvent->getMouseButton(), mouseEvent->getLocation().x, mouseEvent->getLocation().y);
}

void UISystem::scroll(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	cocos2d::EventMouse* mouseEvent;
	try
	{
		mouseEvent = dynamic_cast<cocos2d::EventMouse*>(ccevnt);
	}
	catch (std::bad_cast& e)
	{
		cocos2d::log("%s onMouse##Event: %s", "[INPUT SYSTEM]", e.what());
		return;
	}

	SLNet::BitStream bsInter;
	bsInter.Write(mouseEvent->getScrollY());

	if (mouseEvent->getScrollY() < 0)
		m_eventManager->execute(EVENTS::CAMERA_ZOOM_IN, eid, nullptr, &bsInter);
	else
		m_eventManager->execute(EVENTS::CAMERA_ZOOM_OUT, eid, nullptr, &bsInter);
}

void UISystem::toogleFullscreen(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	cocos2d::GLViewImpl* view = dynamic_cast<cocos2d::GLViewImpl*>(m_director->getOpenGLView());
	if (view->isFullscreen())
	{
		//SQLiteManager::GetInstance()->Update("fullScreen", 0);
		view->setWindowed(m_windowSize.width, m_windowSize.height);
	}
	else
	{
		//SQLiteManager::GetInstance()->Update("fullScreen", 1);
		view->setFullscreen();
	}
#endif
}

void UISystem::toggleDebugInfo(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	m_showDebug = !m_showDebug;
}

void UISystem::setlblNetwork(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	if (!bs)
		return;

	bool online = false;
	int latency = -1;
	bs->Read(online);
	bs->Read(latency);

	if (online)
	{
		m_lblNetwork->setTextColor(Color4B::GREEN);
		m_lblNetwork->setString("LATENCY: " + std::to_string(latency));
	}
	else
	{
		m_lblNetwork->setTextColor(Color4B::RED);
		m_lblNetwork->setString("O F F L I N E");
	}
}

void UISystem::toggleVSync(int eid, cocos2d::Event * ccevnt, SLNet::BitStream * bs)
{
	if (m_vsync)
	{
		m_director->getOpenGLView()->setSwapInterval(0);
		m_director->setAnimationInterval(1.0f / 2000);
		m_vsync = false;
	}
	else
	{
		m_director->getOpenGLView()->setSwapInterval(1);
		m_vsync = true;
	}
}

void UISystem::createLabels()
{
	createlblPosition();
	createlblNetwork();
}

void UISystem::createlblPosition()
{
	TTFConfig ttf("fonts/American Typewriter.ttf", 12.0f);
	ttf.bold = true;

	m_lblPosition = Label::createWithTTF(ttf, "American Typewriter", TextHAlignment::LEFT);
	m_lblPosition->setPosition(Vec2(625, 24));
	m_layer->addChild(m_lblPosition);
}

void UISystem::updatelblPosition()
{
	int x = m_entityManager->getComp(m_localeid, POSITION)->getX();
	int y = m_entityManager->getComp(m_localeid, POSITION)->getY();
	m_lblPosition->setString("Mapa: 1 (" + std::to_string(x) + ", " + std::to_string(y) + ")");
}

void UISystem::createlblNetwork()
{
	TTFConfig ttf("fonts/American Typewriter.ttf", 16.0f);
	ttf.bold = false;

	m_lblNetwork = Label::createWithTTF(ttf, "American Typewriter", TextHAlignment::LEFT);
	m_lblNetwork->setPosition(Vec2(50, 473));
	m_layer->addChild(m_lblNetwork);
	m_lblNetwork->setVisible(false);
}

void UISystem::createInventoryAndSpells()
{
	m_sprInventory = TP::Interface::createCentroInventarioSprite();
	m_sprSpells = TP::Interface::createCentroHechizosSprite();

	m_layer->addChild(m_sprInventory);
	m_layer->addChild(m_sprSpells);

	m_sprInventory->setAnchorPoint(Vec2(0, 0));
	m_sprSpells->setAnchorPoint(Vec2(0, 0));

	m_sprInventory->setPosition(567, 200);
	m_sprSpells->setPosition(567, 200);

	m_sprSpells->setVisible(false);

}

void UISystem::toggleInventory(int x, int y)
{
	if (x > 570 && y > 115 && x < 667 && y < 145)
	{
		m_sprInventory->setVisible(true);
		m_sprSpells->setVisible(false);
	}
	else if(x > 668 && y > 115 && x < 762 && y < 145)
	{
		m_sprInventory->setVisible(false);
		m_sprSpells->setVisible(true);
	}
}
