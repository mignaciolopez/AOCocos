#include "InputSystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

#define LOGID "[INPUT SYSTEM]"

InputSystem::InputSystem(cocos2d::Scene* scene)
{
	cocos2d::log("%s Constructor", LOGID);

	m_componentManager = ECS::ECSEngine::GetInstance()->GetComponentManager();

	m_director = cocos2d::Director::getInstance();

	//m_compatibleComponents.push_back(ComponentType::SPRITE);

	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager();

	m_kbListener = cocos2d::EventListenerKeyboard::create();

	m_director->getOpenGLView()->setIMEKeyboardState(true);
	m_kbListener->onKeyPressed = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		if (m_keys.find(keyCode) == m_keys.end())
			m_keys.insert(std::make_pair(keyCode, true));
	};
	m_kbListener->onKeyReleased = [=](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
	{
		if (m_keys.find(keyCode) != m_keys.end())
			m_keys.erase(keyCode);
	};

	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(m_kbListener, scene);
}

InputSystem::~InputSystem()
{
	cocos2d::log("%s Destructor", LOGID);
}

void InputSystem::Update()
{
	//cocos2d::log("%s Update", LOGID);

	if (IsKeyPressed(cocos2d::EventKeyboard::KeyCode::KEY_UP_ARROW))
	{
		m_eventManager->execute(EVENTS::MOVE_NORTH, 0, 0);
		
	}

}

bool InputSystem::IsKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (m_keys.find(keyCode) != m_keys.end())
		return true;

	return false;
}

void InputSystem::ReleaseKeyManually(cocos2d::EventKeyboard::KeyCode keyCode)
{
	if (m_keys.find(keyCode) != m_keys.end())
		m_keys.erase(keyCode);
}
