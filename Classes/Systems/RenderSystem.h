#ifndef __RENDER_SYSTEM_H__
#define __RENDER_SYSTEM_H__

#include "ECS/Systems/System.h"

class RenderSystem : public ECS::System
{
public:
	RenderSystem();
	~RenderSystem();

	virtual void Update() override;

private:
	std::vector<ComponentType> m_compatibleComponents;

};

#endif // __RENDER_SYSTEM_H__