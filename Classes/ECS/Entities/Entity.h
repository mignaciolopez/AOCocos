#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <map>

#include "Components/ComponentsList.h"

namespace ECS
{
	class Component;

	using ContainerComponents = std::multimap<ComponentType, Component*>;

	class Entity
	{
	public:
		Entity();
		~Entity();

		void AddComponent(ComponentType componentID, Component* component);
		unsigned int GetNumOfComponents();

	private:

	public:

	private:
		ContainerComponents m_components;

	};
}
#endif // __ENTITY_H__