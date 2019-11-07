#include "SpawnSystem.h"

#include "Components/IncludeComponents.h"

#include "Graphics/Graphics.h"
#include "Graphics/Interface.h"

#include "cocos2d.h"

SpawnSystem::SpawnSystem()
{
	cocos2d::log("%s Constructor", "[SPAWN SYSTEM]");

	m_director = cocos2d::Director::getInstance();

	m_entityManager = ECS::ECS_Engine::getInstance()->getEntityManager();
	m_eventManager = ECS::ECS_Engine::getInstance()->getEventManager();

	m_eventManager->Subscribe(EVENTS::MY_EID, &SpawnSystem::createPlayer, this);
	m_eventManager->Subscribe(EVENTS::EID_JOINED, &SpawnSystem::createPlayer, this);
	m_eventManager->Subscribe(EVENTS::SYNC_PLAYERS, &SpawnSystem::syncPlayers, this);
	m_eventManager->Subscribe(EVENTS::EID_QUIT, &SpawnSystem::removePlayer, this);
}

SpawnSystem::~SpawnSystem()
{
	cocos2d::log("%s Destructor", "[SPAWN SYSTEM]");
}

void SpawnSystem::Update()
{
	//cocos2d::log("%s Update", LOGID);
}

void SpawnSystem::createPlayer(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	m_entityManager->CreateEntity(eid);

	float x = 0.0f, y = 0.0f;
	bs->Read(x);
	bs->Read(y);

	PlayerBodyComponent* body = new (std::nothrow) PlayerBodyComponent(
		TP::Graphics::playerBodyHumanFemaleStandingSouth,
		TP::Graphics::headsPlayerHeadPirateSouth,
		x, y,
		Direction::South,
		Genre::Female,
		Race::Human,
		Head::Pirate);

	if (!body || !body->getBodySpr() || !body->getHeadSpr())
		cocos2d::log("%s PlayerBodyComponent Failed!", "[SPAWN SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, body);

	PositionComponent* pos = new (std::nothrow) PositionComponent(x, y);
	if (!pos)
		cocos2d::log("%s PositionComponent Failed!", "[SPAWN SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, pos);

	body->getBodySpr()->setGlobalZOrder(pos->getY() * -1 + 600);
	body->getHeadSpr()->setGlobalZOrder(pos->getY() * -1 + 600);

	m_eventManager->execute(EVENTS::LOAD_ANIMATION_INFO, eid, nullptr, nullptr);
}

void SpawnSystem::syncPlayers(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	bs->ResetReadPointer();
	bs->IgnoreBytes(sizeof(SLNet::MessageID));
	bs->IgnoreBytes(sizeof(int));
	unsigned int count = 0;
	bs->Read(count);
	for (unsigned int i = 0; i < count; i++)
	{
		int reid = -1;
		float rx, ry;
		bs->Read(reid);
		bs->Read(rx);
		bs->Read(ry);
		syncCreatePlayer(reid, rx, ry);
	}
}

void SpawnSystem::removePlayer(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	m_entityManager->removeEntity(eid);
}

void SpawnSystem::syncCreatePlayer(int eid, float x, float y)
{
	m_entityManager->CreateEntity(eid);

	PlayerBodyComponent* body = new (std::nothrow) PlayerBodyComponent(
		TP::Graphics::playerBodyHumanFemaleStandingSouth,
		TP::Graphics::headsPlayerHeadPirateSouth,
		x, y,
		Direction::South,
		Genre::Female,
		Race::Human,
		Head::Pirate);

	if (!body || !body->getBodySpr() || !body->getHeadSpr())
		cocos2d::log("%s PlayerBodyComponent Failed!", "[SPAWN SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, body);

	PositionComponent* pos = new (std::nothrow) PositionComponent(x, y);
	if (!pos)
		cocos2d::log("%s PositionComponent Failed!", "[SPAWN SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, pos);

	body->getBodySpr()->setGlobalZOrder(pos->getY() * -1 + 600);
	body->getHeadSpr()->setGlobalZOrder(pos->getY() * -1 + 600);

	m_eventManager->execute(EVENTS::LOAD_ANIMATION_INFO, eid, nullptr, nullptr);
}