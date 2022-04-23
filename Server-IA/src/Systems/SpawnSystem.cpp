#include "SpawnSystem.h"

SpawnSystem::SpawnSystem(entt::registry* registry)
	: m_registry(registry), m_signalsManager(nullptr)
{
	ECS_Log::s_consoleL->trace("[SpawnSystem] Constructor");

	m_signalsManager = ECS::SignalsManager::getSignalsManager();

	m_signalsManager->connect<&SpawnSystem::requestEntt>(Signals::NW_REQUEST_ENTT, this);
	m_signalsManager->connect<&SpawnSystem::syncPlayers>(Signals::NW_SERVER_SYNC_PLAYERS, this);
	m_signalsManager->connect<&SpawnSystem::enttQuit>(Signals::NW_ENTT_QUIT, this);
}

SpawnSystem::~SpawnSystem()
{
	ECS_Log::s_consoleL->trace("[SpawnSystem] Destructor");

	m_signalsManager->disconnectAll(this);
}

void SpawnSystem::update(double dt)
{
	
}

void SpawnSystem::requestEntt(entt::entity entity, SLNet::BitStream * bs)
{
	//this should be read form storage or DB
	auto& playerC = m_registry->assign<PlayerComponent>(entity, Directions::South, Genres::Male,
		Races::Human, Bodies::Body_Human_Male, Heads::Head_Human_Male_Brown,
		Shields::NoShield, Helmets::NoHelmet, Weapons::NoWeapon);

	auto& posC = m_registry->assign<PositionComponent>(entity, 1, 3, 3);

	auto& healthC = m_registry->assign<HealthComponent>(entity, 450, 450);

	auto& manaC = m_registry->assign<ManaComponent>(entity, 1850, 1850);

	auto& inventoryC = m_registry->assign<InventoryComponent>(entity);
	
	auto& intervalC = m_registry->assign<IntervalComponent>(entity);

	//notify client
	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::NW_MY_ENTT);
	bsOut.Write(entity);
	bsOut.Write(posC._mapID);
	bsOut.Write(posC._x);
	bsOut.Write(posC._y);
	bsOut.Write(playerC._direction);
	bsOut.Write(playerC._genre);
	bsOut.Write(playerC._race);
	bsOut.Write(playerC._body);
	bsOut.Write(playerC._head);
	bsOut.Write(playerC._shield);
	bsOut.Write(playerC._helmet);
	bsOut.Write(playerC._weapon);
	bsOut.Write(healthC._hp);
	bsOut.Write(healthC._hpMax);
	bsOut.Write(manaC._mp);
	bsOut.Write(manaC._mpMax);
	m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);

	m_signalsManager->publish(Signals::INVENTORY_SYNC, entity);

	syncPlayers(entity, nullptr);

	bsOut.Reset();

	//Notify All
	bsOut.Write((SLNet::MessageID)Signals::NW_ENTT_JOINED);
	bsOut.Write(entity);
	bsOut.Write(posC._mapID);
	bsOut.Write(posC._x);
	bsOut.Write(posC._y);
	bsOut.Write(playerC._direction);
	bsOut.Write(playerC._genre);
	bsOut.Write(playerC._race);
	bsOut.Write(playerC._body);
	bsOut.Write(playerC._head);
	bsOut.Write(playerC._shield);
	bsOut.Write(playerC._helmet);
	bsOut.Write(playerC._weapon);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}

void SpawnSystem::syncPlayers(entt::entity entity, SLNet::BitStream * bs)
{
	SLNet::BitStream bsSyncOut;

	bsSyncOut.Write((SLNet::MessageID)Signals::NW_SYNC_PLAYERS);
	bsSyncOut.Write(entity);

	auto view = m_registry->view<PositionComponent, PlayerComponent>();

	if (view.size() < 2) // only one player connected
		return;

	bsSyncOut.Write(static_cast<int>(view.size() - 1));

	for (auto e : view)
	{
		if (e == entity)
			continue;

		auto posC = m_registry->try_get<PositionComponent>(e);
		auto playerC = m_registry->try_get<PlayerComponent>(e);
		auto manaC = m_registry->try_get<ManaComponent>(e);

		bsSyncOut.Write(e);
		bsSyncOut.Write(posC->_mapID);
		bsSyncOut.Write(posC->_x);
		bsSyncOut.Write(posC->_y);
		bsSyncOut.Write(playerC->_direction);
		bsSyncOut.Write(playerC->_genre);
		bsSyncOut.Write(playerC->_race);
		bsSyncOut.Write(playerC->_body);
		bsSyncOut.Write(playerC->_head);
		bsSyncOut.Write(playerC->_shield);
		bsSyncOut.Write(playerC->_helmet);
		bsSyncOut.Write(playerC->_weapon);
		bsSyncOut.Write(manaC->_meditating);
	}

	m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsSyncOut);
}

void SpawnSystem::enttQuit(entt::entity entity, SLNet::BitStream * bs)
{
	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::NW_ENTT_QUIT);
	bsOut.Write(entity);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
	m_registry->destroy(entity);
}
