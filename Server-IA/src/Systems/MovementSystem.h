#ifndef MOVEMENT_SYSTEM_H__
#define MOVEMENT_SYSTEM_H__

#include "ECS/SignalsManager.h"
#include "ECS/SignalsList.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Components/IncludeComponents.h"

#include "ECS/ECS_Log.h"

class MovementSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::MovementSystem_tag;
	MovementSystem(entt::registry* registry);
	~MovementSystem();

	virtual void update(double dt) override;

	void moveNorth(entt::entity entity, SLNet::BitStream* bs);
	void moveEast(entt::entity entity, SLNet::BitStream* bs);
	void moveSouth(entt::entity entity, SLNet::BitStream* bs);
	void moveWest(entt::entity entity, SLNet::BitStream* bs);
	void moveStop(entt::entity entity, SLNet::BitStream* bs);

	void move(entt::entity entity, Directions dir);

	void broadcastFacing(entt::entity entity, SLNet::BitStream* bs);

private:
	std::shared_ptr<ECS::SignalsManager> m_signalsManager;

	entt::registry* m_registry;
};

#endif // !MOVEMENT_SYSTEM_H__