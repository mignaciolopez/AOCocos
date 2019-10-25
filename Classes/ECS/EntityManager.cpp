#include "EntityManager.h"

EntityManager::EntityManager()
{
	m_id = 0;
}

EntityManager::~EntityManager()
{
}

unsigned int EntityManager::CreateEntity()
{
	m_id = 0;

	while (m_entities.find(m_id) != m_entities.end())
		++m_id;

	Entity* entity = new (std::nothrow) Entity;

	if (entity)
		m_entities.emplace(m_id, entity);
	else
	{
		//allocation error check RAM available
	}

	return m_id;
}

void EntityManager::AddComponentTo(unsigned int entityID, void* component)
{
	if (m_entities.find(entityID) != m_entities.end())
	{
		m_entities.at(entityID)->AddComponent(component);
	}
}
