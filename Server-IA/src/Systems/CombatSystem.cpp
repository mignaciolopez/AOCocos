#include "CombatSystem.h"

CombatSystem::CombatSystem(entt::registry* registry)
	: m_registry(registry), m_signalsManager(nullptr)
{
	ECS_Log::s_consoleL->trace("[CombatSystem] Constructor.");

	m_signalsManager = ECS::SignalsManager::getSignalsManager();

	m_signalsManager->connect<&CombatSystem::punch>(Signals::COMBAT_PUNCH, this);
	m_signalsManager->connect<&CombatSystem::spellThrow>(Signals::COMBAT_SPELLS_THROW, this);
}

CombatSystem::~CombatSystem()
{
	ECS_Log::s_consoleL->trace("[CombatSystem] Destructor.");

	m_signalsManager->disconnectAll(this);
}

void CombatSystem::update(double dt)
{
}

void CombatSystem::punch(entt::entity entity, SLNet::BitStream * bs)
{
	ECS_Log::s_consoleL->trace("[CombatSystem] punch().");
	ECS_Log::s_consoleL->debug("[CombatSystem] punch() entity: {}.", entity);

	auto intC = m_registry->try_get<IntervalComponent>(entity);

	if (!intC)
	{
		ECS_Log::s_consoleL->error("[CombatSystem] punch() IntervalComponent is nullptr. entity: {}.", entity);
		return;
	}

	if (intC->_dtLastAttack < intC->_constAttack)
	{
		ECS_Log::s_consoleL->warn("[CombatSystem] punch() IntervalComponent: To soon to attack. entity: {}.", entity);
		return;
	}

	auto manaC = m_registry->try_get<ManaComponent>(entity);

	if (manaC)
	{
		if (manaC->_meditating)
			return;
	}
	else
		ECS_Log::s_consoleL->debug("[CombatSystem] punch() ManaComponent: is nullptr. entity: {}.", entity);

	auto posC = m_registry->try_get<PositionComponent>(entity);
	if (!posC)
	{
		ECS_Log::s_consoleL->error("[CombatSystem] punch() posC is nullptr. entity: {}.", entity);
		return;
	}

	auto playerC = m_registry->try_get<PlayerComponent>(entity);
	if (!playerC)
	{
		ECS_Log::s_consoleL->error("[CombatSystem] punch() playerC is nullptr. entity: {}.", entity);
		return;
	}

	auto healthC = m_registry->try_get<HealthComponent>(entity);
	if (!healthC)
	{
		ECS_Log::s_consoleL->error("[CombatSystem] punch() healthC is nullptr. entity: {}.", entity);
		return;
	}
	

	if (!playerC->_isAlive)
	{
		ECS_Log::s_consoleL->debug("[CombatSystem] punch() entity: {} is DEAD.", entity);
		return;
	}

	int tx = posC->_x;
	int ty = posC->_y;

	switch (playerC->_direction)
	{
	case Directions::North:
		ty++;
		break;
	case Directions::East:
		tx++;
		break;
	case Directions::South:
		ty--;
		break;
	case Directions::West:
		tx--;
		break;
	default:
		break;
	}

	SLNet::BitStream bsOut;

	auto view = m_registry->view<PositionComponent>();
	for (auto e : view)
	{
		if (e == entity)
		{
			ECS_Log::s_consoleL->debug("[CombatSystem] punch() attacker entity{:d} == target entity:{:d}", entity, e);
			continue;
		}

		auto ePosC = m_registry->try_get<PositionComponent>(e);
		if (!ePosC)
		{
			ECS_Log::s_consoleL->error("[CombatSystem] punch() Target entity:{:d} has no PositionComponent.", e);
			continue;
		}

		auto eHealthC = m_registry->try_get<HealthComponent>(e);
		if (!eHealthC)
		{
			ECS_Log::s_consoleL->error("[CombatSystem] punch() Target entity:{:d} has no HealthComponent.", e);
			continue;
		}

		auto ePlayerC = m_registry->try_get<PlayerComponent>(e);
		if (!ePlayerC)
		{
			ECS_Log::s_consoleL->error("[CombatSystem] punch() Target entity:{:d} has no PlayerComponent.", e);
			continue;
		}

		if (ePosC->_x == tx && ePosC->_y == ty && ePlayerC->_isAlive)
		{
			ECS_Log::s_consoleL->debug("[CombatSystem] punch() entity:{:d} hited entity:{:d} at ({:d},{:d})", entity, e, ePosC->_x, ePosC->_y);

			eHealthC->_hp -= 180;
			if (eHealthC->_hp < 1)
			{
				ePlayerC->_isAlive = false;
				eHealthC->_hp = 0;

				bsOut.Write((SLNet::MessageID)Signals::COMBAT_PUNCH_TARGET);
				bsOut.Write(entity);
				bsOut.Write(e);
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
				m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);

				ECS_Log::s_consoleL->debug("[CombatSystem] punch() Notifying entity:{:d} about new health status", e);
				bsOut.Reset();
				bsOut.Write((SLNet::MessageID)Signals::HEALTH_UPDATE);
				bsOut.Write(e);
				bsOut.Write(eHealthC->_hp);
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, e, &bsOut);

				ECS_Log::s_consoleL->debug("[CombatSystem] punch() entity:{:d} Should stop meditation", e);
				m_signalsManager->publish(Signals::MEDITATE, e);

				bsOut.Reset();
				bsOut.Write((SLNet::MessageID)Signals::COMBAT_DEAD);
				bsOut.Write(entity);
				bsOut.Write(e);	//target entity is the dead one
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
				m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
				ECS_Log::s_consoleL->debug("[CombatSystem] punch() entity:{:d} killed entity:{:d} at ({:d},{:d})", entity, e, ePosC->_x, ePosC->_y);
			}
			else
			{
				bsOut.Write((SLNet::MessageID)Signals::COMBAT_PUNCH_TARGET);
				bsOut.Write(entity);
				bsOut.Write(e);
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
				m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);

				ECS_Log::s_consoleL->debug("[CombatSystem] punch() Notifying entity:{:d} about new health status", e);
				bsOut.Reset();
				bsOut.Write((SLNet::MessageID)Signals::HEALTH_UPDATE);
				bsOut.Write(e);
				bsOut.Write(eHealthC->_hp);
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, e, &bsOut);

				auto eManaC = m_registry->try_get<ManaComponent>(e);
				if (eManaC)
				{
					if (eManaC->_meditating)
					{
						ECS_Log::s_consoleL->debug("[CombatSystem] punch() entity:{:d} Should stop meditation", e);
						m_signalsManager->publish(Signals::MEDITATE, e);
					}
				}
				else
					ECS_Log::s_consoleL->debug("[CombatSystem] punch() ManaComponent: is nullptr. entity: {}.", e);
			}

			intC->_dtLastAttack = 0.0f;
			return;
		}
	}

	ECS_Log::s_consoleL->debug("[CombatSystem] punch() entity:{} attacked invalid target", entity);
	bsOut.Write((SLNet::MessageID)Signals::COMBAT_PUNCH_AIR);
	bsOut.Write(entity);
	m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);

	intC->_dtLastAttack = 0.0f;
}

void CombatSystem::spellThrow(entt::entity entity, SLNet::BitStream * bs)
{
	auto intC = m_registry->try_get<IntervalComponent>(entity);

	if (!intC)
		return;

	if (intC->_dtLastAttack < intC->_constAttack)
	{
		return;
	}

	auto manaC = m_registry->try_get<ManaComponent>(entity);

	if (manaC)
	{
		if (manaC->_meditating)
			return;

		if (manaC->_mp < 850)
			return;
	}

	if (!bs)
	{
		return;
	}

	auto posC = m_registry->try_get<PositionComponent>(entity);

	if (!posC)
	{
		return;
	}

	auto healthC = m_registry->try_get<HealthComponent>(entity);

	if (!healthC)
	{
		return;
	}

	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!playerC->_isAlive)
		return;

	SLNet::BitStream bsOut;

	int tx = -1;
	int ty = -1;

	bs->Read(tx);
	bs->Read(ty);

	auto view = m_registry->view<PositionComponent, HealthComponent>();
	for (auto e : view)
	{
		if (e == entity)
			continue;

		auto ePosC = m_registry->try_get<PositionComponent>(e);
		if (!ePosC)
			continue;

		auto eHealthC = m_registry->try_get<HealthComponent>(e);
		if (!eHealthC)
			continue;

		auto ePlayerC = m_registry->try_get<PlayerComponent>(e);
		if (!ePlayerC)
			continue;

		if (ePosC->_x == tx && ePosC->_y == ty && ePlayerC->_isAlive)
		{
			auto manaC = m_registry->try_get<ManaComponent>(entity);
			if (manaC)
			{
				manaC->_mp -= 850;
				bsOut.Reset();
				bsOut.Write((SLNet::MessageID)Signals::MANA_UPDATE);
				bsOut.Write(entity);
				bsOut.Write(manaC->_mp);
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
			}

			eHealthC->_hp -= 180;


			if (eHealthC->_hp < 1)
			{
				ePlayerC->_isAlive = false;

				bsOut.Reset();
				bsOut.Write((SLNet::MessageID)Signals::COMBAT_SPELLS_TARGET);
				bsOut.Write(entity);
				bsOut.Write(e);
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
				m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);

				m_signalsManager->publish(Signals::MEDITATE, e);

				bsOut.Reset();
				bsOut.Write((SLNet::MessageID)Signals::HEALTH_UPDATE);
				bsOut.Write(e);
				bsOut.Write(eHealthC->_hp);
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, e, &bsOut);

				eHealthC->_hp = 0;
				bsOut.Reset();
				bsOut.Write((SLNet::MessageID)Signals::COMBAT_DEAD);
				bsOut.Write(entity); 
				bsOut.Write(e);	//target entity is the dead one
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
				m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
				//ECS_Log::s_consoleL->trace("[CombatSystem] Player: %i Casted (%i, %i) On %i (%i, %i)", entity, tx, ty, e, eposC->_x, eposC->_y);
			}
			else
			{
				bsOut.Reset();
				bsOut.Write((SLNet::MessageID)Signals::COMBAT_SPELLS_TARGET);
				bsOut.Write(entity);
				bsOut.Write(e);
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
				m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);

				bsOut.Reset();
				bsOut.Write((SLNet::MessageID)Signals::HEALTH_UPDATE);
				bsOut.Write(e);
				bsOut.Write(eHealthC->_hp);
				m_signalsManager->publish(Signals::NW_SEND_CLIENT, e, &bsOut);

				auto eManaC = m_registry->try_get<ManaComponent>(e);
				if (eManaC)
				{
					if (eManaC->_meditating)
						m_signalsManager->publish(Signals::MEDITATE, e);
				}
				//ECS_Log::s_consoleL->trace("[CombatSystem] Player: %i Casted (%i, %i) On %i (%i, %i)", entity, tx, ty, e, eposC->_x, eposC->_y);
			}

			intC->_dtLastAttack = 0.0f;
			return;
		}
	}

	bsOut.Write((SLNet::MessageID)Signals::COMBAT_SPELLS_AIR);
	bsOut.Write(entity);
	m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);

	intC->_dtLastAttack = 0.0f;
	//ECS_Log::s_consoleL->trace("[CombatSystem] Player: %i Casted Spell at (%i, %i)", entity, tx, ty);
	//m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut); 
	//if i send a broadcast is no animate some missing shot animation
}
