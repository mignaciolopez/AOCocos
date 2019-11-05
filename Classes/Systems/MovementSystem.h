#ifndef __MOVEMENT_SYSTEM_H__
#define __MOVEMENT_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "cocos2d.h"

enum Direction
{
	North,
	East,
	South,
	West
};

class MovementSystem : public ECS::System
{
public:
	MovementSystem();
	~MovementSystem();

	virtual void Update() override;

	void moveNorth(int eid, cocos2d::Event* ccevnt = nullptr, SLNet::BitStream* bs = nullptr);
	void moveEast(int eid, cocos2d::Event* ccevnt = nullptr, SLNet::BitStream* bs = nullptr);
	void moveSouth(int eid, cocos2d::Event* ccevnt = nullptr, SLNet::BitStream* bs = nullptr);
	void moveWest(int eid, cocos2d::Event* ccevnt = nullptr, SLNet::BitStream* bs = nullptr);

	void move(Direction dir, int eid);
	void moveLocal(Direction dir);
	void moveRemote(Direction dir, int eid);

	void stopMoving(int eid);

	void setLocalEntity(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

	int m_localEntity;

	std::map<int, std::vector<Direction>*> m_pendingMoves;

	cocos2d::MoveBy* m_moveNorth;
	cocos2d::MoveBy* m_moveEast;
	cocos2d::MoveBy* m_moveSouth;
	cocos2d::MoveBy* m_moveWest;

	cocos2d::DelayTime* m_delayCallToStopMoving;

};

#endif // __MOVEMENT_SYSTEM_H__