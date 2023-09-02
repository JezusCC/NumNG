#include "xml_loader.h"

namespace ngUtils{
    ngXml *XmlLoader::loadFile(const ngString &path)
    {
        ngStd::ifstream file(path);
        if(file.is_open()){
            ngStd::stringstream ss;
            ss << file.rdbuf();
            file.close();
            return this->loadString(ss.str());
        }
        return nullptr;
    }

    ngXml *XmlLoader::loadString(const ngString &xml)
    {
        auto root = this->parse(xml);
        if(root != nullptr){
            return new ngXml(root);
        }else{
            // NG_DEBUG_LOG("[XmlLoader::loadString] parse xml failed");
            return nullptr;
        }
    }
    ngXmlTag *XmlLoader::parse(ngStd::vector<ngStd::tuple<uint32,ngString,ngString,ngString>> tags)
    {
        

        //开始解析
        ngXmlTag* root = nullptr;
        ngXmlTag* current = root;
        

        
        
        

    }
    ngStd::vector<ngStd::tuple<uint32,ngString, ngString, ngString>> XmlLoader::getTagInfos(const ngString &xmlStr)
    {
        //保存解析出来的当前层数,开始标签，标签体，闭合标签
        ngStd::vector<ngStd::tuple<uint32,ngString,ngString,ngString>> tagInfos;

        //从字符串开始解析，碰到<就开始解析标签
        
        //解析标签的时候，碰到空格就开始解析属性，碰到>就结束解析属性
        //解析属性的时候，碰到=就开始解析属性值，碰到空格就结束解析属性值
        //解析属性值的时候，碰到"就开始解析属性值，碰到"就结束解析属性值

        uint32 index = 0;
        uint32 level = 0;

        uint32 size = xmlStr.size();

        for(;index<xmlStr.size();index++){
            ngString startTagName = "";
            ngString closeTagName = "";
            ngString content = "";

            //解析开始标签
            char8 ch = xmlStr[index];
            if(ch == '<'){
                uint32 start = index+1;
                uint32 end = start;
                for(;xmlStr[end] != '>' && end < xmlStr.size();end++);
                startTagName = xmlStr.substr(start,end-start);

                //解析标签内容
                start = end;
                end = start;
                for(;xmlStr[end] != '<';end++);
                content = xmlStr.substr(start,end-start);

                //解析闭合标签还没有写完。。。

                //解析闭合标签
                start = end;
                end = start;
                for(;xmlStr[end] != '>';end++);
                closeTagName = xmlStr.substr(start,end-start);

                tagInfos.push_back(ngStd::make_tuple(level,startTagName,content,closeTagName));

            }
        }
    }
}