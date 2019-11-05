#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <map>
#include <vector>

#include "../../ECS/Components/Component.h"

namespace ECS
{
	using ContainerComponents = std::multimap<ComponentType, Component*>;

	class Entity
	{
	public:
		Entity(int id);
		~Entity();

		template <typename COMPONENT>
		inline void AddComponent(COMPONENT* component)
		{
			m_components.emplace(component->_type, component);
		}

		int GetNumOfComponents();

		std::vector<Component*> getComponents();
		std::vector<Component*> getComponents(ComponentType type);

	private:

	public:
		ContainerComponents m_components;

	private:
		int m_id;
	};
}
#endif // __ENTITY_H__