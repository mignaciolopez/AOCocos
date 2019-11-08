#ifndef __ANIMATION_SYSTEM_H__
#define __ANIMATION_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "cocos2d.h"

struct animationInfo
{
public:
	int tagN;
	int tagE;
	int tagS;
	int tagW;
	std::string animationName;

	std::string m_bodyNameNorth;
	std::string m_bodyNameEast;
	std::string m_bodyNameSouth;
	std::string m_bodyNameWest;

	std::string m_headNameNorth;
	std::string m_headNameEast;
	std::string m_headNameSouth;
	std::string m_headNameWest;

	cocos2d::Animate* m_animationNorth = nullptr;
	cocos2d::Animate* m_animationEast = nullptr;
	cocos2d::Animate* m_animationSouth = nullptr;
	cocos2d::Animate* m_animationWest = nullptr;
};

class AnimationSystem : public ECS::System
{
public:
	AnimationSystem();
	~AnimationSystem();

	virtual void Update() override;

	void animate(int eid, cocos2d::Event*, SLNet::BitStream* bs);
	void loadAnimationInfo(int eid, cocos2d::Event*, SLNet::BitStream* bs);
	void removeInfo(int eid, cocos2d::Event*, SLNet::BitStream* bs);

	void setBodyCF(int eid);

private:
	int newTag();

	void constructDirectionName(Direction dir);
	void constructBodyName(int eid);
	void constructHeadName(int eid);
	void constructAnimation(int eid, Direction dir, animationInfo* animInfo);

	void setBody(int eid);
	void setHead(int eid);

public:

private:
	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;
	cocos2d::SpriteFrameCache* m_sfCache;

	std::map<int, animationInfo*> m_animations;

	const float m_NS = 0.04f;
	const float m_EW = 0.05f;

	std::string m_dirName;
	std::string m_bodyName;
	std::string m_headName;

	//Indexado de animaciones
	enum Items
	{
		TURTLE,
		GOLD,
		SPELL,
		ARMOR_LEATHER,
		ARMOR_IRON,
		TUNIC_MAGE,
		TUNIC_
		//etc (small one)
	};
	std::map<Items, std::map<Direction, cocos2d::Animate*>> m_indexAnimatios;

	//Indexado de Graphicos
	enum ItemsType
	{
		SHIELD,
		CLOTHES,
		ARMOR,
		TUNIC
		//etc (huge one)
	};
	std::map<Items, std::string> m_itemsDiccionary;
	std::map<ItemsType, std::string> m_itemsTypeDiccionary;
	//switch para el contruido del nombre para cargar el spriteframeName
	enum ItemOrientation
	{
		NORTH,
		EAST,
		SOUTH,
		WEST,
		INVENTORY
	};
	std::map<Items, std::map<ItemOrientation, cocos2d::Sprite*>> m_itemsSprites;

	//crear un mapa de slots de inventario
	//con la posision que la sprite tiene que tener segun el slot
	//el item
	//el estado (equipado o no) - bool equiped = true/false
	//Hacerlo component o systema no lo se (sistema requiere de eventos para comunicarse
};

#endif //__ANIMATION_SYSTEM_H__