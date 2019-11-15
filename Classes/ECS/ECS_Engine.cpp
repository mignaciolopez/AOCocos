#include "ECS_Engine.h"

#include <atomic>

namespace ECS
{

#define LOGID "[ECS Engine]"

	static ECS_Engine* s_ecsEngine = nullptr;

	ECS_Engine * ECS_Engine::getInstance()
	{
		if (!s_ecsEngine)
		{
			s_ecsEngine = new (std::nothrow) ECS_Engine;
		}

		return s_ecsEngine;
	}

	void ECS_Engine::destroyInstance()
	{
		if (s_ecsEngine)
		{
			delete s_ecsEngine;
			s_ecsEngine = nullptr;
		}
	}

	ECS_Engine::ECS_Engine()
	{
#if _DEBUG
		cocos2d::log("%s Constructor", LOGID);
#endif

		m_entityManager = new (std::nothrow) EntityManager();
		if (!m_entityManager)
			cocos2d::log("%s EntityManager allocation error", LOGID);

		m_eventManager = new (std::nothrow) EventManager;
		if (!m_entityManager)
			cocos2d::log("%s EventManager allocation error", LOGID);

		m_systemManager = new (std::nothrow) SystemManager(m_eventManager);
		if (!m_systemManager)
			cocos2d::log("%s SystemManager allocation error", LOGID);
	}

	ECS_Engine::~ECS_Engine()
	{
		if (m_eventManager)
		{
			delete m_eventManager;
			m_eventManager = nullptr;
		}

		if (m_systemManager)
		{
			delete m_systemManager;
			m_systemManager = nullptr;
		}

		if (m_entityManager)
		{
			delete m_entityManager;
			m_entityManager = nullptr;
		}
#if _DEBUG
		cocos2d::log("%s Destructor", LOGID);
#endif
	}

	void ECS_Engine::update()
	{
			m_systemManager->Update();
	}

	EntityManager* ECS_Engine::getEntityManager()
	{
		return m_entityManager;
	}

	SystemManager* ECS_Engine::getSystemManager()
	{
		return m_systemManager;
	}

	EventManager* ECS_Engine::getEventManager()
	{
		return m_eventManager;
	}

	void ECS_Engine::applicationDidEnterBackground()
	{
	}

	void ECS_Engine::applicationWillEnterForeground()
	{
	}

}