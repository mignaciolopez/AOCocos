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

	return m_id;
}
