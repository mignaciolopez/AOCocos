#include "UISystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

UISystem::UISystem()
{
	cocos2d::log("%s Constructor", "[UI SYSTEM]");

	m_componentManager = ECS::ECSEngine::GetInstance()->GetComponentManager();

	m_director = cocos2d::Director::getInstance();

	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MOUSE_PRESSED, &UISystem::clicked, this);
	m_eventManager->Subscribe(EVENTS::MOUSE_RELEASED, &UISystem::clicked, this);
	m_eventManager->Subscribe(EVENTS::UI_TOGGLE_FULLSCREEN, &UISystem::toogleFullscreen, this);
}

UISystem::~UISystem()
{
	cocos2d::log("%s Destructor", "[UI SYSTEM]");
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

void UISystem::toogleFullscreen(unsigned int eid, unsigned int cid, cocos2d::Event* ccevent)
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	cocos2d::GLViewImpl* view = static_cast<cocos2d::GLViewImpl*>(m_director->getOpenGLView());
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
