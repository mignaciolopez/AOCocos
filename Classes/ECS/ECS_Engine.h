#ifndef __ECS_ENGINE_H__
#define __ECS_ENGINE_H__

#include "ECS/Entities/EntityManager.h"
#include "ECS/Systems/SystemManager.h"
#include "ECS/EventManager.h"

namespace ECS
{

	class ECS_Engine
	{
	public:
		ECS_Engine();
		~ECS_Engine();

		static ECS_Engine* getInstance();
		static void destroyInstance();

		void update();

		EntityManager* getEntityManager();
		SystemManager* getSystemManager();
		EventManager* getEventManager();

		void applicationDidEnterBackground();
		void applicationWillEnterForeground();

	private:

	public:

	private:
		EntityManager* m_entityManager;
		EventManager* m_eventManager;
		SystemManager* m_systemManager;

	};

}

#endif // __ECS_ENGINE_H__