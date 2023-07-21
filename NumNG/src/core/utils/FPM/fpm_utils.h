#pragma once

#include "../../preclude/preclude.h"

namespace ngFpm {

	template <typename T>
	bool isEqual(const T& a, const T& b, const T& epsilon)
	{
		T diff = std::abs(a - b);
		return diff < epsilon;
	}
}