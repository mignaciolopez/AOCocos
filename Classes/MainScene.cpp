#include "MainScene.h"
#include "ECS/ECSEngine.h"

#include "Components/ComponentsList.h"

#include "Systems/RenderSystem.h"
#include "Components/BodyComponent.h"

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

	// 1- Init Engine
	m_ECSEngine = ECS::ECSEngine::GetInstance();

	// 2- Create Entity
	unsigned int entity = m_ECSEngine->GetEntityManager()->CreateEntity();

	// 3- Create Component
	BodyComponent* body = new (std::nothrow) BodyComponent;
	if (!body)
		cocos2d::log("%s body Failed!", LOGID);

	// 4- Add Component to Entity
	m_ECSEngine->GetEntityManager()->AddComponentTo(entity, body);

	// 5- Create System
	RenderSystem* renderSystem = new (std::nothrow) RenderSystem;
	if (!renderSystem)
		cocos2d::log("%s RenderSystem Failed!", LOGID);

	// 6- Register System
	m_ECSEngine->GetSystemManager()->RegisterSystem(renderSystem);
	

	cocos2d::log("%s Init Success.", LOGID);
    return true;
}

void MainScene::update(float dt)
{
	m_ECSEngine->Update();
}
