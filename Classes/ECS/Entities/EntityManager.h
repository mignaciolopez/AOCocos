#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include "ECS/Entities/Entity.h"

#include <map>
#include <vector>

namespace ECS
{
	using ContainerEntity = std::map<int, Entity*>;

	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();

		int CreateEntity();

		template <typename COMPONENT>
		inline void AddComponentToEntity(int eid, COMPONENT* component)
		{
			if (m_entities.find(eid) != m_entities.end())
				m_entities.at(eid)->AddComponent(component);
		}

		Entity* getEntity(int id);
		ContainerEntity* getEntities();

	private:
		ContainerEntity m_entities;

	};
}
#endif // __ENTITY_MANAGER_H__