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
	InputSystem* inputSystem = new (std::nothrow) InputSystem(this);
	if (!inputSystem)
		cocos2d::log("%s InputSystem Failed!", LOGID);

	UISystem* uiSystem = new (std::nothrow) UISystem(this);
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

	CameraSystem* cameraSystem = new (std::nothrow) CameraSystem(this);
	if (!cameraSystem)
		cocos2d::log("%s CameraSystem Failed!", LOGID);

	AnimationSystem* animationSystem = new (std::nothrow) AnimationSystem;
	if (!animationSystem)
		cocos2d::log("%s AnimationSystem Failed!", LOGID);

	MapSystem* mapSystem = new (std::nothrow) MapSystem;
	if (!mapSystem)
		cocos2d::log("%s MapSystem Failed!", LOGID);

	// 3- Register Systems
	m_inputSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(inputSystem);
	m_uiSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(uiSystem);
	m_movementSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(movementSystem);
	m_networkSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(networkSystem);
	m_spawnSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(spawnSystem);
	m_cameraSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(cameraSystem);
	m_animationSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(animationSystem);
	m_mapSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(mapSystem);

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
