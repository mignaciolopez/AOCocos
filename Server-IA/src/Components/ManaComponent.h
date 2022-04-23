#ifndef MANA_COMPONENT_H__
#define MANA_COMPONENT_H__

#include "Components/Enums.h"

#include "ECS/ECS_Log.h"

class ManaComponent
{
public:
	ManaComponent(int mp, int mpMax) : _mp(mp), _mpMax(mpMax)
	{
		ECS_Log::s_consoleL->trace("[ManaComponent] Constructor");


	}

	~ManaComponent()
	{
		ECS_Log::s_consoleL->trace("[ManaComponent] Destructor");	
	}

	float _percent;
	int _mp;
	int _mpMax;

	bool _meditating = false;
};

#endif // !MANA_COMPONENT_H__
