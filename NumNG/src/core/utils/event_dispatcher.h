#pragma once
#include "../preclude/preclude.h"

namespace ngUtil {

	using EventFunction = std::function<void(const void*)>;

	enum class EventType {
		//ϵͳ����Ϣ
		EVENT_SYSTEM,
		//Ӧ�ü���Ϣ
		EVENT_APPLICATION,
		//GUI����Ϣ
		EVENT_GUI,
		//�ű�֪ͨ
		EVENT_SCRIPT,
		//�û��ű�
		EVENT_USER_SCRIPT,
		//�û�����Ϣ
		EVENT_CUSTOM0,
		EVENT_CUSTOM1,
		EVENT_CUSTOM2
	};

	/*
	* ����ͨ�õ��¼�����
	*/
	template<typename T>
	struct EventData {};

#define SPECIALIZATION_EVENT_DATA(_struct,_name)\
	template<>\
	struct EventData<_struct> {\
			_struct name;\
	}
	/**
	 * �����¼��������ͣ������ͱ�����һ���ṹ�壬�¼��ַ���ת���¼�ʱͨ��name��ȡ��ת��������
	 */
#define CUSTOM_EVENT_DATA(_struct,_name) SPECIALIZATION_EVENT_DATA(_struct,_name)

	class EventDispatcher {
	public:
		EventDispatcher();
		~EventDispatcher();

		void subcribe(EventType eventType, EventFunction func);
		void unsubcribe(EventType eventType, EventFunction func);
		/**
		 * �ַ��¼����ɽ��¼��ַ������ж�����
		 * @param eventDataӦ��һ����װ������Ϊ�ṹ��
		 */
		template<typename _StructType>
		void dispatch(EventType eventType, EventData<_StructType> eventData);

	private:
		std::map<EventType, std::vector<EventFunction>> m_handlers;
	};
}