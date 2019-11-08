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

	void setLocalEntity(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

private:
	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

	int m_localeid;
};

#endif // __RENDER_SYSTEM_H__