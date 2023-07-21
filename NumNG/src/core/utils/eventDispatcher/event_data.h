#pragma once

namespace ngUtils {
	/*
	* 声明通用的事件数据
	*/
	template<typename T>
	struct EventData {};

#define EV_SPECIALIZATION_EVENT_DATA(_struct,_name)\
	template<>\
	struct ngUtils::EventData<_struct> {\
			_struct _name;\
	}
	/**
	 * 定义事件数据类型，该类型必须是一个结构体，事件分发器转发事件时通过name获取到转发的数据
	 */
#define EV_CUSTOM_EVENT_DATA_DEFINE(_struct,_name) EV_SPECIALIZATION_EVENT_DATA(_struct,_name)
#define EV_GET_CUSTOM_EVENT_DATA_TYPE(_struct) ngUtils::EventData<_struct>
}