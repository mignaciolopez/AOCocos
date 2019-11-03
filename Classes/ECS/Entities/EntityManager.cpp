#include "EntityManager.h"

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[ENTITY MANAGER]"

	EntityManager::EntityManager()
	{
		cocos2d::log("%s Constructor", LOGID);
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

	bool EntityManager::CreateEntity(int eid)
	{
		if (m_entities.find(eid) != m_entities.end())
			return false;

		Entity* entity = new (std::nothrow) Entity(eid);

		if (entity)
			m_entities.emplace(eid, entity);
		else
		{
			cocos2d::log("%s Allocation Error", LOGID);
			cocos2d::log("%s Entity* entity = new (std::nothrow) Entity;", LOGID);
			return false;
		}

		return true;
	}

	Entity * EntityManager::getEntity(int id)
	{
		if (m_entities.find(id) != m_entities.end())
			return m_entities.at(id);
		
		return nullptr;
	}

	ContainerEntity * EntityManager::getEntities()
	{
		return &m_entities;
	}

}