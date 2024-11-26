#ifndef __TMH_TYPES_DATA_HPP
#define __TMH_TYPES_DATA_HPP

#include <vector>
#include <cstddef>
#include <ostream>

namespace ThemModdingHerds::Types
{
    /**
     * @brief Represents a byte of data
     */
    typedef std::byte Byte;
    /**
     * @brief Represents a byte range
     */
    typedef std::vector<Byte> Bytes;
    inline std::ostream& operator<<(std::ostream& os,const Byte &byte)
    {
        os << std::hex << byte;
        return os;
    }
    inline std::ostream& operator<<(std::ostream& os,const Bytes &bytes)
    {
        for(auto byte : bytes)
            os << byte;
        return os;
    }
}

#endif