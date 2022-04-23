#ifndef HEALTH_SYSTEM_H__
#define HEALTH_SYSTEM_H__

#include "ECS/SignalsManager.h"
#include "ECS/SignalsList.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Components/IncludeComponents.h"

#include "ECS/ECS_Log.h"

class HealthSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::HealthSystem_tag;
	HealthSystem(entt::registry* registry);
	~HealthSystem();

	virtual void update(double dt) override;

	void onConstructHealthC(entt::registry& registry, entt::entity entity);
	void onDestroyHealthC(entt::registry& registry, entt::entity entity);

	void healthUsePotion(entt::entity entity, SLNet::BitStream * bs);

private:
	std::shared_ptr<ECS::SignalsManager> m_signalsManager;
	entt::registry* m_registry;
};

#endif // !HEALTH_SYSTEM_H__
