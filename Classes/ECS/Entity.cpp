#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::AddComponent(void * component)
{
	m_components.push_back(component);
}

unsigned int Entity::GetNumOfComponents()
{
	return m_components.size();
}
