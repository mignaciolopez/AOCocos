#include "Component.h"

#include "Components/IncludeComponents.h"

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
#if _DEBUG
		cocos2d::log("%s Destructor", LOGID);
#endif
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

	cocos2d::Sprite * Component::getShieldSpr()
	{
		return nullptr;
	}

	void Component::setShieldSpr(cocos2d::Sprite * shield)
	{
	}

	cocos2d::Sprite * Component::getHelmetSpr()
	{
		return nullptr;
	}

	void Component::setHelmetSpr(cocos2d::Sprite * helmet)
	{
	}

	cocos2d::Sprite * Component::getWeaponSpr()
	{
		return nullptr;
	}

	void Component::setWeaponSpr(cocos2d::Sprite * weapon)
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

	bool Component::getAttacking()
	{
		return false;
	}

	void Component::setAttacking(bool a)
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

	Body Component::getBody()
	{
		return Body();
	}

	void Component::setBody(Body body)
	{
	}

	Head Component::getHead()
	{
		return Head();
	}

	void Component::setHead(Head head)
	{
	}

	Shield Component::getShield()
	{
		return Shield();
	}

	void Component::setShield(Shield shield)
	{
	}

	Helmet Component::getHelmet()
	{
		return Helmet();
	}

	void Component::setHelmet(Helmet helmet)
	{
	}

	Weapon Component::getWeapon()
	{
		return Weapon();
	}

	void Component::setWeapon(Weapon weapon)
	{
	}

	unsigned int Component::getBodyGs(Direction dir)
	{
		return 0;
	}

	void Component::setBodyGs(Direction dir, unsigned int gid)
	{
	}

	unsigned int Component::getHeadGs(Direction dir)
	{
		return 0;
	}

	void Component::setHeadGs(Direction dir, unsigned int gid)
	{
	}

	unsigned int Component::getShieldGs(Direction dir)
	{
		return 0;
	}

	void Component::setShieldGs(Direction dir, unsigned int gid)
	{
	}

	unsigned int Component::getHelmetGs(Direction dir)
	{
		return 0;
	}

	void Component::setHelmetGs(Direction dir, unsigned int gid)
	{
	}

	unsigned int Component::getWeaponGs(Direction dir)
	{
		return 0;
	}

	void Component::setWeaponGs(Direction dir, unsigned int gid)
	{
	}

	cocos2d::Animate * Component::getAnimBody()
	{
		return nullptr;
	}

	void Component::setAnimBody(Direction dir, cocos2d::Animate * anim)
	{
	}

	cocos2d::Animate * Component::getAnimShield()
	{
		return nullptr;
	}

	void Component::setAnimShield(Direction dir, cocos2d::Animate * anim)
	{
	}

	cocos2d::Animate * Component::getAnimWeapon()
	{
		return nullptr;
	}

	void Component::setAnimWeapon(Direction dir, cocos2d::Animate * anim)
	{
	}

	cocos2d::Animate * Component::getAnimBlood()
	{
		return nullptr;
	}

	void Component::setAnimBlood(cocos2d::Animate * anim)
	{
	}

	//PositionComponent
	int Component::getX()
	{
		return 0.0f;
	}

	void Component::setX(int x)
	{
	}

	int Component::getY()
	{
		return 0.0f;
	}

	void Component::setY(int y)
	{
	}

	Direction Component::getNextMove()
	{
		return Direction::INVALID;
	}

	void Component::setNextMove(Direction dir)
	{
	}

	void Component::removeFirstMove()
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

	int Component::getAeid()
	{
		return -1;
	}
	void ECS::Component::setAeid(int aeid)
	{
	}

	//Inventory
	slot * Component::getSlot(int slotIndex)
	{
		return nullptr;
	}

	void Component::setid(int slotIndex, int id)
	{
	}

	void Component::setEquiped(int slotIndex, bool equiped)
	{
	}

	void Component::setQuantity(int slotIndex, int quantity)
	{
	}

	void Component::setName(int slotIndex, std::string name)
	{
	}

	void Component::setPosition(int slotIndex, cocos2d::Vec2 pos)
	{
	}

	void Component::setPosition(int slotIndex, int x, int y)
	{
	}

}