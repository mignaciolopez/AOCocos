#ifndef __ENTITIES_SYSTEM_H__
#define __ENTITIES_SYSTEM_H__

#include "ECS/ECSEngine.h"

namespace cocos2d
{
	class Director;
}

class EntitiesSystem : public ECS::System
{
public:
	EntitiesSystem();
	~EntitiesSystem();

	virtual void Update() override;

	void createEntity(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);
	void sync(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);
	void removeEntity(int eid, cocos2d::Event* ccevent, SLNet::BitStream* bs);

private:
	void createEntity(int eid, float x, float y);

private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;

	const cocos2d::Size m_windowSize = cocos2d::Size(800, 600);
};

#endif // __ENTITIES_SYSTEM_H__