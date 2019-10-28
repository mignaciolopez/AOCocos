#ifndef __COMPONENT_MANAGER_H__
#define __COMPONENT_MANAGER_H__

#include <map>
#include <vector>

#include "ECS/Components/Component.h"

#include "cocos2d.h"

namespace ECS
{

	using ContainerComponent = std::map<unsigned int, Component*>;
	using ContainerComponentTypes = std::multimap<ComponentType, unsigned int>;

	class ComponentManager
	{
	public:
		ComponentManager();
		~ComponentManager();

		Component* getComponent(unsigned int id);

		template <typename COMPONENT>
		inline unsigned int storeComponent(COMPONENT* component)
		{
			unsigned int id = getNewID();

			m_components.emplace(id, component);
			m_componentsIndexType.emplace(component->_type, id);

			return id;
		}

		std::vector<unsigned int> getComponentsOfType(ComponentType type);

	private:
		unsigned int getNewID();

	public:

	private:
		ContainerComponent m_components;
		ContainerComponentTypes m_componentsIndexType;

	};
}

#endif // __COMPONENT_MANAGER_H__