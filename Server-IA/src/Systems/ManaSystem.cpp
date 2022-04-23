#include "ManaSystem.h"

ManaSystem::ManaSystem(entt::registry* registry)
	: m_registry(registry)
{
	ECS_Log::s_consoleL->trace("[ManaSystem] Constructor");

	m_signalsManager = ECS::SignalsManager::getSignalsManager();

	m_registry->on_construct<ManaComponent>().connect<&ManaSystem::onConstructManaC>(this);
	m_registry->on_destroy<ManaComponent>().connect<&ManaSystem::onDestroyManaC>(this);

	m_signalsManager->connect<&ManaSystem::meditate>(Signals::MEDITATE, this);
	m_signalsManager->connect<&ManaSystem::manaUsePotion>(Signals::MANA_USE_POTION, this);
}

ManaSystem::~ManaSystem()
{
	ECS_Log::s_consoleL->trace("[ManaSystem] Destructor");

	m_signalsManager->disconnectAll(this);

	m_registry->on_construct<ManaComponent>().disconnect<&ManaSystem::onConstructManaC>(this);
	m_registry->on_destroy<ManaComponent>().disconnect<&ManaSystem::onDestroyManaC>(this);
}

void ManaSystem::update(double dt)
{
	m_timeElapsed += dt;

	if (m_timeElapsed > 1.0)
	{
		m_timeElapsed = 0.0;

		auto view = m_registry->view<ManaComponent>();

		for (auto& e : view)
		{
			if (m_entitiesMeditating.find(e) == m_entitiesMeditating.end())
				continue;

			auto manaC = m_registry->try_get<ManaComponent>(e);

			manaC->_mp += 150;

			if (manaC->_mp > manaC->_mpMax)
			{
				manaC->_mp = manaC->_mpMax;
				m_signalsManager->publish(Signals::MEDITATE, e);
			}
			
			SLNet::BitStream bsOut;
			bsOut.Write((SLNet::MessageID)Signals::MANA_UPDATE);
			bsOut.Write(e);
			bsOut.Write(manaC->_mp);
			m_signalsManager->publish(Signals::NW_SEND_CLIENT, e, &bsOut);
		}
	}
	
}

void ManaSystem::onConstructManaC(entt::registry & registry, entt::entity entity)
{
	
}

void ManaSystem::onDestroyManaC(entt::registry & registry, entt::entity entity)
{
	
}

void ManaSystem::meditate(entt::entity entity, SLNet::BitStream* bs)
{
	auto manaC = m_registry->try_get<ManaComponent>(entity);
	auto posC = m_registry->try_get<PositionComponent>(entity);
	auto playerC = m_registry->try_get<PlayerComponent>(entity);

	if (!manaC || !posC || !playerC)
	{
		return;
	}

	SLNet::BitStream bsOut;

	if (!playerC->_isAlive)
	{
		manaC->_meditating = false;
		bsOut.Write((SLNet::MessageID)Signals::MEDITATE_END);
		bsOut.Write(entity);
		m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
		m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
		m_entitiesMeditating.erase(entity);
		return;
	}

	if (manaC->_meditating || posC->_moving)
	{
		manaC->_meditating = false;
		bsOut.Write((SLNet::MessageID)Signals::MEDITATE_END);
		bsOut.Write(entity);
		m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
		m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
		m_entitiesMeditating.erase(entity);
	}
	else
	{
		bsOut.Write((SLNet::MessageID)Signals::MEDITATE_START);
		bsOut.Write(entity);
		m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
		m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
		manaC->_meditating = true;
		m_entitiesMeditating.emplace(entity, true);
	}
}

void ManaSystem::manaUsePotion(entt::entity entity, SLNet::BitStream * bs)
{
	auto manaC = m_registry->try_get<ManaComponent>(entity);

	manaC->_mp += 80;

	if (manaC->_mp > manaC->_mpMax)
		manaC->_mp = manaC->_mpMax;

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::MANA_UPDATE);
	bsOut.Write(entity);
	bsOut.Write(manaC->_mp);
	m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);

	bsOut.Reset();
	bsOut.Write((SLNet::MessageID)Signals::MANA_USE_POTION);
	bsOut.Write(entity);
	m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}
