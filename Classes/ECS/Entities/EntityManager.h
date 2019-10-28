#ifndef __ENTITY_MANAGER_H__
#define __ENTITY_MANAGER_H__

#include "Components/ComponentsList.h"

#include "ECS/Entities/Entity.h"
#include "ECS/Components/Component.h"

#include <map>
#include <vector>

namespace ECS
{
	using ContainerEntity = std::map<unsigned int, Entity*>;

	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();

		unsigned int CreateEntity();
		
		void AddComponentToEntity(unsigned int entityID, unsigned int componentID);

		Entity* getEntity(unsigned int id);

	private:
		ContainerEntity m_entities;

	};
}
#endif // __ENTITY_MANAGER_H__