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
#if _DEBUG
		cocos2d::log("%s Destructor", "[POSITION COMPONENT]");
#endif
	}

	virtual ComponentType getType() override
	{
		return m_type;
	}
	
	virtual int getX() override
	{
		return m_x;
	}
	virtual void setX(int x) override
	{
		m_x = x;
	}

	virtual int getY() override
	{
		return m_y;
	}
	virtual void setY(int y) override
	{
		m_y = y;
	}

	virtual Direction getNextMove() override
	{
		Direction dir = Direction::INVALID;
		if (m_pendingMoves.size() > 0)
		{
			dir = m_pendingMoves[0];
		}
		return dir;
	}
	virtual void setNextMove(Direction dir) override
	{
		m_pendingMoves.push_back(dir);
	}
	virtual void removeFirstMove() override
	{
		m_pendingMoves.erase(m_pendingMoves.begin());
	}

private:
	const ComponentType m_type = ComponentType::POSITION;
	int m_x, m_y;
	std::vector<Direction> m_pendingMoves;
};

#endif // __SPRITE_COMPONENT_H__
