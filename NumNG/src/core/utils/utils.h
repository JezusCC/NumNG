#pragma once
#include "../preclude/preclude.h"

namespace NGUtil {
	class UtilBase {
		virtual ~UtilBase() = default;
		virtual string toString() = 0;
	};
}