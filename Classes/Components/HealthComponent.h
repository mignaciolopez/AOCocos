#ifndef HEALTH_COMPONENT_H__
#define HEALTH_COMPONENT_H__

#include "Components/Enums.h"

#include "cocos2d.h"

#include "Enums.h"

class HealthComponent
{
public:
	HealthComponent(int hp, int hpMax) : _hp(hp), _hpMax(hpMax)
	{
#if _DEBUG
		cocos2d::log("[HealthComponent] Constructor");
#endif


	}

	~HealthComponent()
	{
#if _DEBUG
		cocos2d::log("[HealthComponent] Destructor");
#endif		
	}

	cocos2d::Node* _node;
	cocos2d::Sprite* _sprBar;
	float _percent;
	int _hp;
	int _hpMax;

	cocos2d::Label* _lblHp;
};

#endif // !HEALTH_COMPONENT_H__
