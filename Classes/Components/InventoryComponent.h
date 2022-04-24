#ifndef INVENTORY_COMPONENT_H__
#define INVENTORY_COMPONENT_H__

#include "Components/Enums.h"

#include "cocos2d.h"

#include "Enums.h"

class InventoryComponent
{
public:
	InventoryComponent()
	{
#if _DEBUG
		cocos2d::log("[InventoryComponent] Constructor");
#endif
		for (int i = 0; i < 25; i++)
			_inventory[i] = nullptr;
		
	}

	~InventoryComponent()
	{
#if _DEBUG
		cocos2d::log("[InventoryComponent] Destructor");
#endif		
	}

	struct Item
	{
		Items itemType;
		int _col;
		int _row;
		cocos2d::Sprite* _sprite;
		cocos2d::Label* _labelQuantity;
		cocos2d::Label* _displayName;
		uint16_t _quantity;
		cocos2d::EventListenerTouchOneByOne* _touchListener;
	};

	Item* _inventory[25];

	std::pair<int, int> _selected; //col, row

	cocos2d::Node* _node;
	cocos2d::Size _size = cocos2d::Size(166, 181);
	cocos2d::Vec2 _pos = cocos2d::Vec2(593, 257);

	cocos2d::DrawNode* _yellowSquare;
};

#endif // !INVENTORY_COMPONENT_H__
