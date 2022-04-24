#ifndef INTERVAL_SYSTEM_H__
#define INTERVAL_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

class IntervalSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::IntervalSystem_tag;
	IntervalSystem(cocos2d::Scene* scene, entt::registry* registry);
	~IntervalSystem();

	virtual void update(float dt) override;

	void onConstructIntC(entt::registry& registry, entt::entity entity);

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);
	void loadIntervals(entt::entity entity, SLNet::BitStream* bs);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	entt::entity m_localEntt = entt::null;

	cocos2d::Scene* m_scene;
};

#endif // !INTERVAL_SYSTEM_H__
