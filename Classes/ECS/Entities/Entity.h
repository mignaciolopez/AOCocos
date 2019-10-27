#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <map>
#include <vector>

#include "Components/ComponentsList.h"

#include "ECS/Entities/Entity.h"
#include "ECS/Components/Component.h"

namespace ECS
{
	using ContainerComponents = std::multimap<ComponentType, Component*>;

	class Entity
	{
	public:
		Entity();
		~Entity();

		template <typename COMPONENT>
		inline void AddComponent(COMPONENT* component)
		{
			m_components.emplace(component->_type, component);
		}

		unsigned int GetNumOfComponents();
		std::vector<Component*> GetComponentsOfType(ComponentType type);

	private:

	public:

	private:
		ContainerComponents m_components;

	};
}
#endif // __ENTITY_H__