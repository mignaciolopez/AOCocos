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

	m_eventManager->Subscribe(EVENTS::MY_EID, &SpawnSystem::createLocal, this);
	m_eventManager->Subscribe(EVENTS::EID_JOINED, &SpawnSystem::createRemote, this);
	m_eventManager->Subscribe(EVENTS::SYNC_PLAYERS, &SpawnSystem::syncPlayers, this);
	m_eventManager->Subscribe(EVENTS::EID_QUIT, &SpawnSystem::removePlayer, this);
}



SpawnSystem::~SpawnSystem()
{
#if _DEBUG
	cocos2d::log("%s Destructor", "[SPAWN SYSTEM]");
#endif
}

void SpawnSystem::update(float dt)
{
	//cocos2d::log("%s Update", LOGID);
}

void SpawnSystem::createLocal(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	createPlayer(eid, ccevent, bs);
	m_eventManager->execute(EVENTS::GRAPHICS_LOAD_PLAYER, eid);
	m_eventManager->execute(EVENTS::CAMERA_LAYER_ADD, eid, nullptr, nullptr);
	m_eventManager->execute(EVENTS::MAP_CREATE, eid, nullptr, nullptr);
	m_eventManager->execute(EVENTS::MAP_CHILD_ADD, eid, nullptr, nullptr);
	m_eventManager->execute(EVENTS::MOVES_V_CREATE, eid, nullptr, nullptr);
	m_eventManager->execute(EVENTS::AUDIO_C_CREATE, eid, nullptr, nullptr);
}

void SpawnSystem::createRemote(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	createPlayer(eid, ccevent, bs);
	m_eventManager->execute(EVENTS::GRAPHICS_LOAD_PLAYER, eid);
	m_eventManager->execute(EVENTS::MAP_CHILD_ADD, eid, nullptr, nullptr);
	m_eventManager->execute(EVENTS::MOVES_V_CREATE, eid, nullptr, nullptr);
	m_eventManager->execute(EVENTS::AUDIO_C_CREATE, eid, nullptr, nullptr);
}

void SpawnSystem::createPlayer(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	m_entityManager->CreateEntity(eid);

	int x = 0, y = 0;
	Direction dir;
	Genre genre;
	Race race;
	Body body;
	Head head;
	Shield shield;
	Helmet helmet;
	Weapon weapon;

	bs->Read(x);
	bs->Read(y);
	bs->Read(dir);
	bs->Read(genre);
	bs->Read(race);
	bs->Read(body);
	bs->Read(head);
	bs->Read(shield);
	bs->Read(helmet);
	bs->Read(weapon);

	PlayerBodyComponent* bodyC = new (std::nothrow) PlayerBodyComponent(
		x, y, dir, genre, race, body, head, shield, helmet, weapon);

	if (!bodyC || !bodyC->getBodySpr() || !bodyC->getHeadSpr())
		cocos2d::log("%s PlayerBodyComponent Failed!", "[SPAWN SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, bodyC);

	PositionComponent* pos = new (std::nothrow) PositionComponent(x, y);
	if (!pos)
		cocos2d::log("%s PositionComponent Failed!", "[SPAWN SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, pos);
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
		int rx, ry;
		Direction rdir;
		Genre rgenre;
		Race rrace;
		Body rbody;
		Head rhead;
		Shield rshield;
		Helmet rhelmet;
		Weapon rweapon;

		bs->Read(reid);
		bs->Read(rx);
		bs->Read(ry);
		bs->Read(rdir);
		bs->Read(rgenre);
		bs->Read(rrace);
		bs->Read(rbody);
		bs->Read(rhead);
		bs->Read(rshield);
		bs->Read(rhelmet);
		bs->Read(rweapon);
		syncCreatePlayer(reid, rx, ry, rdir, rgenre, rrace, rbody, rhead, rshield, rhelmet, rweapon);
		
		m_eventManager->execute(EVENTS::GRAPHICS_LOAD_PLAYER, reid);
		m_eventManager->execute(EVENTS::MAP_CHILD_ADD, reid, nullptr, nullptr);
		m_eventManager->execute(EVENTS::MOVES_V_CREATE, reid, nullptr, nullptr);
		m_eventManager->execute(EVENTS::AUDIO_C_CREATE, reid, nullptr, nullptr);
	}
}

void SpawnSystem::removePlayer(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs)
{
	m_eventManager->execute(EVENTS::MAP_CHILD_REMOVE, eid, nullptr, nullptr);
	m_eventManager->execute(EVENTS::MOVES_V_REMOVE, eid, nullptr, nullptr);
	m_eventManager->execute(EVENTS::AUDIO_C_REMOVE, eid, nullptr, nullptr);
	m_entityManager->removeEntity(eid);
}

void SpawnSystem::syncCreatePlayer(int eid, int x, int y, Direction dir, Genre genre, Race race, Body body, Head head, Shield shield, Helmet helmet, Weapon weapon)
{
	m_entityManager->CreateEntity(eid);

	PlayerBodyComponent* bodyC = new (std::nothrow) PlayerBodyComponent(
		x, y, dir, genre, race, body, head, shield, helmet, weapon);

	if (!bodyC || !bodyC->getBodySpr() || !bodyC->getHeadSpr())
		cocos2d::log("%s PlayerBodyComponent Failed!", "[SPAWN SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, bodyC);

	PositionComponent* pos = new (std::nothrow) PositionComponent(x, y);
	if (!pos)
		cocos2d::log("%s PositionComponent Failed!", "[SPAWN SYSTEM]");

	m_entityManager->AddComponentToEntity(eid, pos);
}