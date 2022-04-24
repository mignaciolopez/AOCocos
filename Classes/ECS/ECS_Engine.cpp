#include "ECS_Engine.h"

#include <atomic>

namespace ECS
{

	ECS_Engine::ECS_Engine() 
		: m_signalsManager(nullptr), m_registry(nullptr)
	{
#ifdef _DEBUG
		cocos2d::log("[ECS_Engine] Constructor.");
#endif

	}

	ECS_Engine::~ECS_Engine()
	{
#ifdef _DEBUG
		cocos2d::log("[ECS_Engine] Destructor.");
#endif

	}


	ECS_Engine* s_ECS_Engine = nullptr;

	ECS_Engine * ECS_Engine::getInstance()
	{
#ifdef _DEBUG
		cocos2d::log("[ECS_Engine] Call to getInstance.");
#endif
		if (!s_ECS_Engine)
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] new (std::nothrow) ECS_Engine.");
#endif
			s_ECS_Engine = new (std::nothrow) ECS_Engine;
		}

		return s_ECS_Engine;
	}

	void ECS_Engine::destroyInstance()
	{
#ifdef _DEBUG
		cocos2d::log("[ECS_Engine] Destroying Instance.");
#endif

		if (s_ECS_Engine)
		{
			delete s_ECS_Engine;
			s_ECS_Engine = nullptr;
		}
	}

	bool ECS_Engine::start()
	{
#ifdef _DEBUG
		cocos2d::log("[ECS_Engine] Starting ECS Engine.");
#endif

		m_registry = new (std::nothrow) entt::registry;
		if (!m_registry)
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] m_registry is nullptr.");
#endif
			return false;
		}

		m_signalsManager = ECS::SignalsManager::getInstance();
		m_signalsManager->connect<&ECS_Engine::setLocalEntity>(Signals::NW_MY_ENTT, this);

		m_systemManager = new (std::nothrow) SystemManager;
		if (!m_systemManager)
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] m_systemManager is nullptr.");
#endif
			return false;
		}

		//Systems
		AudioSystem* audioSystem = new (std::nothrow) AudioSystem(m_registry);
		if (!audioSystem)
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] audioSystem is nullptr.");
#endif
			return false;
		}
		if (!m_systemManager->RegisterSystem(audioSystem))
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] audioSystem was not registered.");
#endif
			return false;
		}

		NetworkSystem* networkSystem = new (std::nothrow) NetworkSystem(m_registry);
		if (!networkSystem)
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] networkSystem is nullptr.");
#endif
			return false;
		}
		if (!m_systemManager->RegisterSystem(networkSystem))
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] networkSystem was not registered.");
#endif
			return false;
		}

		CameraSystem* cameraSystem = new (std::nothrow) CameraSystem(m_registry);
		if (!cameraSystem)
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] cameraSystem is nullptr.");
#endif
			return false;
		}
		if (!m_systemManager->RegisterSystem(cameraSystem))
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] cameraSystem was not registered.");
#endif
			return false;
		}

		GraphicsSystem* graphicsSystem = new (std::nothrow) GraphicsSystem(m_registry);
		if (!graphicsSystem)
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] graphicsSystem is nullptr.");
#endif
			return false;
		}
		if (!m_systemManager->RegisterSystem(graphicsSystem))
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] graphicsSystem was not registered.");
#endif
			return false;
		}

		AnimationSystem* animationSystem = new (std::nothrow) AnimationSystem(m_registry);
		if (!animationSystem)
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] animationSystem is nullptr.");
#endif
			return false;
		}
		if (!m_systemManager->RegisterSystem(animationSystem))
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] animationSystem was not registered.");
#endif
			return false;
		}

		MovementSystem* movementSystem = new (std::nothrow) MovementSystem(m_registry);
		if (!movementSystem)
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] movementSystem is nullptr.");
#endif
			return false;
		}
		if (!m_systemManager->RegisterSystem(movementSystem))
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] movementSystem was not registered.");
#endif
			return false;
		}

		CombatSystem* combatSystem = new (std::nothrow) CombatSystem(m_registry);
		if (!combatSystem)
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] combatSystem is nullptr.");
#endif
			return false;
		}
		if (!m_systemManager->RegisterSystem(combatSystem))
		{
#ifdef _DEBUG
			cocos2d::log("[ECS_Engine] combatSystem was not registered.");
#endif
			return false;
		}


		//
		cocos2d::Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);

		return true;
	}

	void ECS_Engine::shutdown()
	{
#ifdef _DEBUG
		cocos2d::log("[ECS_Engine] ECS Engine is shuting down.");
#endif

		// unregister all systems

		//delete all components and entities
		if (m_systemManager)
		{
			delete m_systemManager;
			m_systemManager = nullptr;
		}

		if (m_registry)
		{
			m_registry->each([=](auto entity) {
				m_registry->destroy(entity);
			});

			delete m_registry;
			m_registry = nullptr;
		}

		if (m_signalsManager)
		{
			SignalsManager::destroyInstace();
		}

		ECS_Engine::destroyInstance();
	}

	void ECS_Engine::update(float dt)
	{
#ifdef _DEBUG
		//cocos2d::log("[ECS_Engine] Call to update. dt: %f", dt);
#endif
		m_systemManager->update(dt);
	}

	void ECS_Engine::applicationDidEnterBackground()
	{
		if (m_localEntt != entt::null)
			m_signalsManager->publish(Signals::APP_DID_ENTER_BG, m_localEntt);
	}

	void ECS_Engine::applicationWillEnterForeground()
	{
		if (m_localEntt != entt::null)
			m_signalsManager->publish(Signals::APP_WILL_ENTER_FG, m_localEntt);
	}

	void ECS_Engine::setLocalEntity(entt::entity entity,  SLNet::BitStream* bs)
	{
		m_localEntt = entity;
	}

	entt::registry * ECS_Engine::getRegistry()
	{
		return m_registry;
	}

	ECS::SystemManager * ECS_Engine::getSystemManager()
	{
		return m_systemManager;
	}

}
