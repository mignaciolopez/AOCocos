#include "HealthSystem.h"

HealthSystem::HealthSystem(entt::registry* registry)
	: m_registry(registry)
{
	ECS_Log::s_consoleL->trace("[HealthSystem] Constructor");

	m_signalsManager = ECS::SignalsManager::getSignalsManager();

	m_registry->on_construct<HealthComponent>().connect<&HealthSystem::onConstructHealthC>(this);
	m_registry->on_destroy<HealthComponent>().connect<&HealthSystem::onDestroyHealthC>(this);

	m_signalsManager->connect<&HealthSystem::healthUsePotion>(Signals::HEALTH_USE_POTION, this);
}

HealthSystem::~HealthSystem()
{
	ECS_Log::s_consoleL->trace("[HealthSystem] Destructor");

	m_signalsManager->disconnectAll(this);

	m_registry->on_construct<HealthComponent>().disconnect<&HealthSystem::onConstructHealthC>(this);
	m_registry->on_destroy<HealthComponent>().disconnect<&HealthSystem::onDestroyHealthC>(this);
}

void HealthSystem::update(double dt)
{
	
}

void HealthSystem::onConstructHealthC(entt::registry & registry, entt::entity entity)
{

}

void HealthSystem::onDestroyHealthC(entt::registry & registry, entt::entity entity)
{

}

void HealthSystem::healthUsePotion(entt::entity entity, SLNet::BitStream * bs)
{
	auto healthC = m_registry->try_get<HealthComponent>(entity);

	healthC->_hp += 50;

	if (healthC->_hp > healthC->_hpMax)
		healthC->_hp = healthC->_hpMax;

	SLNet::BitStream bsOut;
	bsOut.Write((SLNet::MessageID)Signals::HEALTH_UPDATE);
	bsOut.Write(entity);
	bsOut.Write(healthC->_hp);
	m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);

	bsOut.Reset();
	bsOut.Write((SLNet::MessageID)Signals::HEALTH_USE_POTION);
	bsOut.Write(entity);
	m_signalsManager->publish(Signals::NW_SEND_CLIENT, entity, &bsOut);
	m_signalsManager->publish(Signals::NW_SEND_BROADCAST, entity, &bsOut);
}
