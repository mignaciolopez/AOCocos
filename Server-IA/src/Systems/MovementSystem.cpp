#include "MovementSystem.h"

MovementSystem::MovementSystem(entt::registry* registry)
	: m_registry(registry), m_signalsManager(nullptr)
{
	ECS_Log::s_consoleL->trace("[MovementSystem] Constructor");

	m_signalsManager = ECS::SignalsManager::getSignalsManager();

	m_signalsManager->connect<&MovementSystem::moveNorth>(Signals::MOVE_NORTH, this);
	m_signalsManager->connect<&MovementSystem::moveEast>(Signals::MOVE_EAST, this);
	m_signalsManager->connect<&MovementSystem::moveSouth>(Signals::MOVE_SOUTH, this);
	m_signalsManager->connect<&MovementSystem::moveWest>(Signals::MOVE_WEST, this);
	m_signalsManager->connect<&MovementSystem::moveStop>(Signals::MOVE_STOP, this);
	m_signalsManager->connect<&MovementSystem::broadcastFacing>(Signals::SWITCH_FACING, this);
}

MovementSystem::~MovementSystem()
{
	ECS_Log::s_consoleL->trace("[MovementSystem] Destructor");

	m_signalsManager->disconnectAll(this);
}

void MovementSystem::update(double dt)
{

}

void MovementSystem::moveNorth(entt::entity entity, SLNet::BitStream * bs)
{
	move(entity, Directions::North);
}

void MovementSystem::moveEast(entt::entity entity, SLNet::BitStream * bs)
{
	move(entity, Directions::East);
}

void MovementSystem::moveSouth(entt::entity entity, SLNet::BitStream * bs)
{
	move(entity, Directions::South);
}

void MovementSystem::moveWest(entt::entity entity, SLNet::BitStream * bs)
{
	move(entity, Directions::West);
}

void MovementSystem::moveStop(entt::entity entity, SLNet::BitStream * bs)
{
	auto posC = m_registry->try_get<PositionComponent>(entity);

	if (!posC)
		return;

	posC->_moving = false;
}

void MovementSystem::move(entt::entity entity, Directions dir)
{
	auto posC = m_registry->try_get<PositionComponent>(entity);
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!posC || !playerC)
		return;

	playerC->_direction = dir;

	SLNet::BitStream bsOut;

	int dx = 0, dy = 0;
	switch (dir)
	{
	case North:
		bsOut.Write((SLNet::MessageID)Signals::MOVE_NORTH);
		dy++;
		break;
	case East:
		bsOut.Write((SLNet::MessageID)Signals::MOVE_EAST);
		dx++;
		break;
	case South:
		bsOut.Write((SLNet::MessageID)Signals::MOVE_SOUTH);
		dy--;
		break;
	case West:
		bsOut.Write((SLNet::MessageID)Signals::MOVE_WEST);
		dx--;
		break;
	default:
		return;
	}

	auto view = m_registry->view<PositionComponent>();
	for (auto e : view)
	{
		if (entity == e)
			continue;

		auto eposC = m_registry->try_get<PositionComponent>(e);

		if (eposC->_x == posC->_x + dx && eposC->_y == posC->_y + dy)
		{
			ECS_Log::s_consoleL->trace("[MovementSystem] RENOCK Collision Player: %i, (%i, %i) with e: %i, (%i, %i)", entity, posC->_x, posC->_y, e, eposC->_x, eposC->_y);
			bsOut.Reset();
			bsOut.Write((SLNet::MessageID)Signals::MOVE_RENOCK);
			bsOut.Write(entity);
			bsOut.Write(posC->_mapID);
			bsOut.Write(posC->_x);
			bsOut.Write(posC->_y);
			bsOut.Write(playerC->_direction);
			m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
			//m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
			return;
		}
	}

	if (posC->_x + dx < 0 || posC->_y + dy < 0 || posC->_x + dx > 99 || posC->_y + dy > 99)
	{
		ECS_Log::s_consoleL->trace("[MovementSystem] RENOCK MAP LIMITS Player: %i, (%i, %i)", entity, posC->_x, posC->_y);
		bsOut.Reset();
		bsOut.Write((SLNet::MessageID)Signals::MOVE_RENOCK);
		bsOut.Write(entity);
		bsOut.Write(posC->_mapID);
		bsOut.Write(posC->_x);
		bsOut.Write(posC->_y);
		bsOut.Write(playerC->_direction);
		m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
		m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
		return;
	}

	bsOut.Write(entity);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);

	posC->_x += dx;
	posC->_y += dy;

	posC->_moving = true;

	auto manaC = m_registry->try_get<ManaComponent>(entity);
	if (manaC)
	{
		if (manaC->_meditating)
			m_signalsManager->publish(Signals::MEDITATE, entity);
	}

	if (playerC->_isAlive)
		return;

	if (posC->_x == 1 && posC->_y == 1)
	{
		auto playerC = m_registry->try_get<PlayerComponent>(entity);
		playerC->_isAlive = true;

		auto healthC = m_registry->try_get<HealthComponent>(entity);
		healthC->_hp = healthC->_hpMax;

		bsOut.Reset();
		bsOut.Write((SLNet::MessageID)Signals::COMBAT_RESURRECT);
		bsOut.Write(entity);
		m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
		m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
	}

	//ECS_Log::s_consoleL->trace("[MovementSystem] Player: %i, (%i, %i)", entity, posC->_x, posC->_y);
}

void MovementSystem::broadcastFacing(entt::entity entity, SLNet::BitStream * bs)
{
	Directions dir;
	if (!bs)
	{
		return;
	}

	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC)
		return;

	bs->Read(dir);

	playerC->_direction = dir;

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::SWITCH_FACING);
	bsOut.Write(entity);
	bsOut.Write(dir);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}
