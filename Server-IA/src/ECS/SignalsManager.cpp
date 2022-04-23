#include "SignalsManager.h"

namespace ECS
{
	std::shared_ptr<SignalsManager> SignalsManager::s_signalsManager = nullptr;

	SignalsManager::SignalsManager()
	{
		ECS_Log::s_consoleL->trace("[SignalsManager] Constructor");

		for (int i = Signals::FIRST; i < Signals::LAST; ++i)
		{
			PairSS* pair = new PairSS;
			m_container.emplace(static_cast<Signals>(i), pair);
		}

		ECS_Log::s_consoleL->debug("[SignalsManager] Event Listeners count: {:d}", m_container.size());
	}

	SignalsManager::~SignalsManager()
	{
		ECS_Log::s_consoleL->trace("[SignalsManager] Destructor");

		int count = 0;
		for (auto& s : m_container)
		{
			count++;
			s.second->sink.disconnect();
			delete s.second;
			s.second = nullptr;
		}

		ECS_Log::s_consoleL->debug("[SignalsManager] deleted handlers: {:d} of {:d}", count, m_container.size());
	}

	std::shared_ptr<SignalsManager>& SignalsManager::getSignalsManager()
	{
		if (!s_signalsManager)
		{
			ECS_Log::s_consoleL->debug("[SignalsManager] getSignalsManager() s_signalsManager is nullptr");
			s_signalsManager = std::make_shared<SignalsManager>();
		}

		return s_signalsManager;
	}

	void SignalsManager::publish(Signals signalID, entt::entity entity, SLNet::BitStream * bs)
	{
		if (m_container.find(signalID) == m_container.end())
		{
			ECS_Log::s_consoleL->error("[SignalsManager] publish() Signal Not Found. Signal:{:d} entt:{:d}.", signalID, entity);
			return;
		}

		ECS_Log::s_consoleL->trace("[SignalsManager] publish() Signal: {:d} entt: {:d}.", signalID, entity);
		m_container.at(signalID)->sigh.publish(entity, bs);
	}
}