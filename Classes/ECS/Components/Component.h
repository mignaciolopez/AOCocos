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

		virtual Direction getDirection();
		virtual void setDirection(Direction dir);

		virtual Race getRace();
		virtual void setRace(Race race);

		virtual Genre getGenre();
		virtual void setGenre(Genre genre);

		virtual Head getHead();
		virtual void setHead(Head head);

		//PositionComponent
		virtual float getX();
		virtual float getY();
		virtual void setX(float x);
		virtual void setY(float y);

		//MapComponent
		virtual cocos2d::experimental::TMXTiledMap* getMap();
		virtual void setMap(cocos2d::experimental::TMXTiledMap* map);

	private:
		const ComponentType m_type = ComponentType::NONE;
	};

}
#endif // __COMPONENT_H__
