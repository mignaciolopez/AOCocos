#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include "Components/ComponentsList.h"

#include <map>

namespace ECS
{
	class Entity;
	class Component;

	using ContainerEntity = std::map<unsigned int, Entity*>;

	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();

		unsigned int CreateEntity();
		void AddComponentTo(unsigned int entityID, Component* component);
		ContainerEntity* GetEntities();

		ContainerEntity m_entities;
	private:
		unsigned int m_id;

	};
}
#endif // __ENTITY_MANAGER_H__