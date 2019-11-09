#include "MainScene.h"
#include "ECS/ECS_Engine.h"
#include "DrawNode3D.h"

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

	auto s = Director::getInstance()->getWinSize();
	auto layer3D = Layer::create();
	addChild(layer3D, 0);
	layer3D->setTag(123);
	//auto _camera = Camera::createPerspective(60, (GLfloat)s.width / s.height, 1, 1000);
	auto _camera = Camera::createOrthographic(s.width, s.height, 1, 1000);
	_camera->setCameraFlag(CameraFlag::USER1);
	//removeChild(getDefaultCamera());
	layer3D->addChild(_camera);
	layer3D->setCameraMask(2);

	cocos2d::DrawNode3D* line = cocos2d::DrawNode3D::create();
	//draw x
	for (int j = -20; j <= 20; j++)
	{
		line->drawLine(Vec3(-100, 0, 5 * j), Vec3(100, 0, 5 * j), Color4F(1, 0, 0, 1));
	}
	//draw z
	for (int j = -20; j <= 20; j++)
	{
		line->drawLine(Vec3(5 * j, 0, -100), Vec3(5 * j, 0, 100), Color4F(0, 0, 1, 1));
	}
	//draw y
	line->drawLine(Vec3(0, -50, 0), Vec3(0, 0, 0), Color4F(0, 0.5, 0, 1));
	line->drawLine(Vec3(0, 0, 0), Vec3(0, 50, 0), Color4F(0, 1, 0, 1));
	layer3D->addChild(line);

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

	AnimationSystem* animationSystem = new (std::nothrow) AnimationSystem;
	if (!animationSystem)
		cocos2d::log("%s AnimationSystem Failed!", LOGID);

	MapSystem* mapSystem = new (std::nothrow) MapSystem;
	if (!mapSystem)
		cocos2d::log("%s MapSystem Failed!", LOGID);

	// 3- Register Systems
	m_renderSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(renderSystem);
	m_inputSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(inputSystem);
	m_uiSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(uiSystem);
	m_movementSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(movementSystem);
	m_networkSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(networkSystem);
	m_spawnSystemID = m_ECS_Engine->getSystemManager()->RegisterSystem(spawnSystem);
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
