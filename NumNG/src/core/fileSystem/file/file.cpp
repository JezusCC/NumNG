#include "./file.h"

namespace ngFileSystem {

    namespace ngStdFileSystem = std::filesystem;

    File::File(const ngString& filePath) : path(filePath), content(nullptr) {
        initialize();
    }

    File::~File() {
        delete[] content;
    }

    void File::initialize() {
        ngStdFileSystem::path filePath(path);

        isExists = ngStdFileSystem::exists(filePath);
        isFileFlag = ngStdFileSystem::is_regular_file(filePath);

        if (!isExists || !isFileFlag) {
            return;
        }

        fileName = filePath.filename().string();
        extensionsName = filePath.extension().string();
        fileSize = ngStdFileSystem::file_size(filePath);
        fileType = ngStdFileSystem::path(filePath).replace_extension().string();
        modificationTime = ngStdFileSystem::last_write_time(filePath).time_since_epoch().count();

        // Load file content
        std::ifstream fileStream(path, std::ios::binary);
        if (fileStream) {
            std::ostringstream oss;
            oss << fileStream.rdbuf();
            std::string contentString = oss.str();
            content = new ngByte[contentString.size()];
            std::memcpy(content, contentString.c_str(), contentString.size());
        }
    }

    ngBool File::exists() const {
        return isExists;
    }

    ngBool File::isFile() const {
        return isFileFlag;
    }

    ngString File::getPath() const{
        return path;
    }

    ngString File::getFileName() const {
        return fileName;
    }

    ngString File::getExtensionsName() const {
        return extensionsName;
    }

    uint64_t File::getFileSize() const {
        return fileSize;
    }

    ngString File::getFileType() const {
        return fileType;
    }

    ngStdTimeType File::getModificationTime() const {
        return modificationTime;
    }

    const ngByte* File::getContentByBinary() const {
        return content;
    }

    ngString File::getContentByString() const {
        ngString contentString;
        const ngByte* binaryContent = getContentByBinary();
        if (binaryContent != nullptr) {
            std::stringstream ss;
            ss.write(reinterpret_cast<const char*>(binaryContent), getFileSize());
            contentString = ss.str();
        }
        return contentString;
    }

        ngString File::getAbsoluteURL() const {
        ngStdFileSystem::path filePath(path);
        return ngStdFileSystem::absolute(filePath).string();
    }

    ngString File::getRelativeURL(const ngString& basePath) const {
        ngStdFileSystem::path filePath(path);
        ngStdFileSystem::path base(basePath);
        return ngStdFileSystem::relative(filePath, base).string();
    }

    void File::forceUpdate(){
        initialize();
    }

} // namespace ngFileSystem