#include "EntitiesSystem.h"

#include "Components/SpriteComponent.h"

#include "cocos2d.h"

EntitiesSystem::EntitiesSystem()
{
	cocos2d::log("%s Constructor", "[ENTITIES SYSTEM]");

	m_director = cocos2d::Director::getInstance();

	m_entityManager = ECS::ECSEngine::GetInstance()->GetEntityManager();
	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MY_EID, &EntitiesSystem::createEntity, this);
	m_eventManager->Subscribe(EVENTS::EID_JOINED, &EntitiesSystem::createEntity, this);
}

EntitiesSystem::~EntitiesSystem()
{
	cocos2d::log("%s Destructor", "[ENTITIES SYSTEM]");
}

void EntitiesSystem::Update()
{
	//cocos2d::log("%s Update", LOGID);
}

void EntitiesSystem::createEntity(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	m_entityManager->CreateEntity(eid);

	SpriteComponent* body = new (std::nothrow) SpriteComponent("HelloWorld.png");
	if (!body || !body->_sprite)
	{
		cocos2d::log("%s body Failed!", "[ENTITIES SYSTEM]");
		m_entityManager->AddComponentToEntity(eid, body); //storing te comp even if it failed prevents quit with memory leak
		return;
	}

	m_entityManager->AddComponentToEntity(eid, body);
}
