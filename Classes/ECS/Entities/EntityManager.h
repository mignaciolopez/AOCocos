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

		bool CreateEntity(int eid);

		Entity* getEntity(int id);
		ContainerEntity* getEntities();

		void removeEntity(int eid);

		template <typename C>
		inline void AddComponentToEntity(int eid, C* component)
		{
			if (m_components.find(eid) != m_components.end())
			{
				if (m_components.at(eid)->find(component->getType()) == m_components.at(eid)->end())
					m_components.at(eid)->emplace(component->getType(), component);
			}
		}

		Component* getComp(int eid, ComponentType type);

		/*template <typename C>*/
		/*inline C* TgetComp(int eid, ComponentType type, C* c)
		{
			if (m_components.find(eid) != m_components.end())
			{
				if (m_components.at(eid)->find(type) != m_components.at(eid)->end())
					return dynamic_cast<C*>(m_components.at(eid)->at(type));
			}
			return nullptr;
		}*/

		void removeComponent(int eid, ComponentType type, bool cleanup = true);

	private:
		ContainerEntity m_entities;

		using ContainerComponents = std::map<int, std::map<ComponentType, Component*>*>;
		ContainerComponents m_components;

	};
}
#endif // __ENTITY_MANAGER_H__