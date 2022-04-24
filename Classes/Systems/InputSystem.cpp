#include "InputSystem.h"

#include "cocos2d.h"

USING_NS_CC;

InputSystem::InputSystem(cocos2d::Scene* scene, entt::registry* registry)
	: m_scene(scene), m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[InputSystem] Constructor");
#endif

	m_director = cocos2d::Director::getInstance();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
	for (int i = 0; i < 256; i++)
		m_keyStates[i] = false;

	m_kbListener = cocos2d::EventListenerKeyboard::create();
	m_kbListener->retain();

	m_director->getOpenGLView()->setIMEKeyboardState(true);
	m_kbListener->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* ccevnt)
	{
		m_keyStates[static_cast<int>(keyCode)] = true;
		keyPressed(keyCode);
	};
	m_kbListener->onKeyReleased = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* ccevnt)
	{
		m_keyStates[static_cast<int>(keyCode)] = false;
		keyReleased(keyCode);
	};

	m_scene->getEventDispatcher()->addEventListenerWithFixedPriority(m_kbListener, 1);
#endif // !Destop Platform

	m_signalsManager = ECS::SignalsManager::getInstance();

	m_signalsManager->connect<&InputSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);

	m_localEntt = entt::null;

	
}

InputSystem::~InputSystem()
{
#if _DEBUG
	cocos2d::log("[InputSystem] Destructor");
#endif

	

	ECS::SignalsManager::getInstance()->disconnectAll(this);

	if (Director::getInstance())
	{
		if (Director::getInstance()->getRunningScene())
		{
			m_scene = Director::getInstance()->getRunningScene();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
			if (m_kbListener)
			{
				if (m_kbListener->getReferenceCount() > 0)
					m_kbListener->release();

				if (m_scene->getEventDispatcher()->hasEventListener(m_kbListener->LISTENER_ID))
					m_scene->getEventDispatcher()->removeEventListener(m_kbListener);
			}
#endif // !Destop Platform
		}
	}
}

void InputSystem::update(float dt)
{
	if (!m_registry->valid(m_localEntt))
		return;
	
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
	if (m_keyStates[static_cast<int>(EventKeyboard::KeyCode::KEY_UP_ARROW)])
	{
		m_signalsManager->publish(Signals::MOVE_NORTH, m_localEntt);
	}
	else if (m_keyStates[static_cast<int>(EventKeyboard::KeyCode::KEY_RIGHT_ARROW)])
	{
		m_signalsManager->publish(Signals::MOVE_EAST, m_localEntt);
	}
	else if (m_keyStates[static_cast<int>(EventKeyboard::KeyCode::KEY_DOWN_ARROW)])
	{
		m_signalsManager->publish(Signals::MOVE_SOUTH, m_localEntt);
	}
	else if (m_keyStates[static_cast<int>(EventKeyboard::KeyCode::KEY_LEFT_ARROW)])
	{
		m_signalsManager->publish(Signals::MOVE_WEST, m_localEntt);
	}

#endif // !Destop Platform

}

void InputSystem::setLocalEntity(entt::entity entity, SLNet::BitStream* bs)
{
	m_localEntt = entity;
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
void InputSystem::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
		m_director->end();

	if (!m_registry->valid(m_localEntt))
		return;

	SLNet::BitStream bsOut;

	auto playerC = m_registry->try_get<PlayerComponent>(m_localEntt);
	int body = static_cast<int>(playerC->_body);
	int head = static_cast<int>(playerC->_head);
	int helmet = static_cast<int>(playerC->_helmet);
	int shield = static_cast<int>(playerC->_shield);
	int weapon = static_cast<int>(playerC->_weapon);
	

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_F1:
		m_signalsManager->publish(Signals::MAP_TOGGLE_DEBUG, m_localEntt);
		break;
	case EventKeyboard::KeyCode::KEY_F2:
		m_signalsManager->publish(Signals::UI_TOGGLE_DEBUG, m_localEntt);
		break;
	case EventKeyboard::KeyCode::KEY_F3:
		m_signalsManager->publish(Signals::UI_TOGGLE_VSYNC, m_localEntt);
		break;
	case EventKeyboard::KeyCode::KEY_F11:
		m_signalsManager->publish(Signals::UI_TOGGLE_FULLSCREEN, m_localEntt);
		break;
	case EventKeyboard::KeyCode::KEY_C:

		break;
	case EventKeyboard::KeyCode::KEY_N:
		m_signalsManager->publish(Signals::AUDIO_TOGGLE_FX, m_localEntt);
		break;
	case EventKeyboard::KeyCode::KEY_M:
		m_signalsManager->publish(Signals::AUDIO_TOGGLE_MUSIC, m_localEntt);
		break;
	case EventKeyboard::KeyCode::KEY_R:
		bsOut.Reset();
		bsOut.Write(ParticleAnims::ExplodingRing);
		m_signalsManager->publish(Signals::PARTICLES_ANIM_SPAWN, m_localEntt, &bsOut);

		if (m_registry->has<FXComponent>(m_localEntt))
			m_registry->replace<FXComponent>(m_localEntt, [](auto &fxC) { fxC._FXs.push_back(FXS::Resurrect); });

		bsOut.Reset();
		bsOut.Write((SLNet::MessageID)Signals::PARTICLES_ANIM_SPAWN);
		bsOut.Write(m_localEntt);
		bsOut.Write(ParticleAnims::ExplodingRing);
		m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		break;
	case EventKeyboard::KeyCode::KEY_U:
		m_signalsManager->publish(Signals::INVENTORY_ITEM_USE, m_localEntt);
		break;
	case EventKeyboard::KeyCode::KEY_END:		
		bsOut.Reset();
		bsOut.Write((SLNet::MessageID)Signals::MEDITATE);
		bsOut.Write(m_localEntt);
		m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		break;
	case EventKeyboard::KeyCode::KEY_KP_PLUS:
		if (animation == 783)
			animation = -1;
		
		animation++;
#if _DEBUG
		cocos2d::log("[InputSystem] animation: %d", animation);
#endif
		bsOut.Reset();
		bsOut.Write(static_cast<Animations>(animation));
		m_signalsManager->publish(Signals::ANIMATE_SPELL, m_localEntt, &bsOut);
		bsOut.Reset();
		bsOut.Write((SLNet::MessageID)Signals::ANIMATE_SPELL);
		bsOut.Write(m_localEntt);
		bsOut.Write(static_cast<Animations>(animation));
		m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		break;
	case EventKeyboard::KeyCode::KEY_KP_MINUS:
		if (animation == 0)
			animation = 784;

		animation--;
#if _DEBUG
		cocos2d::log("[InputSystem] animation: %d", animation);
#endif
		bsOut.Reset();
		bsOut.Write(static_cast<Animations>(animation));
		m_signalsManager->publish(Signals::ANIMATE_SPELL, m_localEntt, &bsOut);
		bsOut.Reset();
		bsOut.Write((SLNet::MessageID)Signals::ANIMATE_SPELL);
		bsOut.Write(m_localEntt);
		bsOut.Write(static_cast<Animations>(animation));
		m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		break;
	case EventKeyboard::KeyCode::KEY_I:
#if _DEBUG
		cocos2d::log("[InputSystem] animation: %d", animation);
#endif
		bsOut.Reset();
		bsOut.Write(static_cast<Animations>(animation));
		m_signalsManager->publish(Signals::ANIMATE_SPELL, m_localEntt, &bsOut);
		bsOut.Reset();
		bsOut.Write((SLNet::MessageID)Signals::ANIMATE_SPELL);
		bsOut.Write(m_localEntt);
		bsOut.Write(static_cast<Animations>(animation));
		m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		break;
	case EventKeyboard::KeyCode::KEY_O:
		/*m_signalsManager->publish(Signals::ANIMATE_WEAPON, m_localEntt);
		bsOut.Write((SLNet::MessageID)Signals::ANIMATE_WEAPON);
		bsOut.Write(m_localEntt);
		m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);*/
		break;
	case EventKeyboard::KeyCode::KEY_P:
	/*	m_signalsManager->publish(Signals::ANIMATE_SHIELD, m_localEntt);
		bsOut.Write((SLNet::MessageID)Signals::ANIMATE_SHIELD);
		bsOut.Write(m_localEntt);
		m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);*/
		break;
	case EventKeyboard::KeyCode::KEY_KP_MULTIPLY:
		if (playerC)
		{
			if (body == 6)
				body = -1;
			playerC->_body = static_cast<Bodies>(++body);
			m_signalsManager->publish(Signals::GRAPHICS_LOAD_BODY, m_localEntt);

			bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_BODY);
			bsOut.Write(m_localEntt);
			bsOut.Write(playerC->_body);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		}
		break;
	case EventKeyboard::KeyCode::KEY_KP_DIVIDE:
		if (playerC)
		{
			if (body == 0)
				body = 7;
			playerC->_body = static_cast<Bodies>(--body);
			m_signalsManager->publish(Signals::GRAPHICS_LOAD_BODY, m_localEntt);

			bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_BODY);
			bsOut.Write(m_localEntt);
			bsOut.Write(playerC->_body);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		}
		break;
	case EventKeyboard::KeyCode::KEY_9:
		if (playerC)
		{
			if (head == 237)
				head = -1;
			playerC->_head = static_cast<Heads>(++head);
			m_signalsManager->publish(Signals::GRAPHICS_LOAD_HEAD, m_localEntt);

			bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_HEAD);
			bsOut.Write(m_localEntt);
			bsOut.Write(playerC->_head);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		}
		break;
	case EventKeyboard::KeyCode::KEY_8:
		if (playerC)
		{
			if (head == 0)
				head = 238;
			playerC->_head = static_cast<Heads>(--head);
			m_signalsManager->publish(Signals::GRAPHICS_LOAD_HEAD, m_localEntt);

			bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_HEAD);
			bsOut.Write(m_localEntt);
			bsOut.Write(playerC->_head);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		}
		break;
	case EventKeyboard::KeyCode::KEY_6:
	/*	if (playerC)
		{
			if (helmet == 16)
				helmet = -1;
			playerC->_helmet = static_cast<Helmet>(++helmet);
			m_signalsManager->publish(Signals::GRAPHICS_LOAD_HELMET, m_localEntt);

			bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_HELMET);
			bsOut.Write(m_localEntt);
			bsOut.Write(playerC->_helmet);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		}*/
		break;
	case EventKeyboard::KeyCode::KEY_5:
	/*	if (playerC)
		{
			if (helmet == 0)
				helmet = 17;
			playerC->_helmet = static_cast<Helmet>(--helmet);
			m_signalsManager->publish(Signals::GRAPHICS_LOAD_HELMET, m_localEntt);

			bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_HELMET);
			bsOut.Write(m_localEntt);
			bsOut.Write(playerC->_helmet);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		}*/
		break;
	case EventKeyboard::KeyCode::KEY_3:
	/*	if (playerC)
		{
			if (shield == 10)
				shield = -1;
			playerC->_shield = static_cast<Shield>(++shield);
			m_signalsManager->publish(Signals::GRAPHICS_LOAD_SHIELD, m_localEntt);

			bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_SHIELD);
			bsOut.Write(m_localEntt);
			bsOut.Write(playerC->_shield);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		}*/
		break;
	case EventKeyboard::KeyCode::KEY_2:
	/*	if (playerC)
		{
			if (shield == 0)
				shield = 11;
			playerC->_shield = static_cast<Shield>(--shield);
			m_signalsManager->publish(Signals::GRAPHICS_LOAD_SHIELD, m_localEntt);

			bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_SHIELD);
			bsOut.Write(m_localEntt);
			bsOut.Write(playerC->_shield);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		}*/
		break;
	case EventKeyboard::KeyCode::KEY_PERIOD:
	/*	if (playerC)
		{
			if (weapon == 76)
				weapon = -1;
			playerC->_weapon = static_cast<Weapon>(++weapon);
			m_signalsManager->publish(Signals::GRAPHICS_LOAD_WEAPON, m_localEntt);

			bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_WEAPON);
			bsOut.Write(m_localEntt);
			bsOut.Write(playerC->_weapon);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		}*/
		break;
	case EventKeyboard::KeyCode::KEY_0:
		/*if (playerC)
		{
			if (weapon == 0)
				weapon = 77;
			playerC->_weapon = static_cast<Weapon>(--weapon);
			m_signalsManager->publish(Signals::GRAPHICS_LOAD_WEAPON, m_localEntt);

			bsOut.Write((SLNet::MessageID)Signals::GRAPHICS_LOAD_WEAPON);
			bsOut.Write(m_localEntt);
			bsOut.Write(playerC->_weapon);
			m_signalsManager->publish(Signals::NW_SEND_SERVER, m_localEntt, &bsOut);
		}*/
		break;
	default:
		break;
	}
}

void InputSystem::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (!m_registry->valid(m_localEntt))
		return;

	SLNet::BitStream bsOut;
	auto tbSpellsC = m_registry->try_get<TBSpellsComponent>(m_localEntt);
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_CTRL:
	case EventKeyboard::KeyCode::KEY_RIGHT_CTRL:
		m_signalsManager->publish(Signals::COMBAT_PUNCH, m_localEntt);
		break;
	case EventKeyboard::KeyCode::KEY_SPACE:
		m_director->pause();
		Graphics::destroyInstance();
		SpriteFrameCache::getInstance()->removeSpriteFrames();
		Graphics::getInstance();
		m_signalsManager->publish(Signals::GRAPHICS_RELOAD_INSTANCE, m_localEntt);
		m_director->resume();
		break;
	default:
		break;
	}		
}

void InputSystem::ReleaseKeyManually(cocos2d::EventKeyboard::KeyCode keyCode)
{
	m_keyStates[static_cast<int>(keyCode)] = false;
}
#endif // !Destop Platform
