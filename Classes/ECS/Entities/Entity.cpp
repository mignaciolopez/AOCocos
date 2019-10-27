#include "Entity.h"

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
		for (auto component : m_components)
		{
			delete component.second;
			component.second = nullptr;
		}
		cocos2d::log("%s Destructor", LOGID);
	}

	/*void Entity::AddComponent(Component * component)
	{
		m_components.emplace(component->_type, component);
	}*/

	unsigned int Entity::GetNumOfComponents()
	{
		return m_components.size();
	}

	std::vector<Component*> Entity::GetComponentsOfType(ComponentType type)
	{
		std::vector<Component*> comps;

		typedef ContainerComponents::iterator itC;
		std::pair<itC, itC> result = m_components.equal_range(type);

		for (itC it = result.first; it != result.second; it++)
			comps.push_back(it->second);

		return comps;
	}

}