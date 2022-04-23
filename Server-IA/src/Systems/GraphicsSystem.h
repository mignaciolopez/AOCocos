#ifndef GRAPHICS_SYSTEM_H__
#define GRAPHICS_SYSTEM_H__

#include "ECS/SignalsManager.h"
#include "ECS/SignalsList.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Components/IncludeComponents.h"

class GraphicsSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::GraphicsSystem_tag;
	GraphicsSystem(entt::registry* registry);
	~GraphicsSystem();

	virtual void update(double dt) override;

	void loadBody(entt::entity entity, SLNet::BitStream* bs);
	void loadHead(entt::entity entity, SLNet::BitStream* bs);
	void loadHelmet(entt::entity entity, SLNet::BitStream* bs);
	void loadShield(entt::entity entity, SLNet::BitStream* bs);
	void loadWeapon(entt::entity entity, SLNet::BitStream* bs);
	void animateSpell(entt::entity entity, SLNet::BitStream* bs);
	void animateWeapon(entt::entity entity, SLNet::BitStream* bs);
	void animateShield(entt::entity entity, SLNet::BitStream* bs);

private:

public:

private:
	std::shared_ptr<ECS::SignalsManager> m_signalsManager;

	entt::registry* m_registry;

};

#endif // !GRAPHICS_SYSTEM_H__