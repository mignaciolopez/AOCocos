#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#include "ECS/EventList.h"
#include "ECS/Systems/System.h"

#include <vector>
#include <map>

#include "cocos2d.h"
#include "BitStream.h"

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

		virtual void execute(int, cocos2d::Event* = nullptr, SLNet::BitStream* = nullptr) = 0;
	};
	
	// Event Handler Class : Handles Callback
	template <typename Class>
	class EventHandler : public EventHandlerBase
	{
		// Defining type for function pointer
		typedef void (Class::*_fptr)(int, cocos2d::Event*, SLNet::BitStream*);

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

		virtual void execute(int eid, cocos2d::Event* ccevnt = nullptr, SLNet::BitStream* bs = nullptr) override
		{
			(object->*function)(eid, ccevnt, bs);
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
		void addListener(Class *obj, void (Class::*func)(int, cocos2d::Event*, SLNet::BitStream*))
		{
			m_handlers[count] = new (std::nothrow) EventHandler<Class>(obj, func);
			count++;
		}

		void execute(int eid, cocos2d::Event* ccevnt = nullptr, SLNet::BitStream* bs = nullptr)
		{
			for (EventHandlerMap::iterator it = m_handlers.begin(); it != m_handlers.end(); ++it)
				it->second->execute(eid, ccevnt, bs);
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
		inline bool Subscribe(EVENTS evnt, void(SYSTEM::*func)(int, cocos2d::Event*, SLNet::BitStream*), SYSTEM* system)
		{
			if (m_events.find(evnt) != m_events.end())
			{
				m_events.at(evnt)->addListener(system, func);
				return true;
			}
			return false;
		}

		void execute(EVENTS evnt, int eid, cocos2d::Event* ccevnt = nullptr, SLNet::BitStream* bs = nullptr);

	private:
		std::map<EVENTS, Evnt*> m_events;
	};

}
#endif // __EVENT_MANAGER_H__