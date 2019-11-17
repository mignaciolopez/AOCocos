#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "Components/ComponentsList.h"

#include "cocos2d.h"

//PlayerBodyComponent
enum Direction;
enum Genre;
enum Race;
enum Head;

//Inventory
struct slot
{
	short id;
	bool equiped;
	unsigned short quantity;
	std::string name;
	cocos2d::Vec2 pos;
};

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
		virtual void setX(int x);
		virtual int getY();
		virtual void setY(int y);
		virtual Direction getNextMove();
		virtual void setNextMove(Direction dir);
		virtual void removeFirstMove();

		//MapComponent
		virtual cocos2d::TMXTiledMap* getMap();
		virtual void setMap(cocos2d::TMXTiledMap* map);

		//Layer3D
		virtual cocos2d::Layer* getLayer();
		virtual void setLayer(cocos2d::Layer* layer3D);

		//Audio
		virtual int getMusic();
		virtual void setMusic(int musicID);
		virtual int getPrevMusic();
		virtual void setPrevMusic(int musicID);
		virtual void addAudio(int audioID);
		virtual void removeAudio(int audioID);
		virtual std::map<int, int>* getAudios();
		virtual int getAeid();
		virtual void setAeid(int aeid);

		//Inventory
		virtual slot* getSlot(int slotIndex);
		virtual void setid(int slotIndex, int id);
		virtual void setEquiped(int slotIndex, bool equiped);
		virtual void setQuantity(int slotIndex, int quantity);
		virtual void setName(int slotIndex, std::string name);
		virtual void setPosition(int slotIndex, cocos2d::Vec2 pos);
		virtual void setPosition(int slotIndex, int x, int y);

	private:
		const ComponentType m_type = ComponentType::NONE;
	};

}
#endif // __COMPONENT_H__
