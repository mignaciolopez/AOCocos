#ifndef __ANIMATION_SYSTEM_H__
#define __ANIMATION_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "cocos2d.h"

class AnimationSystem : public ECS::System
{
public:
	AnimationSystem();
	~AnimationSystem();

	virtual void Update() override;

private:

public:

private:
	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

};

#endif //__ANIMATION_SYSTEM_H__