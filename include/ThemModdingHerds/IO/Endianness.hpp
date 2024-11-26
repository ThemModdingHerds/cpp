#ifndef __TMH_IO_ENDIANNESS_HPP
#define __TMH_IO_ENDIANNESS_HPP

#include <bit>
#include <ostream>

namespace ThemModdingHerds::IO
{
    /**
     * @brief The byte order of a data sequence
     */
    enum struct Endianness
    {
        Little,
        Big,
        Both
    };
    inline std::ostream& operator<<(std::ostream& os,const Endianness &endianness)
    {
        switch(endianness)
        {
            case Endianness::Little:
                os << "Little";
                break;
            case Endianness::Big:
                os << "Big";
                break;
            case Endianness::Both:
                os << "Both";
                break;
            default:
                os << "Unknown";
                break;
        }
        return os;
    }
    /**
     * @brief Get the endianness of the current running system
     * 
     * @return The systems endianness
     */
    inline Endianness getSystemEndianness()
    {
        // is system big endian?
        if constexpr(std::endian::native == std::endian::big)
            return Endianness::Big;
        // is system little endian?
        if constexpr(std::endian::native == std::endian::little)
            return Endianness::Little;
        return Endianness::Both; // I know there's both or something like that but this can cause issues
    }
    template<typename T>
    inline T swap_endian(T u)
    {
        union {
            T u;
            unsigned char u8[sizeof(T)];
        } source, dest;
        source.u = u;
        for(size_t k = 0;k < sizeof(T);k++)
            dest.u8[k] = source.u8[sizeof(T) - k - 1];
        return dest.u;
    }
    inline void swap_endian(const char* input,char* output,size_t size)
    {
        for(size_t k = 0;k < size;k++)
            output[k] = input[size-k-1];
    }
}

#endif