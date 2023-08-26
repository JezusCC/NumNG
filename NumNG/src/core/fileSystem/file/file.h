#pragma once
#include "../../preclude/preclude.h"
#include <ctime>
#include <filesystem>

using ngStdTimeType = std::time_t;
namespace ngStdFileSystem = std::filesystem;

namespace ngFileSystem {

    class File {
    public:
        explicit File(const ngString& filePath);
        ~File();

        ngBool exists() const;
        ngBool isFile() const;
        ngString getFileName() const;
        ngString getExtensionsName() const;
        uint64 getFileSize() const;
        ngString getFileType() const;
        ngStdTimeType getModificationTime() const;

    private:
        ngStdFileSystem::path path;
    };

} // namespace ngFileSystem
