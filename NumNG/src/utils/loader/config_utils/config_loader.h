#pragma once
#include "../../common/common.h"
namespace ngUtils {

	class ConfigLoader {
	public:
		ConfigLoader(const ngString& path);
		~ConfigLoader();

		ngBool hasSection(const ngString& section)const;
		/**
		 * @brief 寻找当前config中是否包含某一个键
		 *
		 * @param key key name
		 * @param section 从哪个节开始寻找，如果没有则默认从root节开始寻找
		 * @return ngString 返回找到的节名，如果没有，则为空
		 */
		ngString hasKey(const ngString& key, const ngString& section = "root")const;

		template<typename _Ret>
		_Ret castTo(const ngString& key) {

		}

	private:
		ngStd::map<ngString, ngStd::map<ngString, ngString>> m_root;
	};


}