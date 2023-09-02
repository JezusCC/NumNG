#pragma once
#include "../../utils/utils.h"

namespace ngFileSystem {

    using ngStdTimeType = ngStd::time_t;

    /**
     * @brief 文件对象File
     * 
     * 资源ID
     * 文件路径
     * 文件类型
     * 文件扩展名
     * 绝对路径
     * 相对路径
     * 文件数据
     * 修改时间
     * 
    */
    class File {
    public:

        // Getter and Setter for m_uuid
        const ngUtils::UUID& getUuid() const ;
        // Getter and Setter for m_path
        const ngString& getPath() const ;
        void setPath(const ngString& path) ;
        // Getter and Setter for m_type
        const ngString& getType() const ;
        void setType(const ngString& type) ;
        // Getter and Setter for m_extension
        const ngString& getExtension() const ;
        void setExtension(const ngString& extension) ;
        // Getter and Setter for m_content
        const ngByte* getContentBinary() const ;
        const ngByte* getContentString() const ;
        // Getter and Setter for m_modification
        ngStdTimeType getModification() const ;
        void setModification(ngStdTimeType modification) ;

    private:
        ngUtils::UUID m_uuid;
        ngString m_path;
        ngString m_type;
        ngString m_extension;
        ngByte* m_content;
        ngStdTimeType m_modification;
    };

/**
 * @brief Directory 类
 * 用于描述目录
 * 
 */
    class Directory{
    public:
        Directory(const ngString& name,const ngString& path,ngBool isFile);
        ~Directory();

        ngBool isFile()const;
        ngBool isDirectory()const;
        uint32 fileNums()const;
        uint32 directoryNums()const;

    private:
        ngString m_path;
    private:
        //文件缓存
        //第一次获取可能慢一些，第二次加载直接从缓存拿
        ngStd::vector<File*> m_files_cache;
        //目录缓存
        ngStd::vector<ngString> m_directory_cache;
    };

    ngBool createDirectory(const ngString& path);
    ngBool deleteDirectory(const ngString& path);
    ngBool copyDirectory(const ngString& srcPath,const ngString& dstPath,ngBool deep = true);
    ngBool renameDirectory(const ngString& name);

    const ngString& getDirName(const ngString& path);
    int32 getDirFileNums(const ngString& path);
    int32 getDirSubdirNums(const ngString& path);

    ngBool createFile(const ngString& path,File file);
    ngBool deleteFile(const ngString& path,const ngString& fileName);
    ngBool copyFile(const ngString& path,const ngString& fileName);
    ngBool renameFile(const ngString& path,const ngString& srcName,const ngString& dstName);

    class FileManager{
    public:
        
    private:
    };

    /**
     * @brief 
     * 文件系统提供API
     * 
     * 创建目录
     * 删除目录
     * 复制目录
     * 重命名目录
     * 
     * 获取目录绝对路径
     * 获取目录相对路径
     * 
     * 获取目录名称
     * 获取当前目录下文件数量
     * 获取当前目录下子目录数量
     * 
     * 创建文件
     * 删除文件
     * 复制文件
     * 重命名文件
     * 
     * 获取文件绝对路径
     * 获取文件相对路径
     * 
     * 路径拼接(将一个路径与另一个路径拼接起来)
     * 内置根路径变量(当前项目所在路径，若引擎没初始化，该路径为空)
     * 
     * 
     */

    /**
     * @brief 
     * 文件过滤器
     * 根据条件进行过滤
     * 
     * 条件：
     *      按类型过滤
     *      按扩展名过滤
     *      按修改日期过滤
     *      按文件大小过滤(区间)
     *      按名字(区分大小写)
     *      按名字(不区分大小写)
     *      按名字(模糊搜索，KMP算法)
     * 
     */

} // namespace ngFileSystem
                  