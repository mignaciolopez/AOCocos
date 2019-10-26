#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

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

	private:
		unsigned int m_id;
		ContainerEntity m_entities;

	};
}
#endif // __ENTITY_MANAGER_H__