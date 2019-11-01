#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include "ECS/EventList.h"
#include "ECS/Systems/System.h"

#include <vector>
#include <map>

#include "cocos2d.h"

namespace ECS
{
	// Abstract Class for EventHandler to notify of a change
	class EventHandlerBase
	{
	public:
		EventHandlerBase()
		{
			cocos2d::log("%s Constructor", "[EVENT HANDLER BASE]");
		}
		virtual ~EventHandlerBase()
		{
			cocos2d::log("%s Destructor", "[EVENT HANDLER BASE]");
		}

		virtual void execute(unsigned int, unsigned int, cocos2d::Event* = nullptr) = 0;
	};
	
	// Event Handler Class : Handles Callback
	template <typename Class>
	class EventHandler : public EventHandlerBase
	{
		// Defining type for function pointer
		typedef void (Class::*_fptr)(unsigned int, unsigned int, cocos2d::Event*);

	public:
		// Object of the Listener
		Class *object;
		// Function for callback
		_fptr function;

		EventHandler(Class *obj, _fptr func)
		{
			cocos2d::log("%s Constructor", "[EVENT HANDLER]");
			object = obj;
			function = func;
		}
		~EventHandler()
		{
			cocos2d::log("%s Destructor", "[EVENT HANDLER]");
		}

		virtual void execute(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt = nullptr) override
		{
			(object->*function)(eid, cid, ccevnt);
		}
	};

	// Class to create a event
	class Evnt
	{
	public:
		Evnt()
		{
			cocos2d::log("%s Constructor", "[EVNT]");
		}
		virtual ~Evnt()
		{
			for (auto handler : m_handlers)
			{
				if (handler.second)
				{
					delete handler.second;
					handler.second = 0;
				}
			}
			cocos2d::log("%s Destructor", "[EVNT]");
		}

		template <typename Class>
		void addListener(Class *obj, void (Class::*func)(unsigned int, unsigned int, cocos2d::Event*))
		{
			m_handlers[count] = new (std::nothrow) EventHandler<Class>(obj, func);
			count++;
		}

		void execute(unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt = nullptr)
		{
			for (EventHandlerMap::iterator it = m_handlers.begin(); it != m_handlers.end(); ++it)
				it->second->execute(eid, cid, ccevnt);
		}
	private:
		// To store all listeners of the event
		typedef std::map<int, EventHandlerBase*> EventHandlerMap;
		EventHandlerMap m_handlers;
		int count = 0;

	};

	class EventManager
	{
	public:
		EventManager();
		~EventManager();

		template <typename SYSTEM>
		inline bool Subscribe(EVENTS evnt, void(SYSTEM::*func)(unsigned int, unsigned int, cocos2d::Event*), SYSTEM* system)
		{
			if (m_events.find(evnt) != m_events.end())
			{
				m_events.at(evnt)->addListener(system, func);
				return true;
			}
			return false;
		}

		void execute(EVENTS evnt, unsigned int eid, unsigned int cid, cocos2d::Event* ccevnt = nullptr);

	private:
		std::map<EVENTS, Evnt*> m_events;
	};

}
#endif // __EVENT_MANAGER_H__