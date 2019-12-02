#ifndef __MAP_SYSTEM_H__
#define __MAP_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "cocos2d.h"

class MapSystem : public ECS::System
{
public:
	MapSystem();
	~MapSystem();

	virtual void update(float dt) override;
	
	virtual void setLocaleid(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	virtual void addeidChild(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	virtual void removeChild(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	
	virtual void createMapC(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	virtual void loadMap(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

	virtual void canMove(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

	virtual void toggleDebug(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

	virtual void spellThrouw(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

private:


public:


private:
	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

	int m_localeid;

	MapComponent* m_currentMapC;
};

#endif // __MAP_SYSTEM_H__