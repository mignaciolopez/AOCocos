#ifndef __ANIMATION_SYSTEM_H__
#define __ANIMATION_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "cocos2d.h"

class AnimationSystem : public ECS::System
{
public:
	AnimationSystem();
	~AnimationSystem();

	virtual void update(float dt) override;

	void animate(int eid, cocos2d::Event*, SLNet::BitStream* bs);
	void animateWeapon(int eid, cocos2d::Event*, SLNet::BitStream* bs);
	void animateShield(int eid, cocos2d::Event*, SLNet::BitStream* bs);

	void setBodyCF(int eid);

	void attackEnd(int eid);

private:
	void setBody(int eid);
	void setHead(int eid);
	void setShield(int eid);
	void setHelmet(int eid);
	void setWeapon(int eid);

public:

private:
	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;
	cocos2d::SpriteFrameCache* m_sfCache;
	
};

#endif //__ANIMATION_SYSTEM_H__