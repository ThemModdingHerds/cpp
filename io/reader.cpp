#include <ThemModdingHerds/IO/Reader.hpp>

namespace ThemModdingHerds::IO
{
    Reader::Reader(std::istream &stream): mStream(stream)
    {
        // assigns directly the stream into the member
    }
    Endianness Reader::endianness() const
    {
        return mEndianness;
    }
    Reader& Reader::setEndianness(Endianness endianness)
    {
        mEndianness = endianness;
        return *this;
    }
    void Reader::read(void* input,std::streamsize size)
    {
        // read the bytes
        mStream.read((char*)input,size);
        // do we need to swap the values from the input?
        if(mEndianness != getSystemEndianness())
        for(std::streamsize i = 0;i < size;i++) // swap those bytes!
            ((char*)input)[i] = ((char*)input)[i-size-1];
    }
    std::string Reader::readString(std::string::size_type length)
    {
        std::string str(length,'\0');
        read(&str[0],length * sizeof(std::string::value_type));
        return str;
    }
    std::string Reader::readString64()
    {
        uint64_t length = read<uint64_t>();
        return readString(length);
    }
    std::string Reader::readString32()
    {
        uint32_t length = read<uint32_t>();
        return readString(length);
    }
    std::string Reader::readString16()
    {
        uint16_t length = read<uint16_t>();
        return readString(length);
    }
    std::string Reader::readString8()
    {
        uint8_t length = read<uint8_t>();
        return readString(length);
    }
}