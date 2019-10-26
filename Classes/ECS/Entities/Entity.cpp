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
		for (auto component : m_components)
		{
			delete component.second;
			component.second = nullptr;
		}
	}

	void Entity::AddComponent(ComponentType type, ECS::Component* component)
	{
		m_components.emplace(type, component);
	}

	unsigned int Entity::GetNumOfComponents()
	{
		return m_components.size();
	}

}