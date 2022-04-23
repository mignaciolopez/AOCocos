#ifndef INTERVAL_COMPONENT_H__
#define INTERVAL_COMPONENT_H__

#include "Components/Enums.h"

#include "ECS/ECS_Log.h"

class IntervalComponent
{
public:
	IntervalComponent()
	{

		ECS_Log::s_consoleL->trace("[IntervalComponent] Constructor");

	}

	~IntervalComponent()
	{

		ECS_Log::s_consoleL->trace("[IntervalComponent] Destructor");
	}

	double _dtLastAttack = 0.0;
	double _constAttack = 1.0;

	double _dtLastCastSpell = 0.0;
	double _constCastSpell = 0.8;
	
	double _dtLastUse = 0.0;
	double _constUse = 0.4;
};

#endif // !INTERVAL_COMPONENT_H__
