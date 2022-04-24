#include "MainScene.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
    return MainScene::create();
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        cocos2d::log("[MainScene] problem loading 'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + visibleSize.height - closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

	setOnExitCallback(CC_CALLBACK_0(MainScene::mainSceneOnExit, this));

	this->scheduleUpdate();

	m_ECS_Engine = ECS::ECS_Engine::getInstance();
	m_signalsManager = ECS::SignalsManager::getInstance();
	m_registry = m_ECS_Engine->getRegistry();

	TP::Interface::addSpriteFramesToCache();
	
	//ECS Systems
	m_systemManager = m_ECS_Engine->getSystemManager();

	InputSystem* inputSystem = new (std::nothrow) InputSystem(this, m_registry);
	m_systemManager->RegisterSystem(inputSystem);

	UISystem* uiSystem = new (std::nothrow) UISystem(this, m_registry);
	m_systemManager->RegisterSystem(uiSystem);

	MapSystem* mapSystem = new (std::nothrow) MapSystem(this, m_registry);
	m_systemManager->RegisterSystem(mapSystem);

	SpawnSystem* spawnSystem = new (std::nothrow) SpawnSystem(this, m_registry);
	m_systemManager->RegisterSystem(spawnSystem);

	InventorySystem* inventorySystem = new (std::nothrow) InventorySystem(this, m_registry);
	m_systemManager->RegisterSystem(inventorySystem);

	HealthSystem* healthSystem = new (std::nothrow) HealthSystem(this, m_registry);
	m_systemManager->RegisterSystem(healthSystem);

	ParticlesSystem* particlesSystem = new (std::nothrow) ParticlesSystem(this, m_registry);
	m_systemManager->RegisterSystem(particlesSystem);

	ManaSystem* manaSystem = new (std::nothrow) ManaSystem(this, m_registry);
	m_systemManager->RegisterSystem(manaSystem);

	IntervalSystem* intervalSystem = new (std::nothrow) IntervalSystem(this, m_registry);
	m_systemManager->RegisterSystem(intervalSystem);

	setUserData(m_ECS_Engine);

	//this is like hitting enter in the lobby scene after provided username and password
    m_signalsManager->publish(Signals::NW_CONNECT, entt::null);

    return true;
}


void MainScene::menuCloseCallback(Ref* pSender)
{
	setUserData(nullptr);
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void MainScene::update(float dt)
{
#ifdef _DEBUG
	//cocos2d::log("[MainScene] Call to update. dt: %f", dt);
#endif
}

void MainScene::mainSceneOnExit()
{
#ifdef _DEBUG
	cocos2d::log("[MainScene] Call to mainSceneOnExit");
#endif
	setUserData(nullptr);

	m_signalsManager->publish(Signals::NW_DISCONNECT, entt::null);

	TP::Interface::removeSpriteFramesFromCache();

	m_systemManager->unRegisterSystem(ECS::iSystemTags::InputSystem_tag);
	m_systemManager->unRegisterSystem(ECS::iSystemTags::UISystem_tag);
	m_systemManager->unRegisterSystem(ECS::iSystemTags::MapSystem_tag);
	m_systemManager->unRegisterSystem(ECS::iSystemTags::SpawnSystem_tag);
	m_systemManager->unRegisterSystem(ECS::iSystemTags::InventorySystem_tag);
	m_systemManager->unRegisterSystem(ECS::iSystemTags::HealthSystem_tag);
	m_systemManager->unRegisterSystem(ECS::iSystemTags::ParticlesSystem_tag);
	m_systemManager->unRegisterSystem(ECS::iSystemTags::ManaSystem_tag);
}
