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
	SpriteComponent* body = new (std::nothrow) SpriteComponent("HelloWorld.png");
	if (!body || !body->_sprite)
	{
		cocos2d::log("%s body Failed!", LOGID);
		m_ECSEngine->GetEntityManager()->AddComponentToEntity(entity, body);
		return false;
	}
	SpriteComponent* head = new (std::nothrow) SpriteComponent("HelloWorld.png");
	if (!head || !head->_sprite)
	{
		cocos2d::log("%s head Failed!", LOGID);
		m_ECSEngine->GetEntityManager()->AddComponentToEntity(entity, head);
		return false;
	}

	// 4- Add Components to Entities (This store the component with component Manager
	m_bodyComponentID = m_ECSEngine->GetEntityManager()->AddComponentToEntity(entity, body);
	m_headComponentID = m_ECSEngine->GetEntityManager()->AddComponentToEntity(entity, head);

	// 5- Create Systems
	RenderSystem* renderSystem = new (std::nothrow) RenderSystem;
	if (!renderSystem)
		cocos2d::log("%s RenderSystem Failed!", LOGID);

	InputSystem* inputSystem = new (std::nothrow) InputSystem(this);
	if (!inputSystem)
		cocos2d::log("%s InputSystem Failed!", LOGID);

	// 6- Register Systems
	m_renderSystemID = m_ECSEngine->GetSystemManager()->RegisterSystem(renderSystem);
	m_inputSystemID = m_ECSEngine->GetSystemManager()->RegisterSystem(inputSystem);

	cocos2d::log("%s Init Success.", LOGID);
    return true;
}

void MainScene::update(float dt)
{
	m_ECSEngine->Update();
	//unscheduleUpdate();
}
