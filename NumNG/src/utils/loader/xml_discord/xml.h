#pragma once

#include "xmltag.h"

namespace ngUtils{
    //XML 类，用于描述XML结构
    class ngXml {
    public:
        /**
         * @brief 构造一个默认的XML对象，具有一个根标签
         * 
         */
        ngXml();
        /**
         * @brief XmlLoader解析的XML对象
         * 
         * @param root 
         */
        ngXml(ngXmlTag* root);

        ~ngXml();

        /**
         * @brief 获取XML根标签
         * 
         * @return ngXmlTag* 
         */
        ngXmlTag* getRoot();
        const ngXmlTag* getRoot() const;
        /**
         * @brief 获取指定名称的所有标签,如果没有则返回空数组，如果不传入名称则返回所有标签
         * 
         * @param name 
         * @return ngStd::vector<ngXmlTag*> 
         */
        ngStd::vector<ngXmlTag*> getTags(const ngString& name = "");
        const ngStd::vector<const ngXmlTag*> getTags(const ngString& name = "") const;

         /**
         * @brief 获取具有指定名称标签的第一个子标签，如果不传入名称则返回根标签所属子标签的第一个子标签,如果没有则返回空
         * 
         * @param name 
         * @return ngXmlTag* 
         */
        ngXmlTag* getFirstChildTag(const ngString& name = "");

        /**
         * @brief 获取具有指定名称标签的最后一个子标签，如果不传入名称则返回根标签所属子标签的最后一个子标签,如果没有则返回空
         * 
         * @param name 
         * @return ngXmlTag* 
         */
        ngXmlTag* getLastChildTag(const ngString& name = "");


    private:
        /**
         * @brief 清除XML对象
         * 
         */
        void clear();

    private:
        ngXmlTag* m_root;
    };
}