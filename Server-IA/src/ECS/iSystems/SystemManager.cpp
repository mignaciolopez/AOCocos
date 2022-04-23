#include "SystemManager.h"

namespace ECS
{

	SystemManager::SystemManager()
	{
		ECS_Log::s_consoleL->trace("[SystemManager] Constructor");
	}

	SystemManager::~SystemManager()
	{
		ECS_Log::s_consoleL->trace("[SystemManager] Destructor");

		int count = 0;
		for (auto& system : m_systems)
		{
			count++;
			delete system.second;
			system.second = nullptr;
		}

		ECS_Log::s_consoleL->debug("[SystemManager] deleted systems: {0:d} of {0:d}", count, m_systems.size());
	}

	void SystemManager::update(double dt)
	{
		for (auto system : m_systems)
		{
			system.second->update(dt);
		}
	}

	void SystemManager::unRegisterSystem(iSystemTags iSysTag, bool cleanUp)
	{
		ECS_Log::s_consoleL->trace("[SystemManager] unRegisterSystem() iSysTag: {0:d}", (int)iSysTag);
		if (m_systems.find(iSysTag) != m_systems.end())
		{
			if (cleanUp && m_systems.at(iSysTag))
			{
				delete m_systems.at(iSysTag);
				m_systems.at(iSysTag) = nullptr;
				ECS_Log::s_consoleL->debug("[SystemManager] deleted iSysTag: {0:d}", (int)iSysTag);
			}

			m_systems.erase(iSysTag);
		}
	}

	iSystem * SystemManager::getSystem(iSystemTags iSysTag)
	{
		if (m_systems.find(iSysTag) != m_systems.end())
		{
			ECS_Log::s_consoleL->debug("[SystemManager] getSystem() found iSysTag: {0:d}", (int)iSysTag);
			return m_systems.at(iSysTag);
		}

		ECS_Log::s_consoleL->error("[SystemManager] getSystem() not found iSysTag: {0:d}", (int)iSysTag);
		return nullptr;
	}
}