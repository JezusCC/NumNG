#pragma once
#include "../utils/event_dispatcher.h"
namespace ngCore {
	/**
	 * Êó±êÊı¾İ
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