#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__

#include "ECS/ECSEngine.h"

namespace cocos2d
{
	class Director;
}

class RenderSystem : public ECS::System
{
public:
	RenderSystem();
	~RenderSystem();

	virtual void Update() override;
	void spawn(unsigned int eid, unsigned int cid);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::ComponentManager* m_componentManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

};

#endif // __RENDER_SYSTEM_H__