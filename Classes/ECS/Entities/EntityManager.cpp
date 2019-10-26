#include "EntityManager.h"

#include "ECS/Entities/Entity.h"
#include "ECS/Components/Component.h"

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

	void EntityManager::AddComponentTo(unsigned int entityID, Component * component)
	{
		if (m_entities.find(entityID) != m_entities.end())
		{
			m_entities.at(entityID)->AddComponent(component->_type, component);
		}
	}

	ContainerEntity* EntityManager::GetEntities()
	{
		return &m_entities;
	}

}