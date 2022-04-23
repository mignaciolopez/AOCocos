#ifndef __ECS_ENGINE_H__
#define __ECS_ENGINE_H__

#include <chrono>

#include "ECS/SignalsManager.h"
#include "ECS/SignalsList.h"
#include "ECS/iSystems/SystemManager.h"
#include "entt.hpp"

#include "ECS_Log.h"

namespace ECS
{

	class ECS_Engine
	{
	public:
		ECS_Engine();
		~ECS_Engine();

		bool init();
		void shutdown();

		void update();

		static std::shared_ptr<ECS_Engine>& getECSEngine();

		bool isRunning();

	private:

	public:

	private:
		static std::shared_ptr<ECS_Engine> s_ecs_Engine;

		entt::registry* m_registry;

		std::shared_ptr<SignalsManager> m_signalsManager;

		ECS::SystemManager* m_systemManager;

		bool m_running;

		std::chrono::duration<double> m_dt;
		std::chrono::steady_clock::time_point m_start;
		std::chrono::steady_clock::time_point m_end;
	};

}

#endif // __ECS_ENGINE_H__