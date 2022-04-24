#ifndef SIGNAL_MANAGER_H__
#define SIGNAL_MANAGER_H__

#include "SignalsList.h"
#include "entt.hpp"

#include "cocos2d.h"
#include "BitStream.h"

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
#if _DEBUG
				cocos2d::log("[PairSS] Constructor");
#endif
			}
			~PairSS()
			{
#if _DEBUG
				cocos2d::log("[PairSS] Destructor");
#endif
			}
			sighDef sigh;
			sinkDef sink{ sigh };
		};

		SignalsManager();
		~SignalsManager();

		static SignalsManager* getInstance();
		static void destroyInstace();

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

	private:
		std::map<Signals, PairSS*> m_container;
	};
}
#endif // !SIGNAL_MANAGER_H__