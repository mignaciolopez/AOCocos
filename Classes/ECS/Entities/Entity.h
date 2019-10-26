#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <vector>

namespace ECS
{
	class Component;

	using ContainerComponents = std::vector<Component*>;

	class Entity
	{
	public:
		Entity();
		~Entity();

		void AddComponent(Component* component);
		unsigned int GetNumOfComponents();

	private:

	public:

	private:
		ContainerComponents m_components;

	};
}
#endif // __ENTITY_H__