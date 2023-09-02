#include "./event_dispatcher.h"

namespace ngUtils{

	EventDispatcher::EventDispatcher() {

	}
	EventDispatcher::~EventDispatcher(){

	}
	void EventDispatcher::subscribe(EventType eventType, EventFunction func)
	{
		m_handlers[eventType].push_back(func);
	}
	void EventDispatcher::unsubscribe(EventType eventType, EventFunction func)
	{
		if (m_handlers.find(eventType) != m_handlers.end()) {
			auto& handlers = m_handlers[eventType];
			handlers.erase(std::remove(handlers.begin(), handlers.end(), func), handlers.end());
		}
	}
}
