#ifndef __SYSTEM_MANAGER_H__
#define __SYSTEM_MANAGER_H__

#include <map>

namespace ECS
{
	class System;

	using ContainerSystem = std::map<unsigned int, System*>;

	class SystemManager
	{
	public:
		SystemManager();
		~SystemManager();

		void Update();

		template <typename SYSTEM>
		inline unsigned int RegisterSystem(SYSTEM* system)
		{
			unsigned int id = GetNewID();
			m_systems.emplace(id, system);

			return id;
		}

		void unRegisterSystem(unsigned int id, bool cleanUp = true);

		System* getSystem(unsigned int id);

	private:
		unsigned int GetNewID();

	public:

	private:
		ContainerSystem m_systems;

	};
}
#endif // __SYSTEM_MANAGER_H__