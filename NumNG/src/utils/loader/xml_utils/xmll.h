#pragma once
#include "../../common/common.h"
namespace ngUtils {
	
	class XMLDocument;
	class XMLNode;

	using ngTag = XMLNode;

	class ngXml {
	public:
		/**
		 * @brief 创建一个标准XML文档
		 * 
		 */
		ngXml();
		/**
		 * @brief 从文件加载XML文档
		 * 
		 * @param path 
		 */
		ngXml(const ngString& path);
		~ngXml();

		ngBool appendChild(ngTag* tag);
		
		ngBool insertChild(ngTag* tag, ngTag* target);

		void removeChild(ngTag* tag);

	private:
		//清理
		void clear();
		//初始化一个标准XML文档
		void initStdXmlDocument();

	private:
		XMLDocument* document;
	};

}

