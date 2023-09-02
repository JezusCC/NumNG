#pragma once
#include "xml.h"
#include "tinyxml/tinyxml2.h"
namespace ngUtils {

    //XMLLoader 类，用于加载XML文件
    class XmlLoader {
    public:
        XmlLoader()=default;
        ~XmlLoader()=default;

        /**
         * @brief 从文件加载XMl
         * 
         * @param path 
         * @return ngXml* 
         */
        ngXml* loadFile(const ngString& path);
        /**
         * @brief 从字符串加载XML
         * 
         * @param xml 
         * @return ngXml* 
         */
        ngXml* loadString(const ngString& xml);

    private:
        /**
         * @brief 用于转换XML文件到XmlObject，他是一个根Tag
         * 
         * @return ngXmlTag* 
         */
        ngXmlTag* parse(ngStd::vector<ngStd::tuple<uint32,ngString,ngString,ngString>> tags);

        ngStd::vector<ngStd::tuple<uint32,ngString,ngString,ngString>> getTagInfos(const ngString& xmlStr);
    };

}