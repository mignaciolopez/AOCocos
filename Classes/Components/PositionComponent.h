#ifndef __POSITION_COMPONENT_H__
#define __POSITION_COMPONENT_H__

#include "ECS/Components/Component.h"

class PositionComponent : public ECS::Component
{
public:
	PositionComponent(float x, float y)
	{
		cocos2d::log("%s Constructor", "[POSITION COMPONENT]");
		m_x = x;
		m_y = y;
	}
	~PositionComponent()
	{

		cocos2d::log("%s Destructor", "[POSITION COMPONENT]");
	}

	virtual ComponentType getType() override
	{
		return m_type;
	}
	
	virtual float getX() override
	{
		return m_x;
	}
	virtual float getY() override
	{
		return m_y;
	}

	virtual void setX(float x) override
	{
		m_x = x;
	}
	virtual void setY(float y) override
	{
		m_y = y;
	}

private:
	const ComponentType m_type = ComponentType::POSITION;
	float m_x, m_y;
};

#endif // __SPRITE_COMPONENT_H__
