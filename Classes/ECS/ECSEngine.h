#ifndef __ECS_ENGINE_H__
#define __ECS_ENGINE_H__

#include "ECS/Entities/EntityManager.h"
#include "ECS/Systems/SystemManager.h"

namespace ECS
{

	class ECSEngine
	{
	public:
		ECSEngine();
		~ECSEngine();

		void Update();

	private:

	public:
		EntityManager* m_entityManager;
		SystemManager* m_systemManager;

	private:

	};

}

#endif // __ECS_ENGINE_H__