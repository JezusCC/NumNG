#pragma once
#include "./hash_utils.h"

namespace ngUtils {
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