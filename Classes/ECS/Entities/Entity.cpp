#include "Entity.h"

#include "ECS/Components/Component.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[ENTITY]"

	Entity::Entity()
	{
		cocos2d::log("%s Constructor", LOGID);
	}

	Entity::~Entity()
	{
		cocos2d::log("%s Destructor", LOGID);
	}

	void Entity::AddComponent(ECS::Component* component)
	{
		m_components.push_back(component);
	}

	unsigned int Entity::GetNumOfComponents()
	{
		return m_components.size();
	}

}