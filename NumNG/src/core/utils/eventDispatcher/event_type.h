#pragma once
#include "../../preclude/preclude.h"
#include "./event_data.h"

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
		std::function<void(EventData*)> func;
		bool operator==(const EventFunctionType& _oth) { return name == _oth.name; }
	};
	using EventFunction = EventFunctionType;

#define _NG_DEFINE_EVENT_FUNCTION_NORMAL(_f) ngUtils::EventFunctionType{#_f,_f}
#define _NG_DEFINE_EVENT_FUNCTION_CLASS(_f,_o) ngUtils::EventFunctionType{#_f,std::bind(&_f,&_o,std::placeholders::_1)}

	//创建普通函数
#define EV_CUSTOM_EVENT_FUNCTION(func_name) _NG_DEFINE_EVENT_FUNCTION_NORMAL(func_name)
	//创建基于类成员函数的事件函数
#define EV_CUSTOM_CLASS_EVENT_FUNCTION(func_name,object) _NG_DEFINE_EVENT_FUNCTION_CLASS(func_name,object)
}