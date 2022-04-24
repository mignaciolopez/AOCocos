#ifndef HEALTH_SYSTEM_H__
#define HEALTH_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

class HealthSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::HealthSystem_tag;
	HealthSystem(cocos2d::Scene* scene, entt::registry* registry);
	~HealthSystem();

	virtual void update(float dt) override;

	void onConstructHealthC(entt::registry& registry, entt::entity entity);
	void onDestroyHealthC(entt::registry& registry, entt::entity entity);

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

	void healthUpdate(entt::entity entity, SLNet::BitStream * bs);
	void healthUsePotion(entt::entity entity, SLNet::BitStream * bs);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	cocos2d::Director* m_director;

	cocos2d::Scene* m_scene;

	entt::entity m_localEntt = entt::null;
};

#endif // !HEALTH_SYSTEM_H__