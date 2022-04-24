#include "SpawnSystem.h"

SpawnSystem::SpawnSystem(cocos2d::Scene* scene, entt::registry* registry)
	: m_scene(scene), m_registry(registry)
{
#if _DEBUG
	cocos2d::log("[SpawnSystem] Constructor");
#endif

	m_signalsManager = ECS::SignalsManager::getInstance();

	m_signalsManager->connect<&SpawnSystem::setLocalEntity>(Signals::NW_MY_ENTT, this);
	m_signalsManager->connect<&SpawnSystem::entityJoined>(Signals::NW_ENTT_JOINED, this);
	m_signalsManager->connect<&SpawnSystem::syncPlayers>(Signals::NW_SYNC_PLAYERS, this);
	m_signalsManager->connect<&SpawnSystem::removePlayer>(Signals::NW_ENTT_QUIT, this);

	m_localEntt = entt::null;

	
}

SpawnSystem::~SpawnSystem()
{
#if _DEBUG
	cocos2d::log("[SpawnSystem] Destructor");
#endif
	
	ECS::SignalsManager::getInstance()->disconnectAll(this);
}

void SpawnSystem::update(float dt)
{
	
}

void SpawnSystem::setLocalEntity(entt::entity entity, SLNet::BitStream* bs)
{
	entt::entity player = entt::null;
	player = m_registry->create(entity);

	if (player != entity)
	{
		for (int i = 0; player != entity; i++)
		{
#if _DEBUG
			cocos2d::log("[SpawnSystem] setLocalEntity() entity <=> player missmatch with server");
#endif
			m_registry->destroy(player);
			m_registry->destroy(entity);
			player = m_registry->create(entity);
			if (i > 10)
			{
				cocos2d::MessageBox("setLocalEntity() entity <=> player missmatch with server", "[SpawnSystem]");
				exit(-1);
			}
		}
	}

	m_localEntt = player;

	createLocal(m_localEntt, bs);
}

void SpawnSystem::entityJoined(entt::entity entity,  SLNet::BitStream* bs)
{
	entt::entity player = entt::null;
	player = m_registry->create(entity);
	if (player != entity)
	{
		for (int i = 0; player != entity; i++)
		{
#if _DEBUG
			cocos2d::log("[SpawnSystem] entityJoined() entity <=> player missmatch with server");
#endif
			m_registry->destroy(player);
			m_registry->destroy(entity);
			player = m_registry->create(entity);
			if (i > 10)
			{
				cocos2d::MessageBox("entityJoined() entity <=> player missmatch with server", "[SpawnSystem]");
				exit(-1);
			}
		}
	}
	createRemote(player, bs);
}

void SpawnSystem::createLocal(entt::entity entity, SLNet::BitStream* bs)
{
	if (!bs)
	{
#if _DEBUG
		cocos2d::log("[SpawnSystem] createLocal() bs is nullptr.");
#endif
		return;
	}

	int mapID = 0, x = 0, y = 0;
	Directions dir;
	Genres genre;
	Races race;
	Bodies body;
	Heads head;
	Shields shield;
	Helmets helmet;
	Weapons weapon;
	int hp = 0;
	int hpMax = 0;
	int mp = 0;
	int mpMax = 0;

	bs->Read(mapID);
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
	bs->Read(hp);
	bs->Read(hpMax);
	bs->Read(mp);
	bs->Read(mpMax);


	m_registry->assign<MapComponent>(entity, mapID);

	m_registry->assign<HudComponent>(entity, m_scene);
	auto hudC = m_registry->try_get<HudComponent>(entity);
	m_registry->assign<TBSpellsComponent>(entity, hudC->_hudNode);
	m_registry->assign<MapCameraComponent>(entity, m_scene);


	m_registry->assign<PositionComponent>(entity, mapID, x, y);

	m_registry->assign<PlayerComponent>(entity, x, y,
		dir, genre, race, body, head,
		shield, helmet, weapon);

	m_registry->assign<InventoryComponent>(entity);

	m_registry->assign<FXComponent>(entity, true);

	m_registry->replace<FXComponent>(entity, [](auto &fxC) { fxC._FXs.push_back(FXS::Spawn); });

	m_registry->assign<HealthComponent>(entity, hp, hpMax);
	m_registry->assign<ManaComponent>(entity, mp, mpMax);

	m_registry->assign<IntervalComponent>(entity);

	SLNet::BitStream bsOut;
	bsOut.Write(Animations::Anim_Spawn);
	m_signalsManager->publish(Signals::ANIMATE_SPELL, entity, &bsOut);
}

void SpawnSystem::createRemote(entt::entity entity, SLNet::BitStream* bs)
{
	if (!bs)
	{
#if _DEBUG
		cocos2d::log("[SpawnSystem] createRemote() bs is nullptr.");
#endif
		return;
	}

	int mapID = 0, x = 0, y = 0;
	Directions dir;
	Genres genre;
	Races race;
	Bodies body;
	Heads head;
	Shields shield;
	Helmets helmet;
	Weapons weapon;

	bs->Read(mapID);
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

	m_registry->assign<PositionComponent>(entity, mapID, x, y);

	m_registry->assign<PlayerComponent>(entity, x, y,
		dir, genre, race, body, head,
		shield, helmet, weapon);

	m_registry->assign<FXComponent>(entity, true);

	m_registry->replace<FXComponent>(entity, [](auto &fxC) { fxC._FXs.push_back(FXS::Spawn); });

	SLNet::BitStream bsOut;
	bsOut.Write(Animations::Anim_Spawn);
	m_signalsManager->publish(Signals::ANIMATE_SPELL, entity, &bsOut);
}

void SpawnSystem::syncPlayers(entt::entity entity, SLNet::BitStream* bs)
{
	if (!bs)
	{
#if _DEBUG
		cocos2d::log("[SpawnSystem] syncPlayers() bs is nullptr.");
#endif
		return;
	}
	//to review there is no always need to add ass child of same map

	bs->ResetReadPointer();
	bs->IgnoreBytes(sizeof(SLNet::MessageID));
	bs->IgnoreBytes(sizeof(entt::entity));
	unsigned int count = 0;
	bs->Read(count);
	for (unsigned int i = 0; i < count; i++)
	{
		entt::entity remoteEntity = entt::null;
		int mapID = 0, x = 0, y = 0;
		Directions dir;
		Genres genre;
		Races race;
		Bodies body;
		Heads head;
		Shields shield;
		Helmets helmet;
		Weapons weapon;
		bool meditating;

		bs->Read(remoteEntity);
		bs->Read(mapID);
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
		bs->Read(meditating);
		
		entt::entity player = entt::null;
		player = m_registry->create(remoteEntity);
		if (player != remoteEntity)
		{
			for (int i = 0; player != remoteEntity; i++)
			{
#if _DEBUG
				cocos2d::log("[SpawnSystem] syncPlayers() remoteEntity <=> player missmatch with server");
#endif
				m_registry->destroy(player);
				m_registry->destroy(remoteEntity);
				player = m_registry->create(remoteEntity);
				if (i > 10)
				{
					cocos2d::MessageBox("syncPlayers() remoteEntity <=> player missmatch with server", "[SpawnSystem]");
					exit(-1);
				}
			}
		}
		//order matters
		m_registry->assign<PositionComponent>(player, mapID, x, y);

		m_registry->assign<PlayerComponent>(player, x, y,
			dir, genre, race, body, head,
			shield, helmet, weapon);

		m_registry->assign<FXComponent>(player, true);

		if (meditating)
			m_signalsManager->publish(Signals::MEDITATE_START, remoteEntity);
	}
}

void SpawnSystem::removePlayer(entt::entity entity, SLNet::BitStream* bs)
{
	m_registry->remove_if_exists<PlayerComponent>(entity);
	m_registry->remove_if_exists<PositionComponent>(entity);
	m_registry->remove_if_exists<FXComponent>(entity);
	m_registry->destroy(entity);
}
