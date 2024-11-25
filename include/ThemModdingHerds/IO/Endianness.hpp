#ifndef __TMH_IO_ENDIANNESS_HPP
#define __TMH_IO_ENDIANNESS_HPP

#include <bit>

namespace ThemModdingHerds::IO
{
    /**
     * @brief The byte order of a data sequence
     */
    enum struct Endianness
    {
        Little,
        Big
    };
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
        return Endianness::Little; // I know there's both or something like that but let's just keep it little
    }
}

#endif