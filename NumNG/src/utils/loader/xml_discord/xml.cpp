#include "xml.h"

namespace ngUtils{
    ngXml::ngXml()
    {
        m_root = new ngXmlTag("root",nullptr,0);
    }
    ngXml::ngXml(ngXmlTag *root):
        m_root(root)
    {
    }
    ngXml::~ngXml()
    {
        this->clear();
    }
    ngXmlTag *ngXml::getRoot()
    {
        return m_root;
    }
    const ngXmlTag *ngXml::getRoot() const
    {
        return m_root;
    }
    ngStd::vector<ngXmlTag *> ngXml::getTags(const ngString &name)
    {
        ngStd::vector<ngXmlTag*> tags;

        if(name.empty()){
            
        }else{
            tags = m_root->getChilds(name);
        }
        return tags;
    }
    const ngStd::vector<const ngXmlTag *> ngXml::getTags(const ngString &name) const
    {
        ngStd::vector<const ngXmlTag*> tags;

        if(name.empty()){
            tags.push_back(m_root); 
            //从根标签开始遍历
            for(auto& child : m_root->getChildrenVector()){
                //先将自身加入
                tags.push_back(child);
                //再将子标签加入
                ngStd::merge(tags.begin(),tags.end(),child->getChildrenVector().begin(),child->getChildrenVector().end(),tags.begin());
            }
        }else{
            tags = m_root->getChildsConst(name);
        }
        return tags;
    }
    ngXmlTag *ngXml::getFirstChildTag(const ngString &name)
    {
        if(name.empty()){
            return m_root->getChild(0);
        }else{
            return m_root->getChild(name);
        }
    }
    ngXmlTag *ngXml::getLastChildTag(const ngString &name)
    {
        if(name.empty()){
            return m_root->getChild(m_root->getChildrenVector().size()-1);
        }else{
            auto childs = m_root->getChilds(name);
            return childs[childs.size()-1];
        }
    }
    void ngXml::clear()
    {
        if(m_root){
            delete m_root;
            m_root = nullptr;
        }
    }
}
