#ifndef __POSITION_COMPONENT_H__
#define __POSITION_COMPONENT_H__

#include "ECS/Components/Component.h"

class PositionComponent : public ECS::Component
{
public:
	PositionComponent(float x, float y)
	{
		cocos2d::log("%s Constructor", "[POSITION COMPONENT]");
		_x = x;
		_y = y;
	}
	~PositionComponent()
	{

		cocos2d::log("%s Destructor", "[POSITION COMPONENT]");
	}

	const ComponentType _type = ComponentType::POSITION;
	
	float _x, _y;
};

#endif // __SPRITE_COMPONENT_H__
