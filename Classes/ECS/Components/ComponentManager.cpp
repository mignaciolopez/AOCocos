#include "ComponentManager.h"

namespace ECS
{

#define LOGID "[Component Manager]"

	ComponentManager::ComponentManager()
	{
		cocos2d::log("%s Constructor", LOGID);
	}

	ComponentManager::~ComponentManager()
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

	Component * ComponentManager::getComponent(unsigned int id)
	{
		if (m_components.find(id) != m_components.end())
			return m_components.at(id);

		return nullptr;
	}

	std::vector<unsigned int> ComponentManager::getComponentsOfType(ComponentType type)
	{
		std::vector<unsigned int> comps;

		typedef ContainerComponentTypes::iterator MMAPIterator;

		std::pair<MMAPIterator, MMAPIterator> result = m_componentsIndexType.equal_range(type);

		for (MMAPIterator it = result.first; it != result.second; it++)
			comps.push_back(it->second);

		return comps;
	}

	unsigned int ComponentManager::getNewID()
	{
		unsigned int id = 0;

		while (m_components.find(id) != m_components.end())
			++id;

		return id;
	}

}