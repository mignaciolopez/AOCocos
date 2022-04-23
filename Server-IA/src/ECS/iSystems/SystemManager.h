#ifndef __SYSTEM_MANAGER_H__
#define __SYSTEM_MANAGER_H__

#include "ECS/iSystems/iSystem.h"

#include <map>

#include "ECS/ECS_Log.h"

namespace ECS
{
	using ContainerSystem = std::map<iSystemTags, iSystem*>;

	class SystemManager
	{
	public:
		SystemManager();
		~SystemManager();

		void update(double dt);

		template <typename SYSTEM>
		inline bool RegisterSystem(SYSTEM* system)
		{
			if (m_systems.find(system->_tag) == m_systems.end())
			{
				m_systems.emplace(system->_tag, system);

				return true;
			}

			return false;
		}

		void unRegisterSystem(iSystemTags iSysTag, bool cleanUp = true);

		iSystem* getSystem(iSystemTags iSysTag);

	private:
		ContainerSystem m_systems;

	};
}
#endif // __SYSTEM_MANAGER_H__