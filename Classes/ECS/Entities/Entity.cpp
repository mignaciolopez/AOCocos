#include "Entity.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[ENTITY]"

	Entity::Entity(unsigned int id)
	{
		cocos2d::log("%s Constructor", LOGID);

		m_id = id;
	}

	Entity::~Entity()
	{
		cocos2d::log("%s Destructor", LOGID);
	}

	void Entity::AddComponent(unsigned int id)
	{
		m_components.push_back(id);
	}

	unsigned int Entity::GetNumOfComponents()
	{
		return m_components.size();
	}

	std::vector<unsigned int> Entity::GetComponents()
	{
		return m_components;
	}

	std::vector<unsigned int> Entity::GetComponents(ComponentType type)
	{
		return std::vector<unsigned int>();
	}

}