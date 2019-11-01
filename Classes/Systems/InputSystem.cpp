#include "InputSystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

InputSystem::InputSystem(cocos2d::Scene* scene)
{
	cocos2d::log("%s Constructor", "[INPUT SYSTEM]");

	m_scene = scene;

	m_componentManager = ECS::ECSEngine::GetInstance()->GetComponentManager();

	m_director = cocos2d::Director::getInstance();

	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager();

	for (int i = 0; i < 256; i++)
		m_keyStates[i] = false;

	m_kbListener = cocos2d::EventListenerKeyboard::create();
	m_kbListener->retain();

	m_director->getOpenGLView()->setIMEKeyboardState(true);
	m_kbListener->onKeyPressed = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* ccevnt)
	{
		m_keyStates[static_cast<int>(keyCode)] = true;
	};
	m_kbListener->onKeyReleased = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* ccevnt)
	{
		m_keyStates[static_cast<int>(keyCode)] = false;
	};

	m_scene->getEventDispatcher()->addEventListenerWithFixedPriority(m_kbListener, 1);


	m_mouseListener = cocos2d::EventListenerMouse::create();
	m_mouseListener->retain();
	m_scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_mouseListener, m_scene);
	
	m_mouseListener->onMouseDown = CC_CALLBACK_1(InputSystem::onMouseDown, this);
	m_mouseListener->onMouseMove = CC_CALLBACK_1(InputSystem::onMouseMove, this);
	m_mouseListener->onMouseScroll = CC_CALLBACK_1(InputSystem::onMouseScroll, this);
	m_mouseListener->onMouseUp = CC_CALLBACK_1(InputSystem::onMouseUp, this);


	m_localEntity = 0;
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

	cocos2d::log("%s Destructor", "[INPUT SYSTEM]");
}

void InputSystem::Update()
{
	//cocos2d::log("%s Update", LOGID);

	if (IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW))
		m_eventManager->execute(EVENTS::MOVE_NORTH, 0, m_localEntity);
	else if (IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
		m_eventManager->execute(EVENTS::MOVE_EAST, 0, m_localEntity);
	else if (IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_DOWN_ARROW))
		m_eventManager->execute(EVENTS::MOVE_SOUTH, 0, m_localEntity);
	else if (IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_LEFT_ARROW))
		m_eventManager->execute(EVENTS::MOVE_WEST, 0, m_localEntity);
	
	if (IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_TAB))
	{
		ReleaseKeyManually(cocos2d::EventKeyboard::KeyCode::KEY_TAB);
		if (m_localEntity)
			m_localEntity = 0;
		else
			m_localEntity = 1;
	}
	else if (IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE))
	{
		ReleaseKeyManually(cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE);
		m_director->end();
	}
	else if (IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_F11))
	{
		ReleaseKeyManually(cocos2d::EventKeyboard::KeyCode::KEY_F11);
		m_eventManager->execute(EVENTS::UI_TOGGLE_FULLSCREEN, 0, m_localEntity);
	}
}

bool InputSystem::IsKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (m_keyStates[static_cast<int>(keyCode)])
		return true;

	return false;
}

void InputSystem::ReleaseKeyManually(cocos2d::EventKeyboard::KeyCode keyCode)
{
	m_keyStates[static_cast<int>(keyCode)] = false;
}

void InputSystem::onMouseDown(cocos2d::Event * ccevnt)
{
	try
	{
		cocos2d::EventMouse* mouseEvent = dynamic_cast<cocos2d::EventMouse*>(ccevnt);
		m_eventManager->execute(EVENTS::MOUSE_PRESSED, 0, m_localEntity, ccevnt);
	}
	catch (std::bad_cast& e)
	{
		// Not sure what kind of event you passed us cocos, but it was the wrong one
		return;
	}
}

void InputSystem::onMouseMove(cocos2d::Event* ccevnt)
{
	m_eventManager->execute(EVENTS::MOUSE_MOVE, 0, m_localEntity, ccevnt);
}

void InputSystem::onMouseScroll(cocos2d::Event * ccevnt)
{
	m_eventManager->execute(EVENTS::MOUSE_SCROLL, 0, m_localEntity, ccevnt);
}

void InputSystem::onMouseUp(cocos2d::Event * ccevnt)
{
	try
	{
		cocos2d::EventMouse* mouseEvent = dynamic_cast<cocos2d::EventMouse*>(ccevnt);
		m_eventManager->execute(EVENTS::MOUSE_RELEASED, 0, m_localEntity, ccevnt);
	}
	catch (std::bad_cast& e)
	{
		// Not sure what kind of event you passed us cocos, but it was the wrong one
		return;
	}
}
