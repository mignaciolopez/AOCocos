#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include "Components/ComponentsList.h"

#include "ECS/Entities/Entity.h"
#include "ECS/Components/Component.h"

#include <map>
#include <vector>

namespace ECS
{
	using ContainerEntity = std::map<unsigned int, Entity*>;

	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();

		unsigned int CreateEntity();
		
		template <typename COMPONENT>
		inline void AddComponentTo(unsigned int entityID, COMPONENT* component)
		{
			if (m_entities.find(entityID) != m_entities.end())
			{
				m_entities.at(entityID)->AddComponent(component);
			}
		}

		ContainerEntity* GetEntities();

		std::vector<Entity*> GetEntitiesWithComponent(ComponentType type);

	private:
		unsigned int m_id;
		ContainerEntity m_entities;

	};
}
#endif // __ENTITY_MANAGER_H__