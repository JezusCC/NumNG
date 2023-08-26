#pragma once
#include "./hash_utils.h"

namespace ngUtils {
	/*
	* UUID
	* 产生一个UUID，该ID唯一且不可更改
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
		* 返回UUID的字符串
		*/
		ngString getUUID()const;

		ngString toString()override;
	private:
		ngString m_id;
	};
}