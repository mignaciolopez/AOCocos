#ifndef __SPAWN_SYSTEM_H__
#define __SPAWN_SYSTEM_H__

#include "ECS/SignalsManager.h"
#include "ECS/SignalsList.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Components/IncludeComponents.h"

#include "ECS/ECS_Log.h"

class SpawnSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::SpawnSystem_tag;
	SpawnSystem(entt::registry* registry);
	~SpawnSystem();

	virtual void update(double dt) override;

	void requestEntt(entt::entity entity, SLNet::BitStream* bs);
	void syncPlayers(entt::entity entity, SLNet::BitStream* bs);
	void enttQuit(entt::entity entity, SLNet::BitStream* bs);

private:

private:
	std::shared_ptr<ECS::SignalsManager> m_signalsManager;

	entt::registry* m_registry;

};

#endif // __SPAWN_SYSTEM_H__