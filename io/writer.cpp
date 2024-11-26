#include <ThemModdingHerds/IO/Writer.hpp>

namespace ThemModdingHerds::IO
{
    Writer::Writer(std::ostream &stream): mStream(stream)
    {

    }
    Writer::Writer(std::ostream &stream,Endianness endianness): mStream(stream), mEndianness(endianness)
    {

    }
    Endianness Writer::endianness() const
    {
        return mEndianness;
    }
    Writer& Writer::setEndianness(Endianness endianness)
    {
        mEndianness = endianness;
        return *this;
    }
    std::streampos Writer::offset()
    {
        return mStream.tellp();
    }
    Writer& Writer::setOffset(std::streampos offset)
    {
        mStream.seekp(offset,std::ios::beg);
        return *this;
    }
    Writer& Writer::write(const void* input,std::streamsize size)
    {
        char* temp = new char[size];
        // do we need to swap the values from the input?
        for(std::streamsize i = 0;i < size;i++) // swap if needed
            temp[i] = ((const char*)input)[i];
        if(mEndianness != getSystemEndianness())
            swap_endian((const char*)input,temp,size);
        // write the bytes
        mStream.write(temp,size);
        delete[] temp;
        return *this;
    }
    Writer& Writer::writeString(std::string str)
    {
        mStream.write(&str[0],str.length());
        return *this;
    }
    Writer& Writer::writeString64(std::string str)
    {
        write<uint64_t>(str.length());
        return writeString(str);
    }
    Writer& Writer::writeString32(std::string str)
    {
        write<uint32_t>(str.length());
        return writeString(str);
    }
    Writer& Writer::writeString16(std::string str)
    {
        write<uint16_t>(str.length());
        return writeString(str);
    }
    Writer& Writer::writeString8(std::string str)
    {
        write<uint8_t>(str.length());
        return writeString(str);
    }
    Writer& Writer::writeBytes(const Types::Bytes &bytes)
    {
        for(auto byte : bytes)
            mStream.write((const char*)&byte,sizeof(byte));
        return *this;
    }
}
