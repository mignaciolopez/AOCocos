#ifndef SPAWN_SYSTEM_H__
#define SPAWN_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

class SpawnSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::SpawnSystem_tag;
	SpawnSystem(cocos2d::Scene* scene, entt::registry* registry);
	~SpawnSystem();

	virtual void update(float dt) override;

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);
	void entityJoined(entt::entity entity, SLNet::BitStream* bs);

	void syncPlayers(entt::entity entity, SLNet::BitStream* bs);
	void removePlayer(entt::entity entity, SLNet::BitStream* bs);

private:
	void createLocal(entt::entity entity, SLNet::BitStream* bs);
	void createRemote(entt::entity entity, SLNet::BitStream* bs);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	entt::entity m_localEntt = entt::null;

	cocos2d::Scene* m_scene;
};

#endif // !SPAWN_SYSTEM_H__