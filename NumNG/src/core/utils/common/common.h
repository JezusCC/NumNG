#pragma once
#include "../../preclude/preclude.h"

namespace ngUtils {
	class UtilBase {
	public:
		virtual ~UtilBase() = default;
		/*
		* 工具基类提供的toString方法，所有工具类均需要实现各自的toString方法
		*/
		virtual ngString toString() = 0;
	};

	/**
	 * 将基类指针转换成子类指针
	 * 若转换成功返回该指针，否则返回空
	 */
	template<typename TargetType, typename SourceType>
	TargetType* DynamicCast(SourceType* source) {
		return dynamic_cast<TargetType*>(source);
	}
	/**
	 * 将源指针转换成目标指针
	 * 若转换成功返回该指针，否则返回空
	 */
	template<typename TargetType, typename SourceType>
	TargetType* ForceCast(SourceType* source) {
		return static_cast<TargetType*>(source);
	}
}