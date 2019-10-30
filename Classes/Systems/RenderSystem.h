#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__

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

class RenderSystem : public ECS::System
{
public:
	RenderSystem();
	~RenderSystem();

	virtual void Update() override;
	void moveNorth(unsigned int eid, unsigned int cid);
	void moveEast(unsigned int eid, unsigned int cid);
	void moveSouth(unsigned int eid, unsigned int cid);
	void moveWest(unsigned int eid, unsigned int cid);

	void move(Direction dir, unsigned int eid, unsigned int cid);

	void stopMoving(unsigned int cid);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::ComponentManager* m_componentManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

};

#endif // __RENDER_SYSTEM_H__