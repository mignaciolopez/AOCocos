#include "EntityManager.h"


#include "Components/BodyComponent.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[ENTITY MANAGER]"

	EntityManager::EntityManager()
	{
		m_id = 0;
		cocos2d::log("%s Constructor", LOGID);
	}

	EntityManager::~EntityManager()
	{
		cocos2d::log("%s Destructor", LOGID);
		if (m_entities.size() > 0)
		{
			for (auto e : m_entities)
			{
				delete e.second;
				e.second = nullptr;
			}
		}
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
			cocos2d::log("%s Allocation Error", LOGID);
			cocos2d::log("%s Entity* entity = new (std::nothrow) Entity;", LOGID);
		}

		return m_id;
	}

	ContainerEntity* EntityManager::GetEntities()
	{
		return &m_entities;
	}

	std::vector<Entity*> EntityManager::GetEntitiesWithComponent(ComponentType type)
	{
		std::vector<Entity*> entities;

		for (auto entity : m_entities)
		{
			for (auto comp : entity.second->GetComponentsOfType(type))
			{
				entities.push_back(entity.second);
			}
		}

		return entities;
	}

}