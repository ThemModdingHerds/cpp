#include <ThemModdingHerds/GFS/RevergePackage.hpp>
#include <exception>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <iterator>

namespace ThemModdingHerds::GFS
{
    RevergePackage::RevergePackage(HeaderData header,const FileInfos &infos,const Chunks &chunks): mHeader(header), mFileInfos(infos), mChunks(chunks)
    {

    }
    RevergePackage::RevergePackage(HeaderData header): mHeader(header), mFileInfos(), mChunks()
    {

    }
    RevergePackage::RevergePackage(): mHeader(DEFAULT_HEADER), mFileInfos(), mChunks()
    {

    }
    void RevergePackage::RecalculateHeader()
    {
        mHeader.dataOffset = 4 + 8 + mHeader.identifier.length() + 8 + mHeader.version.length() + 8;
        mHeader.nOfFiles = (uint64_t)mFileInfos.size();
        for(uint64_t i = 0;i < mHeader.nOfFiles;i++)
        {
            FileInfoData &info = mFileInfos.at(i);
            mHeader.dataOffset += 8 + info.path.length() + 8 + 4;
        }
    }
    HeaderData RevergePackage::header() const
    {
        return mHeader;
    }
    RevergePackage::FileInfos RevergePackage::fileInfos() const
    {
        return mFileInfos;
    }
    RevergePackage::Chunks RevergePackage::chunks() const
    {
        return mChunks;
    }
    RevergePackage::Chunk RevergePackage::readChunk(const FileInfoData &info)
    {
        for(FileInfos::size_type i = 0;i < mFileInfos.size();i++)
        {
            FileInfoData& data = mFileInfos[i];
            if(data.path == info.path)
                return readChunk(i);
        }
        throw std::exception("couldn't find info");
    }
    RevergePackage::Chunk RevergePackage::readChunk(FileInfos::size_type index)
    {
        return mChunks.at(index);
    }
    RevergePackage& RevergePackage::read(IO::Reader &reader)
    {
        mFileInfos.clear();
        mChunks.clear();
        reader.setEndianness(IO::Endianness::Big);
        mHeader = {
            reader.read<uint32_t>(),
            reader.readString64(),
            reader.readString64(),
            reader.read<uint64_t>()
        };
        std::streampos runningOffset = mHeader.dataOffset;
        for(uint64_t i = 0;i < mHeader.nOfFiles;i++)
        {
            std::string path =reader.readString64();
            uint64_t size = reader.read<uint64_t>();
            uint32_t alignment = reader.read<uint32_t>();

            runningOffset += (alignment - (runningOffset % alignment)) % alignment;

            std::streampos oldOffset = reader.offset();
            reader.setOffset(runningOffset);
            Chunk chunk = reader.readBytes(size);
            reader.setOffset(oldOffset);

            runningOffset += size;
            FileInfoData info = {path,size,alignment};
            mChunks.push_back(chunk);
            mFileInfos.push_back(info);
        }
        return *this;
    }
    RevergePackage& RevergePackage::read(std::string path)
    {
        std::ifstream stream(path,std::ios::binary);
        IO::Reader reader(stream);
        read(reader);
        stream.close();
        return *this;
    }
    RevergePackage& RevergePackage::readFromFolder(std::string path,uint32_t aligment)
    {
        std::filesystem::directory_entry folder(path);
        if(!folder.is_directory())
            throw new std::exception("path is not a directory");
        mHeader = DEFAULT_HEADER;
        mFileInfos.clear();
        mChunks.clear();
        std::filesystem::recursive_directory_iterator it(folder);
        for(auto entry : it)
        {
            if(!entry.is_regular_file()) continue;
            std::filesystem::path filepath = std::filesystem::absolute(entry.path());
            std::filesystem::path relPath = std::filesystem::relative(entry.path(),folder.path());
            std::string entryPath = relPath.string();
            std::replace(entryPath.begin(),entryPath.end(),'\\','/');
            FileInfoData info = {
                entryPath,
                entry.file_size(),
                aligment
            };
            mFileInfos.push_back(info);
            std::ifstream stream(filepath,std::ios::binary);
            Chunk chunk((Chunk::size_type)entry.file_size(),(Types::Byte)0);
            stream.read((char*)&chunk[0],entry.file_size());
            mChunks.push_back(chunk);
            stream.close();
        }
        RecalculateHeader();
        return *this;
    }
    RevergePackage& RevergePackage::readFromFolder(std::string path)
    {
        return readFromFolder(path,1);
    }
    RevergePackage& RevergePackage::write(IO::Writer &writer)
    {
        writer.setEndianness(IO::Endianness::Big);
        RecalculateHeader();
        writer.write<uint32_t>(mHeader.dataOffset);
        writer.writeString64(mHeader.identifier);
        writer.writeString64(mHeader.version);
        writer.write<uint64_t>(mHeader.nOfFiles);
        std::streampos runningOffset = mHeader.dataOffset;
        for(uint64_t i = 0;i < mHeader.nOfFiles;i++)
        {
            FileInfoData &info = mFileInfos.at(i);
            writer.writeString64(info.path);
            writer.write<uint64_t>(info.size);
            writer.write<uint32_t>(info.alignment);
            runningOffset += (info.alignment - (runningOffset % info.alignment)) % info.alignment;
            std::streampos oldOffset = writer.offset();
            writer.setOffset(runningOffset);
            Chunk chunk = readChunk(i);
            writer.writeBytes(chunk);
            writer.setOffset(oldOffset);
            runningOffset += info.size;
        }
        return *this;
    }
    RevergePackage& RevergePackage::write(std::string path)
    {
        std::ofstream stream(path,std::ios::binary);
        IO::Writer writer(stream);
        write(writer);
        stream.close();
        return *this;
    }
}