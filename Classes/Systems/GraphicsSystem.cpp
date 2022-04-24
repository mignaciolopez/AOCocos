#include "GraphicsSystem.h"

USING_NS_CC;

GraphicsSystem::GraphicsSystem(entt::registry* registry) : m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[GraphicsSystem] Constructor");
#endif

	m_fileUtils = FileUtils::getInstance();
	m_sfCache = SpriteFrameCache::getInstance();

	m_signalsManager = ECS::SignalsManager::getInstance();

	m_signalsManager->connect<&GraphicsSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_signalsManager->connect<&GraphicsSystem::loadBody>(Signals::GRAPHICS_LOAD_BODY, this);
	m_signalsManager->connect<&GraphicsSystem::loadHead>(Signals::GRAPHICS_LOAD_HEAD, this);
	//m_signalsManager->connect<&GraphicsSystem::loadHelmet>(Signals::GRAPHICS_LOAD_HELMET, this);
	//m_signalsManager->connect<&GraphicsSystem::loadShield>(Signals::GRAPHICS_LOAD_SHIELD, this);
	//m_signalsManager->connect<&GraphicsSystem::loadWeapon>(Signals::GRAPHICS_LOAD_WEAPON, this);

	m_signalsManager->connect<&GraphicsSystem::graphicsReload>(Signals::GRAPHICS_RELOAD_INSTANCE, this);

	m_graphics = Graphics::getInstance();

	m_localEntt = entt::null;

	m_registry->on_construct<PlayerComponent>().connect<&GraphicsSystem::onConstructPlayerC>(this);
	m_registry->on_destroy<PlayerComponent>().connect<&GraphicsSystem::onDestroyPlayerC>(this);
}

GraphicsSystem::~GraphicsSystem()
{
#if _DEBUG
	cocos2d::log("[GraphicsSystem] Destructor");
#endif

	
	ECS::SignalsManager::getInstance()->disconnectAll(this);

	m_registry->on_construct<PlayerComponent>().disconnect<&GraphicsSystem::onConstructPlayerC>(this);
	m_registry->on_destroy<PlayerComponent>().disconnect<&GraphicsSystem::onDestroyPlayerC>(this);
}

void GraphicsSystem::update(float dt)
{
}

void GraphicsSystem::onConstructPlayerC(entt::registry & registry, entt::entity entity)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	auto mapC = m_registry->try_get<MapComponent>(m_localEntt);

	//body
	playerC->_spriteBody = cocos2d::Sprite::create();
	loadBody(entity, nullptr);
	playerC->_spriteBody->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER1));
	playerC->_spriteBody->setIgnoreAnchorPointForPosition(false);
	playerC->_spriteBody->setAnchorPoint(cocos2d::Vec2(0.5f, 0.0f));
	playerC->_spriteBody->setPosition(playerC->_x * 32 + 16, playerC->_y * 32);
	mapC->_map->addChild(playerC->_spriteBody);
	
	//Head
	playerC->_spriteHead = cocos2d::Sprite::create();
	loadHead(entity, nullptr);
	playerC->_spriteHead->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER1));
	playerC->_spriteHead->setIgnoreAnchorPointForPosition(false);
	playerC->_spriteHead->setAnchorPoint(cocos2d::Vec2(0.5f, 0.0f));
	playerC->_spriteHead->setPosition(cocos2d::Vec2(playerC->_spriteBody->getContentSize().width * 0.5f, 2));
	playerC->_spriteBody->addChild(playerC->_spriteHead, 0);

	//Helmet
	/*playerC->_spriteHelmet = cocos2d::Sprite::create();
	loadHelmet(entity, nullptr, nullptr, nullptr);
	playerC->_spriteHelmet->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER1));
	playerC->_spriteHelmet->setIgnoreAnchorPointForPosition(false);
	playerC->_spriteHelmet->setAnchorPoint(cocos2d::Vec2(0.5f, 0.0f));
	playerC->_spriteHelmet->setPosition(cocos2d::Vec2(playerC->_spriteBody->getContentSize().width * 0.5f, playerC->_spriteBody->getContentSize().height - 7));
	playerC->_spriteBody->addChild(playerC->_spriteHelmet, 1);*/

	//Shield
	/*playerC->_spriteShield = cocos2d::Sprite::create();
	loadShield(entity, nullptr, nullptr, nullptr);
	playerC->_spriteShield->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER1));
	playerC->_spriteShield->setIgnoreAnchorPointForPosition(false);
	playerC->_spriteShield->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
	playerC->_spriteShield->setPosition(cocos2d::Vec2(playerC->_spriteBody->getContentSize().width * 0.5f, playerC->_spriteBody->getContentSize().height * 0.5f));
	playerC->_spriteBody->addChild(playerC->_spriteShield, 3);*/

	//Weapon
	/*playerC->_spriteWeapon = cocos2d::Sprite::create();
	loadWeapon(entity, nullptr, nullptr, nullptr);
	playerC->_spriteWeapon->setCameraMask(static_cast<int>(cocos2d::CameraFlag::USER1));
	playerC->_spriteWeapon->setIgnoreAnchorPointForPosition(false);
	playerC->_spriteWeapon->setAnchorPoint(cocos2d::Vec2(0.5f, 0.5f));
	playerC->_spriteWeapon->setPosition(cocos2d::Vec2(playerC->_spriteBody->getContentSize().width * 0.5f, playerC->_spriteBody->getContentSize().height * 0.5f));
	playerC->_spriteBody->addChild(playerC->_spriteWeapon, 2);*/
}

void GraphicsSystem::onDestroyPlayerC(entt::registry & registry, entt::entity entity)
{
	if (!cocos2d::Director::getInstance()->getRunningScene())
		return;

	if (!cocos2d::Director::getInstance()->getRunningScene()->getUserData())
		return;

	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (playerC->_spriteBody)
	{
		playerC->_spriteBody->removeAllChildren();

		if (playerC->_spriteBody->getParent())
			playerC->_spriteBody->getParent()->removeChild(playerC->_spriteBody);
	}
}

void GraphicsSystem::setLocalEntity(entt::entity entity, SLNet::BitStream* bs)
{
	m_localEntt = entity;
}

void GraphicsSystem::loadBody(entt::entity entity, SLNet::BitStream* bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
	{
		return;
	}

	if (bs)
	{
		Bodies body;
		bs->Read(body);
		playerC->_body = body;
	}

	if (!playerC->_body)
	{
		playerC->_spriteBody->setVisible(false);
		m_signalsManager->publish(Signals::UI_UPDATE_DEBUG, entity);
		return;
	}

	playerC->_spriteBody->setVisible(true);

	for (auto& it : m_graphics->getBodyStanding(playerC->_body))
		playerC->_bodyStandingFrame[it->_dir] = it->_id;

	for (auto& it : m_graphics->getBodyAnimationsFrames(playerC->_body))
	{
		Vector<SpriteFrame*> spriteFrames;

		for (auto& frame : it->_frames)
		{
			spriteFrames.pushBack(m_sfCache->getSpriteFrameByName(std::to_string(frame)));
		}

		Animate* anim;
		anim = Animate::create(Animation::createWithSpriteFrames(spriteFrames, it->_speed));
		anim->retain();

		switch(it->_dir)
		{
			case Directions::North:
				if (playerC->_animBody[0])
					playerC->_animBody[0]->release();

				playerC->_animBody[0] = anim;
				break;
			case Directions::East:
				if (playerC->_animBody[1])
					playerC->_animBody[1]->release();

				playerC->_animBody[1] = anim;
				break;
			case Directions::South:
				if (playerC->_animBody[2])
					playerC->_animBody[2]->release();
				
				playerC->_animBody[2] = anim;
				break;
			case Directions::West:
				if (playerC->_animBody[3])
					playerC->_animBody[3]->release();
				
				playerC->_animBody[3] = anim;
				break;
		}
		
	}

	if (!playerC->_spriteBody->getActionByTag(AxnTags::AnimateSeqBody))
		m_signalsManager->publish(Signals::ANIMATE_SET_BODY, entity);

	m_signalsManager->publish(Signals::UI_UPDATE_DEBUG, entity);
}

void GraphicsSystem::loadHead(entt::entity entity, SLNet::BitStream * bs)
{
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
	{
		return;
	}

	if (bs)
	{
		Heads head;
		bs->Read(head);
		playerC->_head = head;
	}

	if (!playerC->_head)
	{
		playerC->_spriteHead->setVisible(false);
		m_signalsManager->publish(Signals::UI_UPDATE_DEBUG, entity);
		return;
	}

	playerC->_spriteHead->setVisible(true);

	for (auto& it : m_graphics->getHeads(playerC->_head))
		playerC->_headFrame[it->_dir] = it->_id;

	//playerC->_spriteHead->setSpriteFrame(m_sfCache->getSpriteFrameByName(std::to_string(playerC->_headFrame[playerC->_direction])));
	m_signalsManager->publish(Signals::ANIMATE_SET_HEAD, entity);
	m_signalsManager->publish(Signals::UI_UPDATE_DEBUG, entity);
}

void GraphicsSystem::graphicsReload(entt::entity entity, SLNet::BitStream * bs)
{
	m_graphics = Graphics::getInstance();
}
