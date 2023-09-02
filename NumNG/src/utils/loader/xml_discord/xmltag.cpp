#include "xmltag.h"

namespace ngUtils{
    ngXmlTag::ngXmlTag(const ngString &name, ngXmlTag *parent, uint32 level):
        m_name(name),m_parent(parent),m_level(level),m_content("")
    {
    }
    ngXmlTag::~ngXmlTag()
    {
        this->clearChildren();
        this->m_parent = nullptr;
    }
    ngBool ngXmlTag::appendChild(ngXmlTag *child)
    {
        if(child == nullptr)
        {
            return false;
        }else{
            child->m_parent = this;
            m_children.push_back(child);
            return true;
        }
    }
    ngBool ngXmlTag::appendChild(ngXmlTag *child, uint32 index)
    {
        if(child == nullptr || index >= m_children.size())
        {
            return false;
        }else{
            child->m_parent = this;
            m_children.insert(m_children.begin() + index,child);
            return true;
        }
    }
    ngBool ngXmlTag::removeChild(ngXmlTag *child)
    {
        if(child == nullptr)
        {
            return false;
        }else{
            for (auto it = m_children.begin(); it != m_children.end(); it++)
            {
                if(*it == child)
                {
                    m_children.erase(it);
                    delete child;
                    return true;
                }
            }
            return false;
        }
    }
    ngBool ngXmlTag::removeChild(uint32 index)
    {
        if(index >= m_children.size())
        {
            return false;
        }else{
            auto it = m_children.begin() + index;
            delete *it;
            m_children.erase(it);
            return true;
        }
    }
    ngBool ngXmlTag::removeChild(const ngString &name)
    {
        ngBool result = false;
        for (auto it = m_children.begin(); it != m_children.end(); it++)
        {
            if((*it)->m_name == name)
            {
                delete *it;
                m_children.erase(it);
                result = true;
            }
        }
        return result;
    }
    const ngXmlTag *ngXmlTag::getChildConst(uint32 index) const
    {
        if(index >= m_children.size())
        {
            return nullptr;
        }else{
            return m_children[index];
        }
    }
    const ngXmlTag *ngXmlTag::getChildConst(const ngString &name) const
    {
        for (auto child : m_children)
        {
            if(child->m_name == name)
            {
                return child;
            }
        }
        return nullptr;
    }
    ngStd::vector<const ngXmlTag *> ngXmlTag::getChildsConst(const ngString &name) const
    {
        ngStd::vector<const ngXmlTag *> result;
        for (auto child : m_children)
        {
            if(child->m_name == name)
            {
                result.push_back(child);
            }
        }
        return result;
    }
    ngXmlTag *ngXmlTag::getChild(uint32 index)
    {
        if(index >= m_children.size())
        {
            return nullptr;
        }else{
            return m_children[index];
        }
    }
    ngXmlTag *ngXmlTag::getChild(const ngString &name)
    {
        for (auto child : m_children)
        {
            if(child->m_name == name)
            {
                return child;
            }
        }
        return nullptr;
    }
    ngStd::vector<ngXmlTag *> ngXmlTag::getChilds(const ngString &name)
    {
        ngStd::vector<ngXmlTag *> result;
        for (auto child : m_children)
        {
            if(child->m_name == name)
            {
                result.push_back(child);
            }
        }
        return result;
    }
    void ngXmlTag::setAttribute(const ngString &name, const ngString &value)
    {
        m_attributes[name] = value;
    }
    void ngXmlTag::removeAttribute(const ngString &name)
    {
        m_attributes.erase(name);
    }
    const ngString &ngXmlTag::getAttribute(const ngString &name) const
    {
        auto it = m_attributes.find(name);
        if(it == m_attributes.end())
        {
            return "";
        }else{
            return it->second;
        }
    }
    uint32 ngXmlTag::getChildTagCount() const
    {
        return m_children.size();
    }
    void ngXmlTag::setContent(const ngString &content)
    {
        m_content = content;
    }
    ngBool ngXmlTag::setParent(ngXmlTag *parent)
    {
        if(parent == nullptr)
        {
            return false;
        }else{
            if(m_parent != nullptr)
            {
                m_parent->removeChild(this);
            }
            m_parent = parent;
            return true;
        }
    }
    ngStd::vector<ngXmlTag *> ngXmlTag::getChildrenVector() const
    {
        return m_children;
    }
    void ngXmlTag::clearChildren()
    {
        for (auto child : m_children)
        {
            delete child;
        }
        m_children.clear();
    }
}