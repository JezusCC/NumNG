#pragma once
#include "../preclude/preclude.h"
#include "./utils.h"
namespace ngUtil {

	template<typename T>
	T StringCastToClass(const ngString& str);

	class ConfigLoader {
	public:
		ConfigLoader(const ngString& path);
		ConfigLoader(const ngChar* str);
		virtual ~ConfigLoader();

		//将value转化成t类型的值
		template<typename T>
		T cast(const ngString& key);

		ngBool existKey(const ngBool& key);
	private:
		ngBool parse(const ngString& buffer);

	private:
		std::stringstream m_str_buffer;
		std::unordered_map<ngString, ngString> m_config_tree;
	};

}