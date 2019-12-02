#ifndef __COMPONENT_H__
#define __COMPONENT_H__

#include "Components/ComponentsList.h"

#include "cocos2d.h"

//PlayerBodyComponent
enum Direction
{
	INVALID = -1,
	North = 0,
	East,
	South,
	West,
};

enum Genre
{
	Male = 0,
	Female
};

enum Race
{
	Human = 0,
	Dwarf,
	Gnome,
	Elf,
	DarkElf
};

enum Body
{
	Body_Common_Clothes_Green = 1,
	Body_Common_Clothes_Blue,
	Body_Common_Clothes_Red,
	whatsthis
};

enum Head
{
	Head_Male_Human1 = 1
};

enum Shield
{
	Shield_Imperial = 1
};

enum Helmet
{
	Helmet_Iron = 1
};

enum Weapon
{
	Weapon_Sword_Long = 1
};

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

		virtual cocos2d::Sprite* getShieldSpr();
		virtual void setShieldSpr(cocos2d::Sprite* shield);

		virtual cocos2d::Sprite* getHelmetSpr();
		virtual void setHelmetSpr(cocos2d::Sprite* helmet);

		virtual cocos2d::Sprite* getWeaponSpr();
		virtual void setWeaponSpr(cocos2d::Sprite* weapon);

		virtual bool getMoving();
		virtual void setMoving(bool m);

		virtual bool getCanWalk();
		virtual void setCanWalk(bool w);

		virtual bool getAttacking();
		virtual void setAttacking(bool a);

		virtual Direction getDirection();
		virtual void setDirection(Direction dir);

		virtual Race getRace();
		virtual void setRace(Race race);

		virtual Genre getGenre();
		virtual void setGenre(Genre genre);

		virtual Body getBody();
		virtual void setBody(Body body);

		virtual Head getHead();
		virtual void setHead(Head head);

		virtual Shield getShield();
		virtual void setShield(Shield shield);

		virtual Helmet getHelmet();
		virtual void setHelmet(Helmet helmet);

		virtual Weapon getWeapon();
		virtual void setWeapon(Weapon weapon);

		virtual unsigned int getBodyGs(Direction dir);
		virtual void setBodyGs(Direction dir, unsigned int gid);

		virtual unsigned int getHeadGs(Direction dir);
		virtual void setHeadGs(Direction dir, unsigned int gid);

		virtual unsigned int getShieldGs(Direction dir);
		virtual void setShieldGs(Direction dir, unsigned int gid);

		virtual unsigned int getHelmetGs(Direction dir);
		virtual void setHelmetGs(Direction dir, unsigned int gid);

		virtual unsigned int getWeaponGs(Direction dir);
		virtual void setWeaponGs(Direction dir, unsigned int gid);

		virtual cocos2d::Animate* getAnimBody();
		virtual void setAnimBody(Direction dir, cocos2d::Animate* anim);

		virtual cocos2d::Animate* getAnimShield();
		virtual void setAnimShield(Direction dir, cocos2d::Animate* anim);

		virtual cocos2d::Animate* getAnimWeapon();
		virtual void setAnimWeapon(Direction dir, cocos2d::Animate* anim);

		virtual cocos2d::Animate* getAnimBlood();
		virtual void setAnimBlood(cocos2d::Animate* anim);

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
