#ifndef SIGNAL_MANAGER_H__
#define SIGNAL_MANAGER_H__

#include "SignalsList.h"
#include "entt.hpp"

#include "ECS/ECS_Log.h"
#include "BitStream.h"
#include <map>

namespace ECS
{
	class SignalsManager
	{
	public:
		typedef entt::sigh<void(entt::entity, SLNet::BitStream * bs)> sighDef;
		typedef entt::sink<void(entt::entity, SLNet::BitStream * bs)> sinkDef;

		struct PairSS
		{
			PairSS()
			{
				ECS_Log::s_consoleL->trace("[PairSS] Constructor");
			}
			~PairSS()
			{
				ECS_Log::s_consoleL->trace("[PairSS] Destructor");
			}
			sighDef sigh;
			sinkDef sink{ sigh };
		};

		SignalsManager();
		~SignalsManager();

		static std::shared_ptr<SignalsManager>& getSignalsManager();

		void publish(Signals signalID, entt::entity entity, SLNet::BitStream* bs = nullptr);

		template<auto Candidate, typename Type>
		void connect(Signals signalID, Type &&value_or_instance)
		{
			if (m_container.find(signalID) == m_container.end())
				return;

			m_container.at(signalID)->sink.connect<Candidate>(value_or_instance);
		}

		template<typename Type>
		void disconnect(Signals signalID, Type *value_or_instance)
		{
			if (m_container.find(signalID) == m_container.end())
				return;

			m_container.at(signalID)->sink.disconnect(value_or_instance);
		}

		template<typename Type>
		void disconnectAll(Type *value_or_instance)
		{
			for (auto& s : m_container)
			{
				s.second->sink.disconnect(value_or_instance);
			}
		}

	public:

	private:
		static std::shared_ptr<SignalsManager> s_signalsManager;

		std::map<Signals, PairSS*> m_container;

	};
}
#endif // !SIGNAL_MANAGER_H__