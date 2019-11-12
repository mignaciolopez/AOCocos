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

	bool Component::getCanWalk()
	{
		return false;
	}

	void Component::setCanWalk(bool w)
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

	int Component::getX()
	{
		return 0.0f;
	}

	int Component::getY()
	{
		return 0.0f;
	}

	void Component::setX(int x)
	{
	}

	void Component::setY(int y)
	{
	}

	cocos2d::TMXTiledMap * Component::getMap()
	{
		return nullptr;
	}

	void Component::setMap(cocos2d::TMXTiledMap * map)
	{
	}

	cocos2d::Layer * Component::getLayer()
	{
		return nullptr;
	}
	void Component::setLayer(cocos2d::Layer* layer3D)
	{
	}

	int Component::getMusic()
	{
		return 0;
	}

	void Component::setMusic(int musicID)
	{
	}

	int Component::getPrevMusic()
	{
		return 0;
	}

	void Component::setPrevMusic(int musicID)
	{
	}

	void Component::addAudio(int audioID)
	{
	}

	void Component::removeAudio(int audioID)
	{
	}

	std::map<int, int>* Component::getAudios()
	{
		return nullptr;
	}

}