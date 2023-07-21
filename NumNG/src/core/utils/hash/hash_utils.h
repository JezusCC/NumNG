#pragma once
#include "../common/common.h"

namespace ngUtils {
	/*
	* Hash
	* ���ݹ�ϣ�㷨����һ����ϣ����
	* �����ȷ�����������������ͬ�Ľ��
	*/
	class Hash :public UtilBase {
	public:
		Hash() = delete;
		Hash(const Hash&) = delete;
		Hash(ngInt value);
		Hash(ngString value);
		virtual ~Hash() = default;

		ngBool operator==(const Hash& value)const;
		ngBool operator!=(const Hash& value)const;
		/*
		* ��ȡ��ϣ����
		*/
		ngInt getCode()const;

		ngString toString()override;
	private:
		ngInt m_code;
	};
}