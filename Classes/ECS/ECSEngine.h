#ifndef __ECS_ENGINE_H__
#define __ECS_ENGINE_H__

#include "ECS/Entities/EntityManager.h"
#include "ECS/Systems/SystemManager.h"
#include "ECS/Components/ComponentManager.h"

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
		ComponentManager* GetComponentManager();

	private:

	public:

	private:
		EntityManager* m_entityManager;
		SystemManager* m_systemManager;
		ComponentManager* m_componentManager;

	};

}

#endif // __ECS_ENGINE_H__