#ifndef __TMH_TFHRES_DATA_HPP
#define __TMH_TFHRES_DATA_HPP

#include <hiberlite.h>
#include <string>

namespace ThemModdingHerds::TFHResource
{
    // TEXT = std::string
    // INTEGER = int
    // BLOB = void*
    /* Template:
    class <name>
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            
        }
    };
    */
    class CacheRecord
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            ar & HIBERLITE_NVP(shortname);
            ar & HIBERLITE_NVP(source_path);
        }
    public:
        std::string shortname;
        std::string source_path;
    };
    class CachedImage
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            ar & HIBERLITE_NVP(height);
            ar & HIBERLITE_NVP(image_data);
            ar & HIBERLITE_NVP(is_compressed);
            ar & HIBERLITE_NVP(shortname);
            ar & HIBERLITE_NVP(vram_only);
            ar & HIBERLITE_NVP(width);
        }
    public:
        int height;
        void* image_data;
        int is_compressed;
        std::string shortname;
        int vram_only;
        int width;
    };
    class CachedTextfile
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            ar & HIBERLITE_NVP(shortname);
            ar & HIBERLITE_NVP(source_file);
            ar & HIBERLITE_NVP(text_data);
        }
    public:
        std::string shortname;
        std::string source_file;
        void* text_data;
    };
    class FilemapRecord
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            ar & HIBERLITE_NVP(shortname);
            ar & HIBERLITE_NVP(source_path);
            ar & HIBERLITE_NVP(type);
        }
    public:
        std::string shortname;
        std::string source_path;
        std::string type;
    };
    class ImageBiomeRecord
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            ar & HIBERLITE_NVP(biomename);
            ar & HIBERLITE_NVP(image_shortname);
        }
    public:
        std::string biomename;
        std::string image_shortname;
    };
    class InkBytecode
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            ar & HIBERLITE_NVP(bytecode);
            ar & HIBERLITE_NVP(original);
            ar & HIBERLITE_NVP(shortname);
        }
    public:
        std::string bytecode;
        std::string original;
        std::string shortname;
    };
    class JotBytecode
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            ar & HIBERLITE_NVP(bytecode);
            ar & HIBERLITE_NVP(original);
            ar & HIBERLITE_NVP(shortname);
        }
    public:
        std::string bytecode;
        std::string original;
        std::string shortname;
    };
    class LocalizedText
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            ar & HIBERLITE_NVP(langcode);
            ar & HIBERLITE_NVP(storyfile_dbname);
            ar & HIBERLITE_NVP(tag);
            ar & HIBERLITE_NVP(text);
        }
    public:
        std::string langcode;
        std::string storyfile_dbname;
        std::string tag;
        std::string text;
    };
    class MapBiomeRecord
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            ar & HIBERLITE_NVP(biomename);
            ar & HIBERLITE_NVP(map_shortname);
        }
    public:
        std::string biomename;
        std::string map_shortname;
    };
    class PixelAnimation
    {
        friend class hiberlite::access;
        template<class Archive>
        void hibernate(Archive& ar)
        {
            
        }
    public:
        int animtype;
        std::string atlas_shortname;
    };
}

#endif