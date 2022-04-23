#ifndef LEVEL_COMPONENT_H__
#define LEVEL_COMPONENT_H__

#include "Components/Enums.h"

#include "Enums.h"

class LevelComponent
{
public:
	LevelComponent()
	{
		ECS_Log::s_consoleL->trace("[LevelComponent] Constructor");


	}

	~LevelComponent()
	{
		ECS_Log::s_consoleL->trace("[LevelComponent] Destructor");
	}

	float _percent;
	int _level;
	int _exp;
	int _maxExp;
};

#endif // !LEVEL_COMPONENT_H__
