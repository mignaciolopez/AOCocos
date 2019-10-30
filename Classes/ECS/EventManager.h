#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include "ECS/EventList.h"
#include "ECS/Systems/System.h"

#include <vector>
#include <map>

namespace ECS
{
	// Abstract Class for EventHandler to notify of a change
	class EventHandlerBase
	{
	public:
		virtual void execute(unsigned int, unsigned int) = 0;
	};
	
	// Event Handler Class : Handles Callback
	template <typename Class>
	class EventHandler : public EventHandlerBase
	{
		// Defining type for function pointer
		typedef void (Class::*_fptr)(unsigned int, unsigned int);

	public:
		// Object of the Listener
		Class *object;
		// Function for callback
		_fptr function;

		EventHandler(Class *obj, _fptr func)
		{
			object = obj;
			function = func;
		}

		virtual void execute(unsigned int eid, unsigned int cid) override
		{
			(object->*function)(eid, cid);
		}
	};

	// Class to create a event
	class Evnt
	{
		// To store all listeners of the event
		typedef std::map<int, EventHandlerBase*> EventHandlerMap;
		EventHandlerMap handlers;
		int count = 0;
	public:

		template <typename Class>
		void addListener(Class *obj, void (Class::*func)(unsigned int, unsigned int))
		{
			handlers[count] = new (std::nothrow) EventHandler<Class>(obj, func);
			count++;
		}

		void execute(unsigned int eid, unsigned int cid)
		{
			for (EventHandlerMap::iterator it = handlers.begin(); it != handlers.end(); ++it)
				it->second->execute(eid, cid);
		}

	};

	class EventManager
	{
	public:
		EventManager();
		~EventManager();

		template <typename SYSTEM>
		inline bool Subscribe(EVENTS evnt, void(SYSTEM::*func)(unsigned int, unsigned int), SYSTEM* system)
		{
			if (m_events.find(evnt) != m_events.end())
			{
				m_events.at(evnt)->addListener(system, func);
				return true;
			}
			return false;
		}

		void execute(EVENTS evnt, unsigned int eid, unsigned int cid);

	private:
		std::map<EVENTS, Evnt*> m_events;
	};

}
#endif // __EVENT_MANAGER_H__