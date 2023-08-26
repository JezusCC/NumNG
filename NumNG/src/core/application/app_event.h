#pragma once
#include "../utils/eventDispatcher/event_dispatcher.h"

namespace Core {
	/**
	 * 鼠标数据
	 */
	struct MouseEventData {
		uint32 x;
		uint32 y;
	};
	/**
	 * 
	 */
	struct KeyboardEventData {
		int32 keyCode;
	};
}