#pragma once

#include "./event_type.h"
#include "./event_data.h"
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
		template<typename T>
		void dispatch(EventType eventType,EventData<T>* eventData){
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