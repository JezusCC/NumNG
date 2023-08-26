#pragma once
#include "../utils.h"
namespace ngUtils {

	class ConfigLoader {
	public:
		ConfigLoader(const ngString& path);
		ConfigLoader(const ngChar* str);
		virtual ~ConfigLoader();

		// 加载conf文件的方法
		void loadConfFile(const ngString& filePath);

		// 读取配置项的方法
		ngString getConfigValue(const ngString& key);

		template<typename T>
		T cast(const ngString& key) {
			ngString value = getConfigValue(key);
			// Perform the conversion to T and return the result
			// ...
		}

		

	private:
		std::unordered_map<ngString, ngString> m_configData;
	};


}