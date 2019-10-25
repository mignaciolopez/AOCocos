#pragma once

#include <map>

using ContainerEntity = std::map<unsigned int, unsigned int>;
//The second unsigned int will be user later to find faster the network id

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	unsigned int CreateEntity();

private:
	unsigned int m_id;
	ContainerEntity m_entities;
};

