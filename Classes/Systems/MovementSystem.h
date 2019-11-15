#ifndef __MOVEMENT_SYSTEM_H__
#define __MOVEMENT_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "cocos2d.h"
#include <ctime>

enum Direction;

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

	void switchRemoteFacing(int eid, cocos2d::Event* ccevnt = nullptr, SLNet::BitStream* bs = nullptr);

	bool move(int eid, Direction dir);

	void stopMoving(int eid);

	void setLocalEntity(int eid, cocos2d::Event * ccevent, SLNet::BitStream * bs);


private:
	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

	int m_localeid;

	clock_t m_clock_b;
	clock_t m_clock_e;

	const float m_vel = 0.2f;
	double m_fpsPivot;
	int m_fpsCounter;
	int m_fps;

	cocos2d::MoveBy* m_moveNorth;
	cocos2d::MoveBy* m_moveEast;
	cocos2d::MoveBy* m_moveSouth;
	cocos2d::MoveBy* m_moveWest;
};

#endif // __MOVEMENT_SYSTEM_H__