#ifndef __TMH_TFHRES_DATA_HPP
#define __TMH_TFHRES_DATA_HPP

#include "ThemModdingHerds/Types/Data.hpp"
#include <string>

namespace ThemModdingHerds::TFHResource
{
    typedef int Integer;
    typedef std::string Text;
    typedef Types::Bytes Blob;
    struct CacheRecord
    {
        Integer hiberlite_id;
        Text shortname;
        Text source_path;
    };
    struct CachedImage
    {
        Integer height;
        Integer hiberlite_id;
        Blob image_data;
        Integer is_compressed;
        Text shortname;
        Integer vram_only;
        Integer width;
    };
    struct CachedTextfile
    {
        
    };
}

#endif