#define _CRTDBG_MAP_ALLOC

#include "ECS/ECS_Engine.h"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>  
#include <crtdbg.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	ECS_Log::init();
	{
		auto ecs = ECS::ECS_Engine::getECSEngine();

		if (!ecs->init())
		{
			ECS_Log::s_consoleL->critical("[main] ECS_Engine init failed!");
			return -1;
		}

		while (ecs->isRunning())
			ecs->update();

		ecs->shutdown();
	}
	ECS_Log::shutdown();

	std::cout << std::endl << std::endl << "Press Enter to exit.";
	std::cin.get();

	return 0;
}