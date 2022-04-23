#ifndef INVENTORY_SYSTEM_H__
#define INVENTORY_SYSTEM_H__

#include "ECS/SignalsManager.h"
#include "ECS/SignalsList.h"
#include "entt.hpp"

#include "ECS/iSystems/iSystem.h"

#include "Components/IncludeComponents.h"

#include "ECS/ECS_Log.h"

class InventorySystem : public ECS::iSystem
{
public:
	const ECS::iSystemTags _tag = ECS::iSystemTags::InventorySystem_tag;
	InventorySystem(entt::registry* registry);
	~InventorySystem();

	virtual void update(double dt) override;

	void onConstructInventoryC(entt::registry& registry, entt::entity entity);
	void onDestroyInventoryC(entt::registry& registry, entt::entity entity);

	void inventorySync(entt::entity entity, SLNet::BitStream* bs);
	void inventoryUse(entt::entity entity, SLNet::BitStream* bs);
	void graphicsReload(entt::entity entity, SLNet::BitStream* bs);

private:
	std::shared_ptr<ECS::SignalsManager> m_signalsManager;
	entt::registry* m_registry;

	entt::entity m_localEntt = entt::null;
};

#endif // !INVENTORY_SYSTEM_H__