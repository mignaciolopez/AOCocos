#ifndef __COMBAT_SYSTEM_H__
#define __COMBAT_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "cocos2d.h"

class CombatSystem : public ECS::System
{
public:
	CombatSystem();
	~CombatSystem();

	virtual void Update() override;

	void setLocaleid(int eid, cocos2d::Event* ccEvent, SLNet::BitStream* bs);
	
	void punchAir(int eid, cocos2d::Event* ccEvnt, SLNet::BitStream* bs);
	void punchTarget(int eid, cocos2d::Event* ccEvnt, SLNet::BitStream* bs);
	//Client prediction
	void punch(int eid, cocos2d::Event* ccEvent, SLNet::BitStream* bs);


private:
	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;

	int m_localeid;
};

#endif // __COMBAT_SYSTEM_H__