#pragma once

namespace ngUtils {
//	/*
//	* 声明通用的事件数据
//	*/
//	template<typename T>
//	struct EventDataType {};
//
//#define EV_SPECIALIZATION_EVENT_DATA(_struct,_name)\
//	template<>\
//	struct ngUtils::EventDataType<_struct> {\
//			_struct _name;\
//	}
//	/**
//	 * 定义事件数据类型，该类型必须是一个结构体，事件分发器转发事件时通过name获取到转发的数据
//	 */
//#define EV_CUSTOM_EVENT_DATA_DEFINE(_struct,_name) EV_SPECIALIZATION_EVENT_DATA(_struct,_name)
//#define EV_GET_CUSTOM_EVENT_DATA_TYPE(_struct) ngUtils::EventDataType<_struct>

	//空的事件类型
	//用户可以扩展出自定义的EventData，但是接收事件中需要进行转换
	class EventData {
	public:
		EventData() = default;
		virtual ~EventData() = default;
	};

}