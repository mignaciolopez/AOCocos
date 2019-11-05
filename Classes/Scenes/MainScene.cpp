#include "MainScene.h"
#include "ECS/ECS_Engine.h"

#define LOGID "[MAIN SCENE]"

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
		cocos2d::log("%s Failed Init.", LOGID);
        return false;
    }

	this->scheduleUpdate();

	TP::Graphics::addSpriteFramesToCache();

	// 1- Init Engine
	m_ECS_Engine = ECS::ECS_Engine::getInstance();

	// 2- Create Systems
	RenderSystem* renderSystem = new (std::nothrow) RenderSystem;
	if (!renderSystem)
		cocos2d::log("%s RenderSystem Failed!", LOGID);

	InputSystem* inputSystem = new (std::nothrow) InputSystem(this);
	if (!inputSystem)
		cocos2d::log("%s InputSystem Failed!", LOGID);

	UISystem* uiSystem = new (std::nothrow) UISystem;
	if (!uiSystem)
		cocos2d::log("%s UISystem Failed!", LOGID);

	MovementSystem* movementSystem = new (std::nothrow) MovementSystem;
	if (!movementSystem)
		cocos2d::log("%s MovementSystem Failed!", LOGID);

	NetworkSystem* networkSystem = new (std::nothrow) NetworkSystem;
	if (!networkSystem)
		cocos2d::log("%s NetworkSystem Failed!", LOGID);

	SpawnSystem* spawnSystem = new (std::nothrow) SpawnSystem;
	if (!spawnSystem)
		cocos2d::log("%s SpawnSystem Failed!", LOGID);

	// 3- Register Systems
	m_renderSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(renderSystem);
	m_inputSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(inputSystem);
	m_uiSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(uiSystem);
	m_movementSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(movementSystem);
	m_networkSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(networkSystem);
	m_spawnSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(spawnSystem);

	cocos2d::log("%s Init Success.", LOGID);

	setOnExitCallback(CC_CALLBACK_0(MainScene::mainSceneOnExit, this));

    return true;
}

void MainScene::update(float dt)
{
	m_ECS_Engine->update();
	//unscheduleUpdate();
}

void MainScene::mainSceneOnExit()
{
	TP::Graphics::removeSpriteFramesFromCache();
}
