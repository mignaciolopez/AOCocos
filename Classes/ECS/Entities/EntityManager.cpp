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
				if (e.second)
				{
					delete e.second;
					e.second = nullptr;
				}
			}
		}

		if (m_components.size() > 0)
		{
			for (auto cc : m_components)
			{
				if (cc.second)
				{
					for (auto c : *cc.second)
					{
						if (c.second)
						{
							delete c.second;
							c.second = nullptr;
						}
					}

					delete cc.second;
					cc.second = nullptr;
				}
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
		{
			m_entities.emplace(eid, entity);
			std::map<ComponentType, Component*>* map = new (std::nothrow) std::map<ComponentType, Component*>;
			m_components.emplace(eid, map);
		}
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

	void EntityManager::removeEntity(int eid)
	{
		if (m_entities.find(eid) != m_entities.end())
		{
			delete m_entities.at(eid);
			m_entities.at(eid) = nullptr;
			m_entities.erase(eid);
		}

		if (m_components.find(eid) != m_components.end())
		{
			for (auto c : *m_components.at(eid))
			{
				delete c.second;
				c.second = nullptr;
			}
			delete m_components.at(eid);
			m_components.at(eid) = nullptr;

			m_components.erase(eid);
		}
	}

	Component * EntityManager::getComp(int eid, ComponentType type)
	{
		if (m_components.find(eid) != m_components.end())
		{
			if (m_components.at(eid)->find(type) != m_components.at(eid)->end())
				return m_components.at(eid)->at(type);
		}
		return nullptr;
	}

	void EntityManager::removeComponent(int eid, ComponentType type, bool cleanup)
	{
		if (m_components.find(eid) == m_components.end())
			return;

		if (m_components.at(eid)->find(type) == m_components.at(eid)->end())
			return;

		if (cleanup)
		{
			delete m_components.at(eid)->at(type);
			m_components.at(eid)->at(type) = nullptr;
			m_components.at(eid)->erase(type);
		}
		else
		{
			m_components.at(eid)->erase(type);
		}
	}

}