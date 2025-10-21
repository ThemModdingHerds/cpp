#ifndef __TMH_GFS_REVERGEPACKAGE_HPP
#define __TMH_GFS_REVERGEPACKAGE_HPP

#include <vector>
#include <filesystem>
#include <ostream>

#include "Data.hpp"
#include "../IO/Reader.hpp"
#include "../IO/Writer.hpp"

namespace ThemModdingHerds::GFS
{
    /**
     * @brief Archive file format containing entries of files and their data offsetted by an alignment  
     * The structure of a Reverge Package File looks like this:
     * - HeaderData
     * - FileInfoData x HeaderData.nOfFiles
     * - binary data offsetted by data size and their alignment
     */
    class RevergePackage
    {
    public:
        /**
         * @brief Represents a collection of entries
         */
        typedef std::vector<FileInfoData> FileInfos;
        /**
         * @brief Represents a chunk of data of a entry
         */
        typedef Types::Bytes Chunk;
        /**
         * @brief Represents a collection of chunks from entries
         */
        typedef std::vector<Chunk> Chunks;
    private:
        /**
         * @brief The header data of this Reverge Package
         */
        HeaderData mHeader;
        /**
         * @brief The entries of this Reverge Package
         */
        FileInfos mFileInfos;
        /**
         * @brief The binary data that the entries are from
         */
        Chunks mChunks;
        /**
         * @brief Recalculates the header dataOffset and number of files based on the entries' data size
         */
        void RecalculateHeader();
    public:
        /**
         * @brief Construct a new Reverge Package with `header`, entries `infos` and their `chunks`
         * 
         * @param header The header of the Reverge Package
         * @param infos The entries of the Reverge Package
         * @param chunks The chunks of the entries
         */
        RevergePackage(HeaderData header,const FileInfos &infos,const Chunks &chunks);
        /**
         * @brief Construct a new Reverge Package with only the `header` (no entries and chunks)
         * @param header The header of the Reverge Package
         */
        RevergePackage(HeaderData header);
        /**
         * @brief Construct a new Default Reverge Package, useful for reading one from a stream/file
         */
        RevergePackage();
        /**
         * @brief Get the header data of this Reverge Package
         * @return The header data of this Reverge Package
         */
        HeaderData header() const;
        /**
         * @brief Get the entries of this Reverge Package
         * @return The entries of this Reverge Package
         */
        FileInfos fileInfos() const;
        /**
         * @brief Get the chunks of the entries of this Reverge Package
         * @return The chunks of the entries of this Reverge Package
         */
        Chunks chunks() const;
        /**
         * @brief Read a chunk from a entry `info`
         * @param info The entry info from this Reverge Package
         * @return Chunk data of the entry
         */
        Chunk readChunk(const FileInfoData &info);
        /**
         * @brief Read a chunk from a index
         * @param index The entry index from this Reverge Package
         * @return Chunk of the entry
         */
        Chunk readChunk(FileInfos::size_type index);
        /**
         * @brief Clear the data and read new data from a `reader`
         * @param reader The reader to use
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& read(IO::Reader &reader);
        /**
         * @brief Clear the data and read new data from a file at `path`
         * @param path The path to a file
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& read(std::string path);
        /**
         * @brief Clear the data and read new data from a file at `path`
         * @param path The path to a file
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& read(std::filesystem::path path);
        /**
         * @brief Clear the data and create a Reverge Package from a folder at `path` with `aligment`
         * @param path The path to a folder
         * @param aligment The aligment of each entry
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& readFromFolder(std::string path,uint32_t aligment);
        /**
         * @brief Clear the data and create a Reverge Package from a folder at `path` with `aligment`
         * @param path The path to a folder
         * @param aligment The aligment of each entry
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& readFromFolder(std::filesystem::path path,uint32_t alignment);
        /**
         * @brief Clear the data and create a Reverge Package from a folder at `path` with aligment `1`
         * @param path The path to a folder
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& readFromFolder(std::string path);
        /**
         * @brief Clear the data and create a Reverge Package from a folder at `path` with aligment `1`
         * @param path The path to a folder
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& readFromFolder(std::filesystem::path path);
        /**
         * @brief Write the current Reverge Package to a `writer`. It will delete the data inside the writer
         * @param writer The writer to use
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& write(IO::Writer &writer);
        /**
         * @brief Write the current Reverge Package to a file at `path`. It will delete the file at that path
         * @param path The path to a file
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& write(std::string path);
        /**
         * @brief Write the current Reverge Package to a file at `path`. It will delete the file at that path
         * @param path The path to a file
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& write(std::filesystem::path path);
        /**
         * @brief Extract content of this Reverge Package to the folder at `path`
         * @param path The path to a folder
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& extract(std::string path);
        /**
         * @brief Extract content of this Reverge Package to the folder at `path`
         * @param path The path to a folder
         * @return this Reverge Package for self-chaining
         */
        RevergePackage& extract(std::filesystem::path path);
    };
    inline std::ostream& operator<<(std::ostream& os,const RevergePackage &gfs)
    {
        os << gfs.header();
        return os;
    }
}


#endif