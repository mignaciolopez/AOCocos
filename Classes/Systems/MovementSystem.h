#ifndef __MOVEMENT_SYSTEM_H__
#define __MOVEMENT_SYSTEM_H__

#include "ECS/ECSEngine.h"

namespace cocos2d
{
	class Director;
}

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

	void moveNorth(int eid, cocos2d::Event* ccevnt = nullptr);
	void moveEast(int eid, cocos2d::Event* ccevnt = nullptr);
	void moveSouth(int eid, cocos2d::Event* ccevnt = nullptr);
	void moveWest(int eid, cocos2d::Event* ccevnt = nullptr);

	void move(Direction dir, int eid);

	void stopMoving(int eid);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

};

#endif // __MOVEMENT_SYSTEM_H__