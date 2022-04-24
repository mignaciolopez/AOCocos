#ifndef INVENTORY_SYSTEM_H__
#define INVENTORY_SYSTEM_H__

#include "cocos2d.h"

#include "ECS/SignalsManager.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Graphics/Graphics.h"

class InventorySystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::InventorySystem_tag;
	InventorySystem(cocos2d::Scene* scene, entt::registry* registry);
	~InventorySystem();

	virtual void update(float dt) override;

	void onConstructInventoryC(entt::registry& registry, entt::entity entity);
	void onDestroyInventoryC(entt::registry& registry, entt::entity entity);

	void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

	void inventorySync(entt::entity entity, SLNet::BitStream* bs);
	void inventoryItemUse(entt::entity entity, SLNet::BitStream* bs);
	void inventoryItemUpdate(entt::entity entity, SLNet::BitStream* bs);

	void graphicsReload(entt::entity entity, SLNet::BitStream* bs);

	bool onTouchBegan(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);
	void onTouchMoved(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);
	void onTouchEnded(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);
	void onTouchCancelled(const cocos2d::Touch* touch, cocos2d::Event* ccEvnt);

private:
	InventoryComponent::Item* createItem(Items itemType, int col, int row, uint16_t quantity);
	void removeItem(int index);

private:
	ECS::SignalsManager* m_signalsManager;
	entt::registry* m_registry;

	cocos2d::Director* m_director;

	cocos2d::Scene* m_scene;

	entt::entity m_localEntt = entt::null;
	Graphics* m_graphics;
};

#endif // !INVENTORY_SYSTEM_H__