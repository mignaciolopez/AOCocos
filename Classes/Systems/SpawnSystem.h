#ifndef __SPAWN_SYSTEM_H__
#define __SPAWN_SYSTEM_H__

#include "ECS/ECS_Engine.h"

namespace cocos2d
{
	class Director;
}

class SpawnSystem : public ECS::System
{
public:
	SpawnSystem();
	~SpawnSystem();

	virtual void Update() override;

	void createLocal(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);
	void createRemote(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);
	void createPlayer(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);
	void syncPlayers(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);
	void removePlayer(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);

private:
	void syncCreatePlayer(int eid, float x, float y);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

	const cocos2d::Size m_windowSize = cocos2d::Size(800, 600);
};

#endif // __SPAWN_SYSTEM_H__