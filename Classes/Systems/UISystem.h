#ifndef __UI_SYSTEM_H__
#define __UI_SYSTEM_H__

#include "ECS/ECS_Engine.h"

#include "Graphics/Interface.h"

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class UISystem : public ECS::System, 
	public cocos2d::extension::TableViewDataSource, 
	public cocos2d::extension::TableViewDelegate
{
public:
	UISystem(cocos2d::Scene* scene);
	~UISystem();

	virtual void update(float dt) override;

	void setLocaleid(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);

	void clicked(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void released(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void scroll(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void toogleFullscreen(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void toggleDebugInfo(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void setlblNetwork(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);
	void toggleVSync(int eid, cocos2d::Event* ccevnt, SLNet::BitStream* bs);


	virtual void scrollViewDidScroll(cocos2d::extension::ScrollView* view)override {};
	virtual void scrollViewDidZoom(cocos2d::extension::ScrollView* view)override {}
	virtual void tableCellTouched(cocos2d::extension::TableView* table, cocos2d::extension::TableViewCell* cell)override;
	virtual cocos2d::Size tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx)override;
	virtual cocos2d::extension::TableViewCell* tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)override;
	virtual ssize_t numberOfCellsInTableView(cocos2d::extension::TableView *table)override;


private:
	void createLabels();

	void createlblPosition();
	void updatelblPosition();

	void createlblNetwork();

	void createInventoryAndSpells();
	void toggleInventory(int x, int y);
	void castSpell(int x, int y);

	void createTableSpells();

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
	bool m_vsync;

	//LABELS
	cocos2d::Label* m_lblPosition;
	cocos2d::Label* m_lblNetwork;

	//SPRITES
	cocos2d::Sprite* m_sprInventory;
	cocos2d::Sprite* m_sprSpells;

	cocos2d::extension::TableView* m_tableSpells;
	int m_spellSelected;
	bool m_spellCasted;
};

#endif // __UI_SYSTEM_H__