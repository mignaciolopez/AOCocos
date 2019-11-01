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

	void moveNorth(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt = nullptr);
	void moveEast(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt = nullptr);
	void moveSouth(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt = nullptr);
	void moveWest(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt = nullptr);

	void move(Direction dir, unsigned int eid, unsigned int cid);

	void stopMoving(unsigned int cid);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::ComponentManager* m_componentManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

};

#endif // __MOVEMENT_SYSTEM_H__