#include "SystemManager.h"

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
		for (auto& system : m_systems)
		{
			delete system.second;
			system.second = nullptr;
		}
#if _DEBUG
		cocos2d::log("%s Destructor", LOGID);
#endif
	}

	void SystemManager::update(float dt)
	{
		for (auto& system : m_systems)
		{
			system.second->update(dt);
		}
	}

	void SystemManager::unRegisterSystem(iSystemTags iSysTag, bool cleanUp)
	{
		if (m_systems.find(iSysTag) != m_systems.end())
		{
			if (cleanUp && m_systems.at(iSysTag))
			{
				delete m_systems.at(iSysTag);
				m_systems.at(iSysTag) = nullptr;
			}

			m_systems.erase(iSysTag);
		}
	}

	iSystem * SystemManager::getSystem(iSystemTags iSysTag)
	{
		if (m_systems.find(iSysTag) != m_systems.end())
			return m_systems.at(iSysTag);

		return nullptr;
	}
}