#ifndef HUD_DEBUG_COMPONENT_H__
#define HUD_DEBUG_COMPONENT_H__

#include "cocos2d.h"
#include "Scenes/DrawNode3D.h"

class HudDebugComponent final
{
public:
	HudDebugComponent()
	{
#ifdef _DEBUG
		cocos2d::log("[HudDebugComponent] Constructor");
#endif
		
	}

	~HudDebugComponent()
	{
#ifdef _DEBUG
		cocos2d::log("[HudDebugComponent] Destructor");
#endif		
	}

	cocos2d::Node* _hudDebugNode;

	//GRID
	cocos2d::DrawNode3D* _grid;

	//LABELS
	cocos2d::Label* _lblNetwork;

	cocos2d::Node* _nodeBodyInfo;
	cocos2d::Label* _lblBody;
	cocos2d::Label* _lblHead;
	cocos2d::Label* _lblShield;
	cocos2d::Label* _lblHelmet;
	cocos2d::Label* _lblWeapon;
	
};

#endif // !HUD_DEBUG_COMPONENT_H__