#pragma once
#include "../../preclude/preclude.h"

#include <ctime>

using ngStdTimeType = std::time_t;

namespace ngFileSystem {

    class File {
    public:
        explicit File(const ngString& filePath);
        ~File();

        ngBool exists() const;
        ngBool isFile() const;
        ngString getPath() const;
        ngString getFileName() const;
        ngString getExtensionsName() const;
        uint64_t getFileSize() const;
        ngString getFileType() const;
        ngStdTimeType getModificationTime() const;
        const ngByte* getContentByBinary() const;
        ngString getContentByString() const;
        ngString getAbsoluteURL() const;
        ngString getRelativeURL(const ngString& basePath) const;
        void forceUpdate();

    private:
        ngString path;
        ngBool isExists;
        ngBool isFileFlag;
        ngString fileName;
        ngString extensionsName;
        uint64_t fileSize;
        ngString fileType;
        ngStdTimeType modificationTime;
        ngByte* content;

        void initialize();
    };

} // namespace ngFileSystem
