#ifndef COMBAT_SYSTEM_H__
#define COMBAT_SYSTEM_H__

#include "ECS/SignalsManager.h"
#include "ECS/SignalsList.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Components/IncludeComponents.h"

class CombatSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::CombatSystem_tag;
	CombatSystem(entt::registry* registry);
	~CombatSystem();

	virtual void update(double dt) override;

	void punch(entt::entity entity, SLNet::BitStream* bs);
	void spellThrow(entt::entity entity, SLNet::BitStream* bs);

private:
	std::shared_ptr<ECS::SignalsManager> m_signalsManager;

	entt::registry* m_registry;

};

#endif // !COMBAT_SYSTEM_H__