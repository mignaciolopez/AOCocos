#ifndef POSITION_COMPONENT_H__
#define POSITION_COMPONENT_H__

#include "cocos2d.h"

#include "Components/Enums.h"

class PositionComponent final
{
public:
	PositionComponent(int mapID, int x, int y) : _mapID(mapID), _x(x), _y(y)
	{
#if _DEBUG
		cocos2d::log("[PositionComponent] Constructor");
#endif
		_moving = false;
		_canWalk = true;
		_renocking = false;
	}

	~PositionComponent()
	{
#if _DEBUG
		cocos2d::log("[PositionComponent] Destructor");
#endif
	}
		int _mapID;
		int _x;
		int _y;
		std::vector<Directions> _pendingMoves;

		bool _moving;
		bool _canWalk;
		bool _renocking;
};
#endif // !POSITION_COMPONENT_H__
