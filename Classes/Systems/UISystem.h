#ifndef __UI_SYSTEM_H__
#define __UI_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "Graphics/Interface.h"

#include "cocos2d.h"

class UISystem : public ECS::System
{
public:
	UISystem(cocos2d::Scene* scene);
	~UISystem();

	virtual void Update() override;

	void setLocaleid(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

	void clicked(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void scroll(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void toogleFullscreen(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void toggleDebugInfo(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void setlblNetwork(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

private:
	void createLabels();

	void createlblPosition();
	void updatelblPosition();

	void createlblNetwork();

	void createInventoryAndSpells();
	void toggleInventory(int x, int y);


private:
	std::vector<ComponentType> m_compatibleComponents;

	ECS::EntityManager* m_entityManager;
	ECS::EventManager* m_eventManager;
	cocos2d::Director* m_director;
	cocos2d::SpriteFrameCache* sfCache;

	cocos2d::Scene* m_scene;

	const cocos2d::Size m_windowSize = cocos2d::Size(800, 600);

	int m_localeid;

	cocos2d::Layer* m_layer;

	bool m_showDebug;

	//LABELS
	cocos2d::Label* m_lblPosition;
	cocos2d::Label* m_lblNetwork;

	//SPRITES
	cocos2d::Sprite* m_sprInventory;
	cocos2d::Sprite* m_sprSpells;
};

#endif // __UI_SYSTEM_H__