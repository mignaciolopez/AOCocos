#include "ECS_Engine.h"

#include <atomic>
#include "Systems/IncludeSystems.h"
#include <Windows.h> //using to exit on keystrokes

namespace ECS
{
	std::shared_ptr<ECS_Engine> ECS_Engine::s_ecs_Engine = nullptr;

	ECS_Engine::ECS_Engine() : m_signalsManager(nullptr)
	{
		ECS_Log::s_consoleL->trace("[ECS_Engine] Constructor");
	}

	ECS_Engine::~ECS_Engine()
	{
		ECS_Log::s_consoleL->trace("[ECS_Engine] Destructor");
	}

	bool ECS_Engine::init()
	{
		ECS_Log::s_consoleL->trace("[ECS_Engine] init()");

		m_signalsManager = SignalsManager::getSignalsManager();
		if (!m_signalsManager)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] m_signalsManager is nullptr.");
			return false;
		}

		m_registry = new (std::nothrow) entt::registry;
		if (!m_registry)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] m_registry is nullptr.");
			return false;
		}

		m_systemManager = new (std::nothrow) SystemManager;
		if (!m_systemManager)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] m_systemManager is nullptr.");
			return false;
		}

		// 4- Create Systems
		NetworkSystem* networkSystem = new (std::nothrow) NetworkSystem(m_registry);
		if (!networkSystem)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] audioSystem is nullptr.");
			return false;
		}
		if (!m_systemManager->RegisterSystem(networkSystem))
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] audioSystem was not registered.");
			return false;
		}

		SpawnSystem* spawnSystem = new (std::nothrow) SpawnSystem(m_registry);
		if (!spawnSystem)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] spawnSystem is nullptr.");
			return false;
		}
		if (!m_systemManager->RegisterSystem(spawnSystem))
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] spawnSystem was not registered.");
			return false;
		}

		MovementSystem* movementSystem = new (std::nothrow) MovementSystem(m_registry);
		if (!movementSystem)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] movementSystem is nullptr.");
			return false;
		}
		if (!m_systemManager->RegisterSystem(movementSystem))
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] movementSystem was not registered.");
			return false;
		}

		GraphicsSystem* graphicsSystem = new (std::nothrow) GraphicsSystem(m_registry);
		if (!graphicsSystem)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] graphicsSystem is nullptr.");
			return false;
		}
		if (!m_systemManager->RegisterSystem(graphicsSystem))
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] graphicsSystem was not registered.");
			return false;
		}

		CombatSystem* combatSystem = new (std::nothrow) CombatSystem(m_registry);
		if (!combatSystem)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] combatSystem is nullptr.");
			return false;
		}
		if (!m_systemManager->RegisterSystem(combatSystem))
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] combatSystem was not registered.");
			return false;
		}

		HealthSystem* healthSystem = new (std::nothrow) HealthSystem(m_registry);
		if (!healthSystem)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] healthSystem is nullptr.");
			return false;
		}
		if (!m_systemManager->RegisterSystem(healthSystem))
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] healthSystem was not registered.");
			return false;
		}

		ManaSystem* manaSystem = new (std::nothrow) ManaSystem(m_registry);
		if (!manaSystem)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] manaSystem is nullptr.");
			return false;
		}
		if (!m_systemManager->RegisterSystem(manaSystem))
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] manaSystem was not registered.");
			return false;
		}


		InventorySystem* inventorySystem = new (std::nothrow) InventorySystem(m_registry);
		if (!inventorySystem)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] inventorySystem is nullptr.");
			return false;
		}
		if (!m_systemManager->RegisterSystem(inventorySystem))
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] inventorySystem was not registered.");
			return false;
		}


		IntervalSystem* intervalSystem = new (std::nothrow) IntervalSystem(m_registry);
		if (!intervalSystem)
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] intervalSystem is nullptr.");
			return false;
		}
		if (!m_systemManager->RegisterSystem(intervalSystem))
		{
			ECS_Log::s_consoleL->critical("[ECS_Engine] intervalSystem was not registered.");
			return false;
		}


		m_running = true;

		m_start = std::chrono::steady_clock::now();
		m_end = std::chrono::steady_clock::now();
		m_dt = m_end - m_start;

		ECS_Log::s_consoleL->info("[ECS_Engine] Init Success.");
		ECS_Log::s_consoleL->info("[ECS_Engine] Server Running.");

		return true;
	}

	void ECS_Engine::shutdown()
	{
		ECS_Log::s_consoleL->trace("[ECS_Engine] shutdown().");

		//delete all components and entities
		if (m_systemManager)
		{
			delete m_systemManager;
			m_systemManager = nullptr;
		}

		if (m_registry)
		{
			delete m_registry;
			m_registry = nullptr;
		}
	}

	void ECS_Engine::update()
	{
		m_start = std::chrono::steady_clock::now();		

		m_systemManager->update(m_dt.count());

		m_end = std::chrono::steady_clock::now();

		m_dt = m_end - m_start;

		if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_SPACE))
			m_running = false;
	}

	std::shared_ptr<ECS_Engine>& ECS_Engine::getECSEngine()
	{
		if (!s_ecs_Engine)
		{
			ECS_Log::s_consoleL->debug("[ECS_Engine] getECSEngine() s_ecs_Engine is nullptr");
			s_ecs_Engine = std::make_shared<ECS_Engine>();
		}

		return s_ecs_Engine;
	}

	bool ECS_Engine::isRunning()
	{
		return m_running;
	}
}