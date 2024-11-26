#ifndef __TMH_GFS_DATA_HPP
#define __TMH_GFS_DATA_HPP

#include <cstdint>
#include <string>
#include <ostream>

#define REVERGEPACKAGE_IDENTIFIER "Reverge Package File"
#define REVERGEPACKAGE_VERSION "1.1"

namespace ThemModdingHerds::GFS
{
    /**
     * @brief Header data of a Reverge Package File
     */
    struct HeaderData
    {
        /**
         * @brief The offset to the binary data of the files after the header and entries
         */
        uint32_t dataOffset;
        /**
         * @brief The identifier of the Reverge Package as a 64-bit Pascal string, normally it's "Reverge Package File"
         */
        std::string identifier;
        /**
         * @brief The version of the Reverge Package as a 64-bit Pascal string, normally it's "1.1"
         */
        std::string version;
        /**
         * @brief The count of files existing in the Reverge Package
         */
        uint64_t nOfFiles;
    };
    /**
     * @brief Default value of `HeaderData`
     */
    const HeaderData DEFAULT_HEADER = {
        51,
        REVERGEPACKAGE_IDENTIFIER,
        REVERGEPACKAGE_VERSION,
        0
    };
    /**
     * @brief Information about a specific file in a Reverge Package File
     */
    struct FileInfoData
    {
        /**
         * @brief The relative path of the file
         */
        std::string path;
        /**
         * @brief The size of the file in bytes
         */
        uint64_t size;
        /**
         * @brief The aligment of the file data between other file datas/header
         */
        uint32_t alignment;
    };
    inline std::ostream& operator<<(std::ostream& os,const HeaderData &header)
    {
        os << "0x" << std::hex << header.dataOffset << ';' << header.identifier << ';' << header.version << ';' << header.nOfFiles;
        return os;
    }
    inline std::ostream& operator<<(std::ostream& os,const FileInfoData &info)
    {
        os << info.path << ';' << info.size << ';' << info.alignment;
        return os;
    }
}

#endif