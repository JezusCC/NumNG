#pragma once
#include "../common/common.h"
namespace ngUtils{

    /**
     * @brief 
     * 
     * @tparam T 待管理类  
     * @tparam clean 是否由Manager进行元素清理
     */
    template<typename T,ngBool clean = false>
    class Manager{
    public:
        Manager();
        virtual ~Manager(){}
        virtual ngBool addElement(const ngString& name, T element){
            if(hasElement(name)){
                // 
                return true;
            }else{
                m_container.insert(ngStd::make_pair(name, ngStd::move(element)));
                return true;
            }
        }
        virtual ngBool delElement(const ngString& name){
            auto it = m_container.find(name);
            if (it != m_container.end()) {
                m_container.erase(it);
                return true;
            }
            return false;
        }
        virtual ngBool getElement(const ngString& name, T& element)const{
            auto it = m_container.find(name);
            if (it != m_container.end()) {
                element = it->second;
                return true;
            }
            return false;
        }
        virtual ngBool setElement(const ngString& name, const T& newElement){
            auto it = m_container.find(name);
            if (it != m_container.end()) {
                it->second = newElement;
                return true;
            }
            return false;
        }
        ngBool hasElement(const ngString& name)const{
            return m_container.find(name) != m_container.end();
        }
        uint32 countElement()const{
            return m_container.size();
        }
    protected:
        ngStd::map<ngString, T> m_container;
    };

}