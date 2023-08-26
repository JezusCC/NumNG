#include "./file.h"
#include <iomanip>


namespace ngFileSystem {

    File::File(const ngString& filePath) : path(filePath) {}

    File::~File() {}

    ngBool File::exists() const {
        return ngStdFileSystem::exists(path);
    }

    ngBool File::isFile() const {
        return ngStdFileSystem::is_regular_file(path);
    }

    ngString File::getFileName() const {
        return path.filename().string();
    }

    ngString File::getExtensionsName() const {
        return path.extension().string();
    }

    uint64 File::getFileSize() const {
        return ngStdFileSystem::file_size(path);
    }

    ngString File::getFileType() const {
        return getExtensionsName();
    }

    ngStdTimeType File::getModificationTime() const {
        std::filesystem::file_time_type time = ngStdFileSystem::last_write_time(path);
        std::chrono::system_clock::duration duration = time.time_since_epoch();
        ngStdTimeType milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
        return milliseconds;
    }

} // namespace ngFileSystem