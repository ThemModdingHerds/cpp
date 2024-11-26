#ifndef __TMH_IO_WRITER_HPP
#define __TMH_IO_WRITER_HPP

#include "Endianness.hpp"
#include "../Types/Data.hpp"

#include <ostream>
#include <string>

namespace ThemModdingHerds::IO
{
    /**
     * @brief Stream Writer that respects byte order
     */
    class Writer
    {
    private:
        /**
         * @brief The active used stream
         */
        std::ostream &mStream;
        /**
         * @brief The byte order of this stream
         */
        Endianness mEndianness;
    public:
        /**
         * @brief Create a writer from a exisiting stream
         * @param stream the std::ostream to use
         */
        Writer(std::ostream &stream);
        /**
         * @brief Create a Writer from a existing stream with a specific byte order
         * @param stream The std::ostream to use
         * @param endianness The byte order of the stream
         */
        Writer(std::ostream &stream,Endianness endianness);
        /**
         * @brief Returns the reader's byte order
         * @return the byte order of this reader
         */
        Endianness endianness() const;
        /**
         * @brief Get current read position in stream
         * @return The read offset
         */
        std::streampos offset();
        /**
         * @brief Sets a new read position for this reader
         * @param offset The new offset from beginning
         * @return this reader for self-chaining
         */
        Writer& setOffset(std::streampos offset);
        /**
         * @brief Sets a new byte order for this reader
         * @param endianness The new byte order to relate from
         * @return this reader for self-chaining
         */
        Writer& setEndianness(Endianness endianness);
        /**
         * @brief Write `input` with `size` into stream
         * @param input The input buffer to write into the stream
         * @param size The size of the input buffer
         * @return this writer for self-chaining
         */
        Writer& write(const void* input,std::streamsize size);
        /**
         * @brief Write `value` as `T` into stream
         * @tparam T Type of value
         * @param value The value to write to stream
         * @return this writer for self-chaining
         */
        template<typename T>
        Writer& write(const T &value)
        {
            return write(&value);
        }
        /**
         * @brief Write `ptr` as a pointer `T` into stream
         * @tparam T Type of value
         * @param ptr The pointer to a value
         * @return this writer for self-chaining
         */
        template<typename T>
        Writer& write(const T *ptr)
        {
            return write(ptr,sizeof(T));
        }
        /**
         * @brief Write `str` to stream by bytes
         * @param str The string to write
         * @return this writer for self-chaining
         */
        Writer& writeString(std::string str);
        /**
         * @brief Write `str` as a 64-bit Pascal string to stream
         * @param str The string to write
         * @return this writer for self-chaining
         */
        Writer& writeString64(std::string str);
        /**
         * @brief Write `str` as a 32-bit Pascal string to stream
         * @param str The string to write
         * @return this writer for self-chaining
         */
        Writer& writeString32(std::string str);
        /**
         * @brief Write `str` as a 16-bit Pascal string to stream
         * @param str The string to write
         * @return this writer for self-chaining
         */
        Writer& writeString16(std::string str);
        /**
         * @brief Write `str` as a 8-bit Pascal string to stream
         * @param str The string to write
         * @return this writer for self-chaining
         */
        Writer& writeString8(std::string str);
        /**
         * @brief Writes `bytes` into stream
         * @param bytes the array of bytes to write
         * @return this writer for self-chaining
         */
        Writer& writeBytes(const Types::Bytes &bytes);
    };
}

#endif