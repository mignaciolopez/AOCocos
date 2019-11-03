#include "EventManager.h"

namespace ECS
{
#define LOGID "[EVENT MANAGER]"

	EventManager::EventManager()
	{
		cocos2d::log("%s Constructor", LOGID);

		for (int i = EVENTS::FIRST + 1; i != EVENTS::LAST; i++)
		{
			Evnt* e = new (std::nothrow) Evnt;
			if (e)
				m_events.emplace(static_cast<EVENTS>(i), e);
		}
	}

	EventManager::~EventManager()
	{
		for (auto e : m_events)
		{
			if (e.second)
			{
				delete e.second;
				e.second = nullptr;
			}
		}

		cocos2d::log("%s Destructor", LOGID);
	}

	void EventManager::execute(EVENTS evnt, int eid, cocos2d::Event * ccevnt, SLNet::BitStream* bs)
	{
		if (m_events.find(evnt) != m_events.end())
			m_events.at(evnt)->execute(eid, ccevnt, bs);
	}
}
