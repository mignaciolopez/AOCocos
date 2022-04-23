#ifndef INVENTORY_COMPONENT_H__
#define INVENTORY_COMPONENT_H__

#include "Components/Enums.h"

#include "ECS/ECS_Log.h"

//#include "Enums.h"

class InventoryComponent
{
public:
	InventoryComponent()
	{
		ECS_Log::s_consoleL->trace("[InventoryComponent] Constructor");
		for (int i = 0; i < 25; i++)
			_inventory[i] = nullptr;
		
	}

	~InventoryComponent()
	{
		ECS_Log::s_consoleL->trace("[InventoryComponent] Destructor");
	}

	struct Item
	{
		Items _itemType;
		int _col;
		int _row;
		uint16_t _quantity;
	};

	 Item* _inventory[25];
};

#endif // !INVENTORY_COMPONENT_H__
