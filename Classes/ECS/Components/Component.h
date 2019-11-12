#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "Components/ComponentsList.h"

#include "cocos2d.h"

//PlayerBodyComponent
enum Direction;
enum Genre;
enum Race;
enum Head;

namespace ECS
{
	class Component
	{
	public:
		Component();
		virtual ~Component();

		virtual ComponentType getType() = 0;

		//PlayerBodyComponent
		virtual cocos2d::Sprite* getBodySpr();
		virtual void setBodySpr(cocos2d::Sprite* body);

		virtual cocos2d::Sprite* getHeadSpr();
		virtual void setHeadSpr(cocos2d::Sprite* head);

		virtual bool getMoving();
		virtual void setMoving(bool m);

		virtual bool getCanWalk();
		virtual void setCanWalk(bool w);

		virtual Direction getDirection();
		virtual void setDirection(Direction dir);

		virtual Race getRace();
		virtual void setRace(Race race);

		virtual Genre getGenre();
		virtual void setGenre(Genre genre);

		virtual Head getHead();
		virtual void setHead(Head head);

		//PositionComponent
		virtual int getX();
		virtual int getY();
		virtual void setX(int x);
		virtual void setY(int y);

		//MapComponent
		virtual cocos2d::TMXTiledMap* getMap();
		virtual void setMap(cocos2d::TMXTiledMap* map);

		//Layer3D
		virtual cocos2d::Layer* getLayer();
		virtual void setLayer(cocos2d::Layer* layer3D);

	private:
		const ComponentType m_type = ComponentType::NONE;
	};

}
#endif // __COMPONENT_H__
