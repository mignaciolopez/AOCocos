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

	void SystemManager::unRegisterSystem(unsigned int id, bool cleanUp)
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

	System * SystemManager::getSystem(unsigned int id)
	{
		if (m_systems.find(id) != m_systems.end())
			return m_systems.at(id);

		return nullptr;
	}

	unsigned int SystemManager::GetNewID()
	{
		unsigned int id = 0;

		while (m_systems.find(id) != m_systems.end())
			++id;

		return id;
	}
}