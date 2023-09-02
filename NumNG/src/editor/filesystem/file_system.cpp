#include "./file_system.h"

namespace ngFileSystem{
    // Getter and Setter for m_uuid
        const ngUtils::UUID& File::getUuid() const {
            return m_uuid;
        }

        // Getter and Setter for m_path
        const ngString& File::getPath() const {
            return m_path;
        }

        void File::setPath(const ngString& path) {
            m_path = path;
        }

        // Getter and Setter for m_type
        const ngString& File::getType() const {
            return m_type;
        }

        void File::setType(const ngString& type) {
            m_type = type;
        }

        // Getter and Setter for m_extension
        const ngString& File::getExtension() const {
            return m_extension;
        }

        void File::setExtension(const ngString& extension) {
            m_extension = extension;
        }

        // Getter and Setter for m_modification
        ngStdTimeType File::getModification() const {
            return m_modification;
        }

        void File::setModification(ngStdTimeType modification) {
            m_modification = modification;
        }
}