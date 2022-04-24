#ifndef MOVEMENT_SYSTEM_H__
#define MOVEMENT_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

class MovementSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::MovementSystem_tag;
	MovementSystem(entt::registry* registry);
	~MovementSystem();

	virtual void update(float dt) override;

	void onUpdatePosC(entt::registry& registry, entt::entity entity);

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

	void moveNorth(entt::entity entity, SLNet::BitStream* bs);
	void moveEast(entt::entity entity, SLNet::BitStream* bs);
	void moveSouth(entt::entity entity, SLNet::BitStream* bs);
	void moveWest(entt::entity entity, SLNet::BitStream* bs);

	void switchRemoteFacing(entt::entity entity, SLNet::BitStream* bs);
	
	void moveRenock(entt::entity entity, SLNet::BitStream* bs);

	bool move(entt::entity entity, Directions dir);

	void stopMoving(entt::entity entity, int y);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	entt::entity m_localEntt = entt::null;

	std::map<entt::entity, entt::entity> m_entitiesToUpdate;

	cocos2d::Director* m_director;

	float m_vel = 0.2f;
	double m_fpsPivot;

	cocos2d::MoveBy* m_moveNorth;
	cocos2d::MoveBy* m_moveEast;
	cocos2d::MoveBy* m_moveSouth;
	cocos2d::MoveBy* m_moveWest;
};

#endif // !MOVEMENT_SYSTEM_H__