#ifndef __TMH_IO_READER_HPP
#define __TMH_IO_READER_HPP

#include "Endianness.hpp"

#include <istream>
#include <string>

namespace ThemModdingHerds::IO
{
    /**
     * @brief Stream Reader that respects byte order
     */
    class Reader
    {
    private:
        /**
         * @brief The active used stream
         */
        std::istream &mStream;
        /**
         * @brief The byte order of this stream
         */
        Endianness mEndianness;
    public:
        /**
         * @brief Create a Reader from a existing stream
         * @param stream The std::istream to use
         */
        Reader(std::istream &stream);
        /**
         * @brief Returns the reader's byte order
         * @return the byte order of this reader
         */
        Endianness endianness() const;
        /**
         * @brief Sets a new byte order for this reader
         * @param endianness The new byte order to relate from
         * @return this reader for self-chaining
         */
        Reader& setEndianness(Endianness endianness);
        /**
         * @brief Read a chunk with `size` into `input`
         * @param input Pointer to valid data
         * @param size The size of the valid data
         */
        void read(void* input,std::streamsize size);
        /**
         * @brief Read a `T` and return the value
         * @tparam Type to read as
         * @return Value of type `T`
         */
        template<typename T>
        T read()
        {
            T value;
            read((void*)&value,sizeof(T));
            return value;
        }
        /**
         * @brief Read a byte string with `length`
         * @param length The length of the string
         * @return The string read from the stream with `length`
         */
        std::string readString(std::string::size_type length);
        /**
         * @brief Read a Pascal string with a 64-bit prefixed length
         * @return The Pascal string
         */
        std::string readString64();
        /**
         * @brief Read a Pascal string with a 32-bit prefixed length
         * @return The Pascal string
         */
        std::string readString32();
        /**
         * @brief Read a Pascal string with a 16-bit prefixed length
         * @return The Pascal string
         */
        std::string readString16();
        /**
         * @brief Read a Pascal string with a 8-bit prefixed length
         * @return The Pascal string
         */
        std::string readString8();
    };
}

#endif