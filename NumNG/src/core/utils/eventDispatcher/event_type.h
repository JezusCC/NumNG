#pragma once
#include "../../preclude/preclude.h"

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
		std::function<void(void*)> func;
		bool operator==(const EventFunctionType& _oth) { return name == _oth.name; }
	};
	using EventFunction = EventFunctionType;

#define EV_CUSTOM_EVENT_FUNCTION(func_name) {#func_name,func_name}
}