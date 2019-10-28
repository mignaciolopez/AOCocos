#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <vector>

#include "Components/ComponentsList.h"

#include "ECS/Entities/Entity.h"
#include "ECS/Components/Component.h"

namespace ECS
{
	using ContainerComponents = std::vector<unsigned int>;

	class Entity
	{
	public:
		Entity(unsigned int id);
		~Entity();

		void AddComponent(unsigned int id);

		unsigned int GetNumOfComponents();

		std::vector<unsigned int> GetComponents();
		std::vector<unsigned int> GetComponents(ComponentType type);

	private:

	public:
		ContainerComponents m_components;

	private:
		unsigned int m_id;
	};
}
#endif // __ENTITY_H__