#ifndef POSITION_COMPONENT_H__
#define POSITION_COMPONENT_H__

#include "Components/Enums.h"

#include "ECS/ECS_Log.h"

class PositionComponent final
{
public:
	PositionComponent(int mapID, int x, int y) 
		: _mapID(mapID), _x(x), _y(y)
	{
		ECS_Log::s_consoleL->trace("[PositionComponent] Constructor");
		_moving = false;
		_canWalk = true;
	}

	~PositionComponent()
	{
		ECS_Log::s_consoleL->trace("[PositionComponent] Destructor");
	}
		int _mapID;
		int _x;
		int _y;

		bool _moving;
		bool _canWalk;
};
#endif // !POSITION_COMPONENT_H__
