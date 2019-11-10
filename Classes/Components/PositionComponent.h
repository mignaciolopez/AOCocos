#ifndef __POSITION_COMPONENT_H__
#define __POSITION_COMPONENT_H__

#include "ECS/Components/Component.h"

class PositionComponent : public ECS::Component
{
public:
	PositionComponent(int x, int y)
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
	
	virtual int getX() override
	{
		return m_x;
	}
	virtual int getY() override
	{
		return m_y;
	}

	virtual void setX(int x) override
	{
		m_x = x;
	}
	virtual void setY(int y) override
	{
		m_y = y;
	}

private:
	const ComponentType m_type = ComponentType::POSITION;
	int m_x, m_y;
};

#endif // __SPRITE_COMPONENT_H__
