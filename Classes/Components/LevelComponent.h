#ifndef LEVEL_COMPONENT_H__
#define LEVEL_COMPONENT_H__

#include "Components/Enums.h"

#include "cocos2d.h"

#include "Enums.h"

class LevelComponent
{
public:
	LevelComponent()
	{
#if _DEBUG
		cocos2d::log("[LevelComponent] Constructor");
#endif


	}

	~LevelComponent()
	{
#if _DEBUG
		cocos2d::log("[LevelComponent] Destructor");
#endif		
	}

	cocos2d::Sprite* _sprBar;
	float _percent;
	int _level;
	int _exp;
	int _maxExp;

	cocos2d::Label* _lblLevel;
	cocos2d::Label* _lblPercent;
	cocos2d::Label* _lblCurrentMax;
};

#endif // !LEVEL_COMPONENT_H__
