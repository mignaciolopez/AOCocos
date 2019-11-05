#include "Entity.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[ENTITY]"

	Entity::Entity(int id)
	{
		cocos2d::log("%s Constructor", LOGID);

		m_id = id;
	}

	Entity::~Entity()
	{
		for (auto comp : m_components)
		{
			if (comp.second)
			{
				delete comp.second;
				comp.second = nullptr;
			}
		}

		cocos2d::log("%s Destructor", LOGID);
	}

	int Entity::GetNumOfComponents()
	{
		return m_components.size();
	}

	std::vector<Component*> Entity::getComponents()
	{
		std::vector<Component*> comps;
		for (auto comp : m_components)
		{
			comps.push_back(comp.second);
		}
		return comps;
	}

	std::vector<Component*> Entity::getComponents(ComponentType type)
	{
		std::vector<Component*> comps;

		typedef ContainerComponents::iterator MMAPIterator;

		std::pair<MMAPIterator, MMAPIterator> result = m_components.equal_range(type);

		for (MMAPIterator it = result.first; it != result.second; it++)
			comps.push_back(it->second);

		return comps;
	}

}