#pragma once
#include "../../preclude/preclude.h"

namespace ngUtils {
	enum class EventType {
		//系统级消息
		EVENT_SYSTEM,
		//应用级消息
		EVENT_APPLICATION,
		//GUI级消息
		EVENT_GUI,
		//脚本通知
		EVENT_SCRIPT,
		//用户脚本
		EVENT_USER_SCRIPT,
		//用户级消息
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