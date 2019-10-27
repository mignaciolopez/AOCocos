#include "SystemManager.h"

#include "ECS/Entities/Entity.h"
#include "ECS/Systems/System.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[SYSTEM MANAGER]"

	SystemManager::SystemManager()
	{
		cocos2d::log("%s Constructor", LOGID);
	}

	SystemManager::~SystemManager()
	{
		for (auto system : m_systems)
		{
			delete system;
			system = nullptr;
		}
		cocos2d::log("%s Destructor", LOGID);
	}

	void SystemManager::Update()
	{
		for (auto system : m_systems)
		{
			system->Update();
		}
	}

	void SystemManager::RegisterSystem(System * system)
	{
		m_systems.push_back(system);
	}

}