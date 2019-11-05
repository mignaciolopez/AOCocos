#ifndef __ECS_ENGINE_H__
#define __ECS_ENGINE_H__

#include "ECS/Entities/EntityManager.h"
#include "ECS/Systems/SystemManager.h"
#include "ECS/EventManager.h"

namespace ECS
{

	class ECSEngine
	{
	public:
		ECSEngine();
		~ECSEngine();

		static ECSEngine* GetInstance();
		static void DestroyInstance();

		void Update();

		EntityManager* GetEntityManager();
		SystemManager* GetSystemManager();
		EventManager* getEventManager();

	private:

	public:

	private:
		EntityManager* m_entityManager;
		EventManager* m_eventManager;
		SystemManager* m_systemManager;

	};

}

#endif // __ECS_ENGINE_H__