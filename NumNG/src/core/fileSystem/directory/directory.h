#pragma once
#include "../file/file.h"

namespace ngFileSystem {
    namespace fs = std::filesystem;

    class Directory {
    public:
        explicit Directory(const std::string& dirPath);

        bool exists() const;
        bool isDirectory() const;
        std::string name() const;
        std::vector<File> getFiles() const;
        std::vector<Directory> getDirectories() const;

    private:
        fs::path path;
    };

} // namespace ngFileSystem
