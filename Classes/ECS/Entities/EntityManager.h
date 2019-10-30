#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include "ECS/Entities/Entity.h"
#include "ECS/Components/Component.h"

#include <map>
#include <vector>

namespace ECS
{
	using ContainerEntity = std::map<unsigned int, Entity*>;

	class ComponentManager;

	class EntityManager
	{
	public:
		EntityManager(ComponentManager* componentManager);
		~EntityManager();

		unsigned int CreateEntity();
		
		template <typename COMPONENT>
		inline unsigned int AddComponentToEntity(unsigned int entityID, COMPONENT* component)
		{
			unsigned int compID = m_componentManager->storeComponent(component);

			if (m_entities.find(entityID) != m_entities.end())
			{
				m_entities.at(entityID)->AddComponent(compID);
			}

			return compID;
		}

		Entity* getEntity(unsigned int id);

	private:
		ContainerEntity m_entities;
		ComponentManager* m_componentManager;

	};
}
#endif // __ENTITY_MANAGER_H__