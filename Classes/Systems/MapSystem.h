#ifndef MAP_SYSTEM_H__
#define MAP_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

class MapSystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::MapSystem_tag;
	MapSystem(cocos2d::Scene* scene, entt::registry* registry);
	~MapSystem();

	virtual void update(float dt) override;

	void onConstructMapC(entt::registry& registry, entt::entity entity);
	void onDestroyMapC(entt::registry& registry, entt::entity entity);
	
	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);
	
	void createMapComponent(entt::entity entity, SLNet::BitStream* bs);
	void removeMapComponent(entt::entity entity, SLNet::BitStream* bs);

	void addPlayerToMap(entt::entity entity, SLNet::BitStream* bs);
	void removePlayerFromMap(entt::entity entity, SLNet::BitStream* bs);

	void canMove(entt::entity entity, SLNet::BitStream* bs);

	void toggleDebug(entt::entity entity, SLNet::BitStream* bs);

	//bool onTouchBegan(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);
	//void onTouchMoved(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);
	//void onTouchEnded(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);
	//void onTouchCancelled(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	cocos2d::Director* m_director;
	cocos2d::FileUtils* m_fileUtils;

	cocos2d::Scene* m_scene;

	entt::entity m_localEntt = entt::null;

	cocos2d::EventListenerTouchOneByOne* m_touchListener;

	bool m_showDebug;
};

#endif // !MAP_SYSTEM_H__