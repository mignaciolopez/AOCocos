#include "UISystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

#define LOGID "[UI SYSTEM]"

UISystem::UISystem()
{
	cocos2d::log("%s Constructor", LOGID);

	m_componentManager = ECS::ECSEngine::GetInstance()->GetComponentManager();

	m_director = cocos2d::Director::getInstance();

	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MOUSE_PRESSED, &UISystem::clicked, this);
	m_eventManager->Subscribe(EVENTS::MOUSE_RELEASED, &UISystem::clicked, this);
}

UISystem::~UISystem()
{
	cocos2d::log("%s Destructor", LOGID);
}

void UISystem::Update()
{
	//cocos2d::log("%s Update", LOGID);
}

void UISystem::clicked(unsigned int eid, unsigned int cid, cocos2d::Event * ccevnt)
{
	cocos2d::EventMouse* mouseEvent;
	try
	{
		mouseEvent = dynamic_cast<cocos2d::EventMouse*>(ccevnt);
	}
	catch (std::bad_cast& e)
	{
		// Not sure what kind of event you passed us cocos, but it was the wrong one
		return;
	}

	cocos2d::log("ComponentID: %i | Mouse Button: %i | X: %f, Y: %f",
		cid, mouseEvent->getMouseButton(), mouseEvent->getLocation().x, mouseEvent->getLocation().y);
}
