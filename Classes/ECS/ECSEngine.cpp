#include "ECSEngine.h"

#include <atomic>

#include "cocos2d.h"

namespace ECS
{

#define LOGID "[ECS Engine]"

	static ECSEngine* s_ecsEngine = nullptr;

	ECSEngine * ECSEngine::GetInstance()
	{
		if (!s_ecsEngine)
		{
			s_ecsEngine = new (std::nothrow) ECSEngine;
		}

		return s_ecsEngine;
	}

	void ECSEngine::DestroyInstance()
	{
		if (s_ecsEngine)
		{
			delete s_ecsEngine;
			s_ecsEngine = nullptr;
		}
	}

	ECSEngine::ECSEngine()
	{
		cocos2d::log("%s Constructor", LOGID);

		m_entityManager = new (std::nothrow) EntityManager;
		if (!m_entityManager)
			cocos2d::log("%s EntityManager allocation error", LOGID);

		m_systemManager = new (std::nothrow) SystemManager;
		if (!m_systemManager)
			cocos2d::log("%s SystemManager allocation error", LOGID);
	}

	ECSEngine::~ECSEngine()
	{
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

		cocos2d::log("%s Destructor", LOGID);
	}

	void ECSEngine::Update()
	{
			m_systemManager->Update();
	}

	EntityManager * ECSEngine::GetEntityManager()
	{
		return m_entityManager;
	}

	SystemManager * ECSEngine::GetSystemManager()
	{
		return m_systemManager;
	}

}