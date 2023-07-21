#pragma once
#include "../../preclude/preclude.h"

namespace ngUtils {
	class UtilBase {
	public:
		virtual ~UtilBase() = default;
		/*
		* ���߻����ṩ��toString���������й��������Ҫʵ�ָ��Ե�toString����
		*/
		virtual ngString toString() = 0;
	};

	/**
	 * ������ָ��ת��������ָ��
	 * ��ת���ɹ����ظ�ָ�룬���򷵻ؿ�
	 */
	template<typename TargetType, typename SourceType>
	TargetType* DynamicCast(SourceType* source) {
		return dynamic_cast<TargetType*>(source);
	}
	/**
	 * ��Դָ��ת����Ŀ��ָ��
	 * ��ת���ɹ����ظ�ָ�룬���򷵻ؿ�
	 */
	template<typename TargetType, typename SourceType>
	TargetType* ForceCast(SourceType* source) {
		return static_cast<TargetType*>(source);
	}
}