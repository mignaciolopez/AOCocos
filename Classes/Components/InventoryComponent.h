#ifndef __INVENTORY_COMPONENT_H__
#define __INVENTORY_COMPONENT_H__

#include "ECS/Components/Component.h"

#include "cocos2d.h"

class InventoryComponent : public ECS::Component
{
public:
	InventoryComponent()
	{
#if _DEBUG
		cocos2d::log("%s Constructor", "[INVENTORY COMPONENT]");
#endif
		
		m_maxSlots = 25;
	}

	~InventoryComponent()
	{
#if _DEBUG
		cocos2d::log("%s Destructor", "[INVENTORY COMPONENT]");
#endif
	}

	virtual ComponentType getType() override
	{
		return m_type;
	}	

	virtual slot* getSlot(int slotIndex) override
	{
		if (m_slots.size() > 0)
			return m_slots[slotIndex];

		return nullptr;
	}

	virtual void setid(int slotIndex, int id) override
	{
		if (m_slots[slotIndex])
			m_slots[slotIndex]->id = id;
	}

	virtual void setEquiped(int slotIndex, bool equiped) override
	{
		if (m_slots[slotIndex])
			m_slots[slotIndex]->equiped = equiped;
	}

	virtual void setQuantity(int slotIndex, int quantity) override
	{
		if (m_slots[slotIndex])
			m_slots[slotIndex]->quantity = quantity;
	}

	virtual void setName(int slotIndex, std::string name) override
	{
		if (m_slots[slotIndex])
			m_slots[slotIndex]->name = name;
	}

	virtual void setPosition(int slotIndex, cocos2d::Vec2 pos) override
	{
		if (m_slots[slotIndex])
			m_slots[slotIndex]->pos = pos;
	}

	virtual void setPosition(int slotIndex, int x, int y) override
	{
		if (m_slots[slotIndex])
			m_slots[slotIndex]->pos = cocos2d::Vec2(x, y);
	}

private:
	const ComponentType m_type = ComponentType::INVENTORY;

	std::vector<slot*> m_slots;
	int m_maxSlots;

};
#endif // !__INVENTORY_COMPONENT_H__
