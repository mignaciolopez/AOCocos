#include "MainScene.h"
#include "ECS/ECSEngine.h"

#include "Components/ComponentsList.h"

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

	// 2- Create Entities
	unsigned int entity = m_ECSEngine->GetEntityManager()->CreateEntity();

	// 3- Create Components
	BodyComponent* body = new (std::nothrow) BodyComponent;
	if (!body)
		cocos2d::log("%s body Failed!", LOGID);

	HeadComponent* head = new (std::nothrow) HeadComponent;

	// 4- Store Components
	m_bodyComponentID = m_ECSEngine->GetComponentManager()->storeComponent(body);
	m_headComponentID = m_ECSEngine->GetComponentManager()->storeComponent(head);

	// 5- Add Components to Entities
	m_ECSEngine->GetEntityManager()->AddComponentToEntity(entity, m_bodyComponentID);
	m_ECSEngine->GetEntityManager()->AddComponentToEntity(entity, m_headComponentID);

	// 6- Create Systems
	RenderSystem* renderSystem = new (std::nothrow) RenderSystem;
	if (!renderSystem)
		cocos2d::log("%s RenderSystem Failed!", LOGID);

	// 7- Register Systems
	m_renderSystemID = m_ECSEngine->GetSystemManager()->RegisterSystem(renderSystem);
	

	cocos2d::log("%s Init Success.", LOGID);
    return true;
}

void MainScene::update(float dt)
{
	m_ECSEngine->Update();
	//unscheduleUpdate();
}
