#include "UISystem.h"

USING_NS_CC;

UISystem::UISystem(cocos2d::Scene* scene) : m_scene(scene)
{
	cocos2d::log("%s Constructor", "[UI SYSTEM]");

	m_director = cocos2d::Director::getInstance();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();
	sfCache = SpriteFrameCache::getInstance();

	TP::Interface::addSpriteFramesToCache();

	auto s = m_director->getWinSize();

	auto camera = Camera::create();
	camera->retain();
	camera->setCameraFlag(CameraFlag::USER1);

	auto layer = Layer::create();
	layer->addChild(camera);
	layer->setCameraMask(static_cast<int>(CameraFlag::USER1));
	m_scene->addChild(layer, 1);


	Sprite* mainWindow = Sprite::createWithSpriteFrameName(TP::Interface::ventanaPrincipal);
	mainWindow->setAnchorPoint(Vec2(0.0f, 0.0f));
	mainWindow->setCameraMask(static_cast<int>(CameraFlag::USER1));
	layer->addChild(mainWindow);

	layer->setCameraMask(static_cast<int>(CameraFlag::USER1));

	cocos2d::log("[UI SYSTEM] mainWindowSprite camera mask: %i", mainWindow->getCameraMask());

	m_eventManager->Subscribe(EVENTS::MOUSE_PRESSED, &UISystem::clicked, this);
	m_eventManager->Subscribe(EVENTS::MOUSE_RELEASED, &UISystem::clicked, this);
	m_eventManager->Subscribe(EVENTS::UI_TOGGLE_FULLSCREEN, &UISystem::toogleFullscreen, this);

	m_eventManager->Subscribe(EVENTS::MOUSE_SCROLL, &UISystem::scroll, this);
	//m_eventManager->Subscribe(EVENTS::MOUSE_MOVE, &UISystem::clicked, this);
}

UISystem::~UISystem()
{
	TP::Interface::removeSpriteFramesFromCache();

	cocos2d::log("%s Destructor", "[UI SYSTEM]");
}

void UISystem::Update()
{
	//cocos2d::log("%s Update", LOGID);
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
