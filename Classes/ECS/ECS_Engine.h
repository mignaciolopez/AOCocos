#ifndef ECS_ENGINE_H__
#define ECS_ENGINE_H__

#include "Systems/IncludeSystems.h"
#include "ECS/iSystems/SystemManager.h"
#include "ECS/SignalsManager.h"

namespace ECS
{
	class ECS_Engine
	{
	public:
		ECS_Engine();
		~ECS_Engine();

		static ECS_Engine* getInstance();

		bool start();
		void shutdown();

		void update(float dt);

		void applicationDidEnterBackground();
		void applicationWillEnterForeground();

		void setLocalEntity(entt::entity entity, SLNet::BitStream* bs);

		entt::registry* getRegistry();
		ECS::SystemManager* getSystemManager();

	private:
		static void destroyInstance();

		entt::registry* m_registry;

		ECS::SignalsManager* m_signalsManager;
		ECS::SystemManager* m_systemManager;

		entt::entity m_localEntt = entt::null;
	};
}
#endif // !ECS_ENGINE_H__