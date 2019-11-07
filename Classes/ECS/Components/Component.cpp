#include "Component.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[COMPONENT]"

	Component::Component()
	{
		cocos2d::log("%s Constructor", LOGID);
	}

	Component::~Component()
	{
		cocos2d::log("%s Destructor", LOGID);
	}

	cocos2d::Sprite * Component::getBody()
	{
		return nullptr;
	}

	void Component::setBody(cocos2d::Sprite * body)
	{
	}

	cocos2d::Sprite * Component::getHead()
	{
		return nullptr;
	}

	void Component::setHead(cocos2d::Sprite * head)
	{
	}

	bool Component::getMoving()
	{
		return false;
	}

	void Component::setMoving(bool m)
	{
	}

	Direction Component::getDirection()
	{
		return Direction();
	}

	void Component::setDirection(Direction dir)
	{
	}

	float Component::getX()
	{
		return 0.0f;
	}

	float Component::getY()
	{
		return 0.0f;
	}

	void Component::setX(float x)
	{
	}

	void Component::setY(float y)
	{
	}

}