#include "./directory.h"

namespace ngFileSystem {

    Directory::Directory(const std::string& dirPath) : path(dirPath) {}

    bool Directory::exists() const {
        return fs::exists(path);
    }

    bool Directory::isDirectory() const {
        return fs::is_directory(path);
    }

    std::string Directory::name() const {
        return path.filename().string();
    }

    std::vector<File> Directory::getFiles() const {
        std::vector<File> files;
        for (const auto& entry : fs::directory_iterator(path)) {
            if (entry.is_regular_file()) {
                files.emplace_back(entry.path().string());
            }
        }
        return files;
    }

    std::vector<Directory> Directory::getDirectories() const {
        std::vector<Directory> directories;
        for (const auto& entry : fs::directory_iterator(path)) {
            if (entry.is_directory()) {
                directories.emplace_back(entry.path().string());
            }
        }
        return directories;
    }

} // namespace ngFileSystem

