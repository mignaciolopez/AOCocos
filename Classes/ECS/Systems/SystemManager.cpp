#include "SystemManager.h"

#include "ECS/Entities/Entity.h"
#include "ECS/Systems/System.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[SYSTEM MANAGER]"

	SystemManager::SystemManager(EventManager* eventManager) : m_eventManager(eventManager)
	{
		cocos2d::log("%s Constructor", LOGID);
	}

	SystemManager::~SystemManager()
	{
		for (auto system : m_systems)
		{
			delete system.second;
			system.second = nullptr;
		}
		cocos2d::log("%s Destructor", LOGID);
	}

	void SystemManager::Update()
	{
		for (auto system : m_systems)
		{
			system.second->Update();
		}
	}

	void SystemManager::unRegisterSystem(int id, bool cleanUp)
	{
		if (m_systems.find(id) != m_systems.end())
		{
			if (cleanUp && m_systems.at(id))
			{
				delete m_systems.at(id);
				m_systems.at(id) = nullptr;
			}

			m_systems.erase(id);
		}
	}

	System * SystemManager::getSystem(int id)
	{
		if (m_systems.find(id) != m_systems.end())
			return m_systems.at(id);

		return nullptr;
	}

	int SystemManager::GetNewID()
	{
		int id = 0;

		while (m_systems.find(id) != m_systems.end())
			++id;

		return id;
	}
}