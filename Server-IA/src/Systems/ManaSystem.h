#ifndef MANA_SYSTEM_H__
#define MANA_SYSTEM_H__

#include "ECS/SignalsManager.h"
#include "ECS/SignalsList.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Components/IncludeComponents.h"

#include "ECS/ECS_Log.h"

class ManaSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::ManaSystem_tag;
	ManaSystem(entt::registry* registry);
	~ManaSystem();

	virtual void update(double dt) override;

	void onConstructManaC(entt::registry& registry, entt::entity entity);
	void onDestroyManaC(entt::registry& registry, entt::entity entity);

	void meditate(entt::entity entity, SLNet::BitStream * bs);
	void manaUsePotion(entt::entity entity, SLNet::BitStream * bs);

private:
	std::shared_ptr<ECS::SignalsManager> m_signalsManager;
	entt::registry* m_registry;

	std::map<entt::entity, bool> m_entitiesMeditating;

	double m_timeElapsed = 0.0;
};

#endif // !MANA_SYSTEM_H__
