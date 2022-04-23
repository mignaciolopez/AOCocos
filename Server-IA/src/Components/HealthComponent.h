#ifndef HEALTH_COMPONENT_H__
#define HEALTH_COMPONENT_H__

#include "Components/Enums.h"

#include "Enums.h"

class HealthComponent
{
public:
	HealthComponent(int hp, int hpMax) : _hp(hp), _hpMax(hpMax)
	{
		ECS_Log::s_consoleL->trace("[HealthComponent] Constructor");


	}

	~HealthComponent()
	{
		ECS_Log::s_consoleL->trace("[HealthComponent] Destructor");
	}

	int _hp;
	int _hpMax;
};

#endif // !HEALTH_COMPONENT_H__
