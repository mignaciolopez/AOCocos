#ifndef PARTICLES_SYSTEM_H__
#define PARTICLES_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

class ParticlesSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::ParticlesSystem_tag;
	ParticlesSystem(cocos2d::Scene* scene, entt::registry* registry);
	~ParticlesSystem();

	virtual void update(float dt) override;

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);
	void AnimSpawn(entt::entity entity, SLNet::BitStream* bs);
	void AnimUnSpawn(entt::entity entity, SLNet::BitStream* bs);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	entt::entity m_localEntt = entt::null;

	cocos2d::Scene* m_scene;

	std::map<entt::entity, cocos2d::ParticleSystemQuad*> m_meditations;
};

#endif // !PARTICLES_SYSTEM_H__
