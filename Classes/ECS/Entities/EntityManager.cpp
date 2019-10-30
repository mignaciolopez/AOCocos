#include "EntityManager.h"

#include "ECS/Components/ComponentManager.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[ENTITY MANAGER]"

	EntityManager::EntityManager(ComponentManager* componentManager)
	{
		cocos2d::log("%s Constructor", LOGID);

		m_componentManager = componentManager;
	}

	EntityManager::~EntityManager()
	{
		if (m_entities.size() > 0)
		{
			for (auto e : m_entities)
			{
				delete e.second;
				e.second = nullptr;
			}
		}
		cocos2d::log("%s Destructor", LOGID);
	}

	unsigned int EntityManager::CreateEntity()
	{
		unsigned int id = 0;

		while (m_entities.find(id) != m_entities.end())
			++id;

		Entity* entity = new (std::nothrow) Entity(id);

		if (entity)
			m_entities.emplace(id, entity);
		else
		{
			cocos2d::log("%s Allocation Error", LOGID);
			cocos2d::log("%s Entity* entity = new (std::nothrow) Entity;", LOGID);
		}

		return id;
	}

	Entity * EntityManager::getEntity(unsigned int id)
	{
		if (m_entities.find(id) != m_entities.end())
			return m_entities.at(id);
		
		return nullptr;
	}

}