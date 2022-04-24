#include "SignalsManager.h"

namespace ECS
{
	SignalsManager::SignalsManager()
	{
#if _DEBUG
		cocos2d::log("[SignalsManager] Constructor");
#endif
		for (int i = Signals::FIRST; i < Signals::LAST; ++i)
		{
			PairSS* pair = new (std::nothrow) PairSS;
			if (!pair)
			{
#if _DEBUG
				cocos2d::log("[SignalsManager] pait is nullptr");
#endif
				break;
			}
			m_container.emplace(static_cast<Signals>(i), pair);
		}
	}

	SignalsManager::~SignalsManager()
	{
#if _DEBUG
		cocos2d::log("[SignalsManager] Destructor");
#endif

		for (auto& s : m_container)
		{
			s.second->sink.disconnect();
			delete s.second;
			s.second = nullptr;
		}
	}


	static SignalsManager* s_signalsManager = nullptr;

	SignalsManager * SignalsManager::getInstance()
	{
#ifdef _DEBUG
		cocos2d::log("[SignalsManager] Call to getInstance.");
#endif
		if (!s_signalsManager)
		{
#ifdef _DEBUG
			cocos2d::log("[SignalsManager] s_signalsManager is nullptr");
#endif
			s_signalsManager = new (std::nothrow) SignalsManager;
		}

		return s_signalsManager;
	}

	void SignalsManager::destroyInstace()
	{
		if (s_signalsManager)
		{
			delete s_signalsManager;
			s_signalsManager = nullptr;
		}
	}

	void SignalsManager::publish(Signals signalID, entt::entity entity, SLNet::BitStream* bs)
	{
		if (m_container.find(signalID) == m_container.end())
			return;

		m_container.at(signalID)->sigh.publish(entity, bs);
	}
}