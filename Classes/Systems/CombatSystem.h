#ifndef COMBAT_SYSTEM_H__
#define COMBAT_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

class CombatSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::CombatSystem_tag;
	CombatSystem(entt::registry* registry);
	~CombatSystem();

	virtual void update(float dt) override;

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);
	
	void punchAir(entt::entity entity, SLNet::BitStream* bs);
	void punchTarget(entt::entity entity, SLNet::BitStream* bs);

	void spellAir(entt::entity entity, SLNet::BitStream* bs);
	void spellTarget(entt::entity entity, SLNet::BitStream* bs);

	//Client prediction
	void punch(entt::entity entity, SLNet::BitStream* bs);
	void spellThrow(entt::entity entity, SLNet::BitStream* bs);

	void dead(entt::entity entity, SLNet::BitStream* bs);
	void resurrect(entt::entity entity, SLNet::BitStream* bs);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	entt::entity m_localEntt = entt::null;
};

#endif // !COMBAT_SYSTEM_H__