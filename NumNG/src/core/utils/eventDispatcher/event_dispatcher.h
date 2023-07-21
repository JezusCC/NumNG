#pragma once

#include "./event_type.h"
#include "../utils.h"

namespace ngUtils {

	class EventDispatcher {
	public:
		EventDispatcher();
		~EventDispatcher();

		void subscribe(EventType eventType, EventFunction func);

		void unsubscribe(EventType eventType, EventFunction func);

		/**
		* �ַ��¼����ɽ��¼��ַ������ж�����
		* @param eventDataӦ��һ����װ������Ϊ�ṹ��
		*/
		void dispatch(EventType eventType, EventData* eventData) {
			if (m_handlers.find(eventType) != m_handlers.end()) {
				const auto& handlers = m_handlers[eventType];
				for (auto& handler : handlers) {
					handler.func(eventData);
				}
			}
		}

	private:
		std::map<EventType, std::vector<EventFunction>> m_handlers;
	};
}