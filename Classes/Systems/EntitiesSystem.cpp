#include "EntitiesSystem.h"

#include "Components/SpriteComponent.h"
#include "Components/PositionComponent.h"

#include "cocos2d.h"

EntitiesSystem::EntitiesSystem()
{
	cocos2d::log("%s Constructor", "[ENTITIES SYSTEM]");

	m_director = cocos2d::Director::getInstance();

	m_entityManager = ECS::ECSEngine::GetInstance()->GetEntityManager();
	m_eventManager = ECS::ECSEngine::GetInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MY_EID, &EntitiesSystem::createEntity, this);
	m_eventManager->Subscribe(EVENTS::EID_JOINED, &EntitiesSystem::createEntity, this);
	m_eventManager->Subscribe(EVENTS::SYNC, &EntitiesSystem::sync, this);
	m_eventManager->Subscribe(EVENTS::EID_QUIT, &EntitiesSystem::removeEntity, this);
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

	float x = 0.0f, y = 0.0f;
	bs->Read(x);
	bs->Read(y);

	SpriteComponent* body = new (std::nothrow) SpriteComponent("HelloWorld.png", x , y);
	if (!body || !body->_sprite)
		cocos2d::log("%s body Failed!", "[ENTITIES SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, body);

	PositionComponent* pos = new (std::nothrow) PositionComponent(x, y);
	if (!pos)
		cocos2d::log("%s position Failed!", "[ENTITIES SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, pos);
}

void EntitiesSystem::sync(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	unsigned int count = 0;
	bs->Read(count);
	for (unsigned int i = 0; i < count; i++)
	{
		int reid = -1;
		float rx, ry;
		bs->Read(reid);
		bs->Read(rx);
		bs->Read(ry);
		createEntity(reid, rx, ry);
	}
}

void EntitiesSystem::removeEntity(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	m_entityManager->removeEntity(eid);
}

void EntitiesSystem::createEntity(int eid, float x, float y)
{
	m_entityManager->CreateEntity(eid);

	SpriteComponent* body = new (std::nothrow) SpriteComponent("HelloWorld.png", x, y);
	if (!body || !body->_sprite)
		cocos2d::log("%s body Failed!", "[ENTITIES SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, body);

	PositionComponent* pos = new (std::nothrow) PositionComponent(x, y);
	if (!pos)
		cocos2d::log("%s position Failed!", "[ENTITIES SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, pos);
}