#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__

#include "ECS/ECS_Engine.h"

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

private:
	ECS::EntityManager* m_entiyManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

};

#endif // __RENDER_SYSTEM_H__