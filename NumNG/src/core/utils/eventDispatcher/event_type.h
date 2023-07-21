#pragma once
#include "../../preclude/preclude.h"
#include "./event_data.h"

namespace ngUtils {
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

	struct EventFunctionType {
		ngString name;
		std::function<void(EventData*)> func;
		bool operator==(const EventFunctionType& _oth) { return name == _oth.name; }
	};
	using EventFunction = EventFunctionType;

#define _NG_DEFINE_EVENT_FUNCTION_NORMAL(_f) ngUtils::EventFunctionType{#_f,_f}
#define _NG_DEFINE_EVENT_FUNCTION_CLASS(_f,_o) ngUtils::EventFunctionType{#_f,std::bind(&_f,&_o,std::placeholders::_1)}

	//������ͨ����
#define EV_CUSTOM_EVENT_FUNCTION(func_name) _NG_DEFINE_EVENT_FUNCTION_NORMAL(func_name)
	//�����������Ա�������¼�����
#define EV_CUSTOM_CLASS_EVENT_FUNCTION(func_name,object) _NG_DEFINE_EVENT_FUNCTION_CLASS(func_name,object)
}