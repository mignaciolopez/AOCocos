#include "iSystem.h"

namespace ECS
{

	iSystem::iSystem()
	{
		ECS_Log::s_consoleL->trace("[iSystem] Constructor");
	}

	iSystem::~iSystem()
	{
		ECS_Log::s_consoleL->trace("[iSystem] Destructor");
	}

}