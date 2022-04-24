#ifndef MANA_COMPONENT_H__
#define MANA_COMPONENT_H__

#include "Components/Enums.h"

#include "cocos2d.h"

#include "Enums.h"

class ManaComponent
{
public:
	ManaComponent(int mp, int mpMax) : _mp(mp), _mpMax(mpMax)
	{
#if _DEBUG
		cocos2d::log("[ManaComponent] Constructor");
#endif


	}

	~ManaComponent()
	{
#if _DEBUG
		cocos2d::log("[ManaComponent] Destructor");
#endif		
	}

	cocos2d::Node* _node;
	cocos2d::Sprite* _sprBar;
	float _percent;
	int _mp;
	int _mpMax;

	cocos2d::Label* _lblMp;

	bool _meditating = false;

	cocos2d::ParticleSystemQuad* _emitter = nullptr;
};

#endif // !MANA_COMPONENT_H__
