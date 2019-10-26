#include "MainScene.h"
#include "ECS/ECSEngine.h"

#include "Systems/RenderSystem.h"

#define LOGID "[MAIN SCENE]"

USING_NS_CC;

static ECS::ECSEngine* s_ECSEngine;

Scene* MainScene::createScene(ECS::ECSEngine* ecsEngine)
{
	s_ECSEngine = ecsEngine;
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

	RenderSystem* renderSystem = new (std::nothrow) RenderSystem;
	if (!renderSystem)
		cocos2d::log("%s RenderSystem Failed!", LOGID);
	s_ECSEngine->m_systemManager->RegisterSystem(renderSystem);
	

	cocos2d::log("%s Init Success.", LOGID);
    return true;
}

void MainScene::update(float dt)
{
	s_ECSEngine->Update();
}
