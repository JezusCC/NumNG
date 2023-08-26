#pragma once
#include "./directory/directory.h"

namespace ngFileSystem {

    class FileSystem {
    public:
        explicit FileSystem(const std::string& rootPath);

        Directory getRootDirectory() const;

    private:
        Directory rootDirectory;
    };

} // namespace ngFileSystem
