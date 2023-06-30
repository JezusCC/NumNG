#pragma once
#include "../preclude/preclude.h"

namespace ngUtil {

	using EventFunction = std::function<void(const void*)>;

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

	/*
	* 声明通用的事件数据
	*/
	template<typename T>
	struct EventData {};

#define SPECIALIZATION_EVENT_DATA(_struct,_name)\
	template<>\
	struct EventData<_struct> {\
			_struct name;\
	}
	/**
	 * 定义事件数据类型，该类型必须是一个结构体，事件分发器转发事件时通过name获取到转发的数据
	 */
#define CUSTOM_EVENT_DATA(_struct,_name) SPECIALIZATION_EVENT_DATA(_struct,_name)

	class EventDispatcher {
	public:
		EventDispatcher();
		~EventDispatcher();

		void subcribe(EventType eventType, EventFunction func);
		void unsubcribe(EventType eventType, EventFunction func);
		/**
		 * 分发事件，可将事件分发给所有订阅者
		 * @param eventData应是一个封装参数，为结构体
		 */
		template<typename _StructType>
		void dispatch(EventType eventType, EventData<_StructType> eventData);

	private:
		std::map<EventType, std::vector<EventFunction>> m_handlers;
	};
}