#ifndef INTERVAL_COMPONENT_H__
#define INTERVAL_COMPONENT_H__

#include "Components/Enums.h"

#include "cocos2d.h"

#include "Enums.h"

class IntervalComponent
{
public:
	IntervalComponent()
	{
#if _DEBUG
		cocos2d::log("[IntervalComponent] Constructor");
#endif

	}

	~IntervalComponent()
	{
#if _DEBUG
		cocos2d::log("[IntervalComponent] Destructor");
#endif		
	}

	float _dtLastAttack = 0.0f;
	float _constAttack = 1.0f;

	float _dtLastCastSpell = 0.0f;
	float _constCastSpell = 0.8f;
	
	float _dtLastUse = 0.0f;
	float _constUse = 0.4f;
};

#endif // !INTERVAL_COMPONENT_H__
