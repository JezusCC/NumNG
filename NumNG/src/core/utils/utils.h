#pragma once
#include "../preclude/preclude.h"

namespace ngUtil {
	class UtilBase {
	public:
		virtual ~UtilBase() = default;
		/*
		* ���߻����ṩ��toString���������й��������Ҫʵ�ָ��Ե�toString����
		*/
		virtual ngString toString() = 0;
	};

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
	/*
	* UUID
	* ����һ��UUID����IDΨһ�Ҳ��ɸ���
	*/
	class UUID :public UtilBase {
	public:
		UUID();
		UUID(const UUID&) = delete;
		UUID(const UUID&&) = delete;
		virtual ~UUID() = default;

		void operator=(const UUID&) = delete;
		void operator=(const UUID&&) = delete;

		ngBool operator==(const UUID& value)const;
		ngBool operator!=(const UUID& value)const;

		/*
		* ����UUID���ַ���
		*/
		ngString getUUID()const;

		ngString toString()override;
	private:
		ngString m_id;
	};
}