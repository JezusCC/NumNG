#pragma once

#include "../../preclude/preclude.h"

namespace ngFpm {

	constexpr ngFloat Epsilon = 0.0000000001;

	/**
	* �ж�����ֵ�Ƿ�������
	* @param a ����A
	* @param b ����B
	* @param epsilon ����
	* @return �����ֵ������ȷ����棬���򷵻ؼ�
	*/
	template <typename T>
	bool isEqual(const T& a, const T& b, const T& epsilon)
	{
		T diff = std::abs(a - b);
		return diff < epsilon;
	}

	/**
	* ��һ����ֵ
	* @param value ����һ����ֵ
	* @return ��һ�������ֵ
	*/
	template <typename T>
	constexpr ngFloat NumricNormalized(T value) {
		return value < 0
			? -static_cast<ngFloat>(value) / std::numeric_limits<T>::min()
			: static_cast<ngFloat>(value) / std::numeric_limits<T>::max();
	}

	/**
	* ����ֵvalue��һ������ӳ�䵽��һ������(��ֵ��խ����ȫ)
	* @param value ӳ��ֵ
	* @param srcMin Դ������ʼֵ
	* @param srcMax Դ�����յ�ֵ
	* @param dstMin Ŀ��������ʼֵ
	* @param dstMax Ŀ�������յ�ֵ
	* @return ӳ�䵽��������ֵ
	*/
	template <typename T>
	T NumricMapping(T value, T srcMin, T srcMax, T dstMin, T dstMax) {
		if(sizeof(T) < 8) {
			return std::clamp((value - srcMin) * (dstMax - dstMin) / float32(srcMax - srcMin) + dstMin,dstMin,dstMax);
		}
		return std::clamp((value - srcMin) * (dstMax - dstMin) / float64(srcMax - srcMin) + dstMin,dstMin,dstMax);
	}
}