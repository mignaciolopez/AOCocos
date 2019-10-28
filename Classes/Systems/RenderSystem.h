#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__

#include "ECS/Systems/System.h"
#include "ECS/ECSEngine.h"

#include "cocos2d.h"

class RenderSystem : public ECS::System
{
public:
	RenderSystem();
	~RenderSystem();

	virtual void Update() override;

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::ComponentManager* m_componentManager;

	cocos2d::Director* m_director;

};

#endif // __RENDER_SYSTEM_H__