#pragma once

#include "../../preclude/preclude.h"

namespace ngFpm {

	constexpr ngFloat Epsilon = 0.0000000001;

	/**
	* 判断两数值是否近似相等
	* @param a 参数A
	* @param b 参数B
	* @param epsilon 误差精度
	* @return 如果两值近似相等返回真，否则返回假
	*/
	template <typename T>
	bool isEqual(const T& a, const T& b, const T& epsilon)
	{
		T diff = std::abs(a - b);
		return diff < epsilon;
	}

	/**
	* 归一化数值
	* @param value 待归一化数值
	* @return 归一化后的数值
	*/
	template <typename T>
	constexpr ngFloat NumricNormalized(T value) {
		return value < 0
			? -static_cast<ngFloat>(value) / std::numeric_limits<T>::min()
			: static_cast<ngFloat>(value) / std::numeric_limits<T>::max();
	}

	/**
	* 将数值value从一个区间映射到另一个区间(数值缩窄不安全)
	* @param value 映射值
	* @param srcMin 源区间起始值
	* @param srcMax 源区间终点值
	* @param dstMin 目标区间起始值
	* @param dstMax 目标区间终点值
	* @return 映射到新区间后的值
	*/
	template <typename T>
	T NumricMapping(T value, T srcMin, T srcMax, T dstMin, T dstMax) {
		if(sizeof(T) < 8) {
			return std::clamp((value - srcMin) * (dstMax - dstMin) / float32(srcMax - srcMin) + dstMin,dstMin,dstMax);
		}
		return std::clamp((value - srcMin) * (dstMax - dstMin) / float64(srcMax - srcMin) + dstMin,dstMin,dstMax);
	}
}