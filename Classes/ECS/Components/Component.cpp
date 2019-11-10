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

	cocos2d::Sprite * Component::getBodySpr()
	{
		return nullptr;
	}

	void Component::setBodySpr(cocos2d::Sprite * body)
	{
	}

	cocos2d::Sprite * Component::getHeadSpr()
	{
		return nullptr;
	}

	void Component::setHeadSpr(cocos2d::Sprite * head)
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

	Race Component::getRace()
	{
		return Race();
	}

	void Component::setRace(Race race)
	{
	}

	Genre Component::getGenre()
	{
		return Genre();
	}

	void Component::setGenre(Genre genre)
	{
	}

	Head Component::getHead()
	{
		return Head();
	}

	void Component::setHead(Head head)
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

	cocos2d::experimental::TMXTiledMap * Component::getMap()
	{
		return nullptr;
	}

	void Component::setMap(cocos2d::experimental::TMXTiledMap * map)
	{
	}

	cocos2d::Layer * Component::getLayer()
	{
		return nullptr;
	}
	void Component::setLayer(cocos2d::Layer* layer3D)
	{
	}

}