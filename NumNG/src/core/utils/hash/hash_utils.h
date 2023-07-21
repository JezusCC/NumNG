#pragma once
#include "../common/common.h"

namespace ngUtils {
	/*
	* Hash
	* 根据哈希算法产生一个哈希编码
	* 这个类确保在任意机器产生相同的结果
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
		* 获取哈希编码
		*/
		ngInt getCode()const;

		ngString toString()override;
	private:
		ngInt m_code;
	};
}