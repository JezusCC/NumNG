#pragma once
#include "../../common/common.h"
namespace ngUtils{
    //Tag 类，用于描述XML标签
    class ngXmlTag {
    public:
        /**
         * @brief 创建一个空标签,如果parent为空则为根标签
         * 
         */
        ngXmlTag(const ngString& name, ngXmlTag* parent = nullptr,uint32 level = 0);
        ~ngXmlTag();

        /**
         * @brief 插入子标签到当前标签尾部
         * 
         * @param child 
         * @return ngBool 
         */
        ngBool appendChild(ngXmlTag* child);
        /**
         * @brief 插入子标签到当前标签指定位置,不可超过子标签数量
         * 
         * @param child 
         * @param index 
         * @return ngBool 
         */
        ngBool appendChild(ngXmlTag* child, uint32 index);
        /**
         * @brief 移除子标签
         * 
         * @param child 
         * @return ngBool 
         */
        ngBool removeChild(ngXmlTag* child);
        /**
         * @brief 移除指定位置子标签,不可超过子标签数量
         * 
         * @param index 
         * @return ngBool 
         */
        ngBool removeChild(uint32 index);
        /**
         * @brief 移除指定名称子标签,所有具有此名称的子标签都会被移除
         * 
         * @param name 
         * @return ngBool 
         */
        ngBool removeChild(const ngString& name);
        

        /**
         * @brief 返回指定位置子标签,如果有的话
         * 
         * @param index 
         * @return const ngXmlTag* 
         */
        ngXmlTag* getChild(uint32 index);
        const ngXmlTag* getChildConst(uint32 index) const;
        /**
         * @brief 获取第一个具有指定名称的子标签
         * 
         * @param name 
         * @return const ngXmlTag* 
         */
        ngXmlTag* getChild(const ngString& name);
        const ngXmlTag* getChildConst(const ngString& name) const;

        /**
         * @brief 获取所有具有指定名称的子标签
         * 
         * @param name 
         * @return ngStd::vector<ngXmlTag*> 
         */
        ngStd::vector<ngXmlTag*> getChilds(const ngString& name);
        ngStd::vector<const ngXmlTag*> getChildsConst(const ngString& name) const;

        /**
         * @brief 为标签设置属性,如果已经存在则覆盖
         * 
         * @param name 
         * @param value 
         */
        void setAttribute(const ngString& name, const ngString& value);

        /**
         * @brief 移除标签属性,如果不存在则不做任何操作
         * 
         * @param name 
         */
        void removeAttribute(const ngString& name);

        /**
         * @brief 获取标签属性,如果不存在则返回空字符串
         * 
         * @param name 
         * @return const ngString& 
         */
        const ngString& getAttribute(const ngString& name) const;

        /**
         * @brief 获取子标签数量
         * 
         * @return uint32 
         */
        uint32 getChildTagCount() const;

        /**
         * @brief 设置标签内容
         * 
         * @param content 
         */
        void setContent(const ngString& content = "");

        /**
         * @brief 设置当前标签的父标签，如果父标签为空则插入失败，它会将已有的父标签
         * 
         * @param parent 
         * @return ngBool 
         */
        ngBool setParent(ngXmlTag* parent);

        ngStd::vector<ngXmlTag*> getChildrenVector()const;

    private:
        /**
         * @brief 清除当前标签下的子标签
         * 
         */
        void clearChildren();

    private:
        uint32 m_level;
        ngXmlTag* m_parent;
        ngString m_name;
        ngString m_content;
        ngStd::map<ngString,ngString> m_attributes;
        ngStd::vector<ngXmlTag*> m_children;
    };
}