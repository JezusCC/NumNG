#pragma once
#include "../../common/common.h"
#include "tinyxml/tinyxml2.h"
namespace ngUtils {
	
	/**
	 * @brief XML标签对象
	 * 
	 */
	class ngXmlTag : public tinyxml2::XMLElement {
	public:
		ngXmlTag(const ngString& name);
		~ngXmlTag();
	private:

	};

	/**
	 * @brief XML文档对象
	 * 
	 */
	class ngXml : public tinyxml2::XMLDocument {
	public:
		/**
		* 创建一个具有默认根标签的XML文档对象，根标签名为Root
		*/
		ngXml();
		ngXml(const ngString& path);
		~ngXml();

		ngXmlTag* getRoot() const;

	private:
		ngXmlTag* m_root;
	};

}

