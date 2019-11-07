#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "Components/ComponentsList.h"

#include "cocos2d.h"

enum Direction;

namespace ECS
{
	class Component
	{
	public:
		Component();
		virtual ~Component();

		virtual ComponentType getType() = 0;

		//PlayerBodyComponent
		virtual cocos2d::Sprite* getBody();
		virtual void setBody(cocos2d::Sprite* body);

		virtual cocos2d::Sprite* getHead();
		virtual void setHead(cocos2d::Sprite* head);

		virtual bool getMoving();
		virtual void setMoving(bool m);

		virtual Direction getDirection();
		virtual void setDirection(Direction dir);

		//PositionComponent
		virtual float getX();
		virtual float getY();
		virtual void setX(float x);
		virtual void setY(float y);

	private:
		const ComponentType m_type = ComponentType::NONE;
	};

}
#endif // __COMPONENT_H__
