#include "EventManager.h"

namespace ECS
{
	EventManager::EventManager()
	{
		for (int i = EVENTS::FIRST; i != EVENTS::LAST; ++i)
		{
			Evnt* e = new (std::nothrow) Evnt;
			if (e)
				m_events.emplace(static_cast<EVENTS>(i), e);
		}
	}

	EventManager::~EventManager()
	{
	}

	void EventManager::execute(EVENTS evnt, unsigned int eid, unsigned int cid)
	{
		if (m_events.find(evnt) != m_events.end())
			m_events.at(evnt)->execute(eid, cid);
	}
}
