#pragma once

#include <map>

#include "ECS/Entity.h"

using ContainerEntity = std::map<unsigned int, Entity*>;

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	unsigned int CreateEntity();
	void AddComponentTo(unsigned int entityID, void* component);

private:
	unsigned int m_id;
	ContainerEntity m_entities;

};
