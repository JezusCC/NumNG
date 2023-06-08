#pragma once
#include "../preclude/preclude.h"

namespace ngUtil {
	class UtilBase {
	public:
		virtual ~UtilBase() = default;
		/*
		* 工具基类提供的toString方法，所有工具类均需要实现各自的toString方法
		*/
		virtual ngString toString() = 0;
	};

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