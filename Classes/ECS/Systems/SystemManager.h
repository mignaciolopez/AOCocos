#ifndef __SYSTEM_MANAGER_H__
#define __SYSTEM_MANAGER_H__

#include <vector>

namespace ECS
{
	class System;

	using ContainerSystem = std::vector<System*>;

	class SystemManager
	{
	public:
		SystemManager();
		~SystemManager();

		void Update();
		void RegisterSystem(System* system);

	private:

	public:

	private:
		ContainerSystem m_systems;

	};
}
#endif // __SYSTEM_MANAGER_H__