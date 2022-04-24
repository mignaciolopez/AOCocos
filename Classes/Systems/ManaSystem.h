#ifndef MEDITATION_SYSTEM_H__
#define MEDITATION_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Graphics/Graphics.h"

class ManaSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::ManaSystem_tag;
	ManaSystem(cocos2d::Scene* scene, entt::registry* registry);
	~ManaSystem();

	virtual void update(float dt) override;

	void onConstructManaC(entt::registry& registry, entt::entity entity);
	void onDestroyManaC(entt::registry& registry, entt::entity entity);

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

	void meditateStart(entt::entity entity, SLNet::BitStream * bs);
	void meditateEnd(entt::entity entity, SLNet::BitStream * bs);

	void manaUpdate(entt::entity entity, SLNet::BitStream * bs);
	void manaUsePotion(entt::entity entity, SLNet::BitStream * bs);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	cocos2d::Director* m_director;

	cocos2d::Scene* m_scene;

	entt::entity m_localEntt = entt::null;
	Graphics* m_graphics;
};

#endif // !MEDITATION_SYSTEM_H__
