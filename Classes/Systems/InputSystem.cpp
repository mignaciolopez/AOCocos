#include "InputSystem.h"

#include "cocos2d.h"

USING_NS_CC;

InputSystem::InputSystem(cocos2d::Scene* scene)
{
	cocos2d::log("%s Constructor", "[INPUT SYSTEM]");

	m_scene = scene;

	m_director = cocos2d::Director::getInstance();

	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();
	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();

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


	m_mouseListener = cocos2d::EventListenerMouse::create();
	m_mouseListener->retain();
	m_scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_mouseListener, m_scene);
	
	m_mouseListener->onMouseDown = CC_CALLBACK_1(InputSystem::onMouseDown, this);
	m_mouseListener->onMouseMove = CC_CALLBACK_1(InputSystem::onMouseMove, this);
	m_mouseListener->onMouseScroll = CC_CALLBACK_1(InputSystem::onMouseScroll, this);
	m_mouseListener->onMouseUp = CC_CALLBACK_1(InputSystem::onMouseUp, this);

	m_eventManager->Subscribe(EVENTS::MY_EID, &InputSystem::setLocalEntity, this);

	m_localeid = -1;
}

InputSystem::~InputSystem()
{
	if (m_scene)
	{
		if (m_kbListener)
			m_kbListener->release();

		if (m_mouseListener)
			m_mouseListener->release();
	}
#if _DEBUG
	cocos2d::log("%s Destructor", "[INPUT SYSTEM]");
#endif
}

void InputSystem::Update()
{
	if (m_localeid == -1)
		return;
	
	if (m_keyStates[static_cast<int>(EventKeyboard::KeyCode::KEY_UP_ARROW)])
		m_eventManager->execute(EVENTS::MOVE_NORTH, m_localeid);
	else if (m_keyStates[static_cast<int>(EventKeyboard::KeyCode::KEY_RIGHT_ARROW)])
		m_eventManager->execute(EVENTS::MOVE_EAST, m_localeid);
	else if (m_keyStates[static_cast<int>(EventKeyboard::KeyCode::KEY_DOWN_ARROW)])
		m_eventManager->execute(EVENTS::MOVE_SOUTH, m_localeid);
	else if (m_keyStates[static_cast<int>(EventKeyboard::KeyCode::KEY_LEFT_ARROW)])
		m_eventManager->execute(EVENTS::MOVE_WEST, m_localeid);

	if (m_keyStates[static_cast<int>(EventKeyboard::KeyCode::KEY_PG_UP)])
		m_eventManager->execute(EVENTS::CAMERA_ZOOM_OUT, m_localeid);
	else if (m_keyStates[static_cast<int>(EventKeyboard::KeyCode::KEY_PG_DOWN)])
		m_eventManager->execute(EVENTS::CAMERA_ZOOM_IN, m_localeid);
}

void InputSystem::setLocalEntity(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	m_localeid = eid;
}

void InputSystem::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
		m_director->end();

	if (m_localeid == -1)
		return;

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_F1:
		m_eventManager->execute(EVENTS::MAP_TOGGLE_DEBUG, m_localeid);
		break;
	case EventKeyboard::KeyCode::KEY_F2:
		m_eventManager->execute(EVENTS::UI_TOGGLE_DEBUG, m_localeid);
		break;
	case EventKeyboard::KeyCode::KEY_F3:
		m_eventManager->execute(EVENTS::UI_TOGGLE_VSYNC, m_localeid);
		break;
	case EventKeyboard::KeyCode::KEY_F11:
		m_eventManager->execute(EVENTS::UI_TOGGLE_FULLSCREEN, m_localeid);
		break;
	case EventKeyboard::KeyCode::KEY_M:
		m_eventManager->execute(EVENTS::AUDIO_MUSIC_TOGGLE, m_localeid);
		break;
	default:
		break;
	}
}

void InputSystem::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (m_localeid == -1)
		return;

	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_CTRL:
		m_eventManager->execute(EVENTS::COMBAT_PUNCH, m_localeid);
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_CTRL:
		m_eventManager->execute(EVENTS::COMBAT_PUNCH, m_localeid);
		break;
	}		
}

void InputSystem::ReleaseKeyManually(cocos2d::EventKeyboard::KeyCode keyCode)
{
	m_keyStates[static_cast<int>(keyCode)] = false;
}

void InputSystem::onMouseDown(cocos2d::Event * ccevnt)
{
	m_eventManager->execute(EVENTS::MOUSE_PRESSED, m_localeid, ccevnt);
}

void InputSystem::onMouseMove(cocos2d::Event* ccevnt)
{
	m_eventManager->execute(EVENTS::MOUSE_MOVE, m_localeid, ccevnt);
}

void InputSystem::onMouseScroll(cocos2d::Event * ccevnt)
{
	m_eventManager->execute(EVENTS::MOUSE_SCROLL, m_localeid, ccevnt);
}

void InputSystem::onMouseUp(cocos2d::Event * ccevnt)
{
	m_eventManager->execute(EVENTS::MOUSE_RELEASED, m_localeid, ccevnt);
}
