#include <ThemModdingHerds/TFHRES/Database.hpp>

namespace hiberlite
{ 
    template<>
    std::string Database::getClassName<ThemModdingHerds::TFHResource::CacheRecord>()
    {
        return "cache_record";
    }
    template<>
    std::string Database::getClassName<ThemModdingHerds::TFHResource::CachedImage>()
    {
        return "cached_image";
    }
    template<>
    std::string Database::getClassName<ThemModdingHerds::TFHResource::CachedTextfile>()
    {
        return "cached_textfile";
    }
}

namespace ThemModdingHerds::TFHResource
{
    Database::Database(): hiberlite::Database()
    {
        registerBeanClass<CacheRecord>();
        registerBeanClass<CachedImage>();
        registerBeanClass<CachedTextfile>();
    }
    Database::Database(std::string path): Database()
    {
        open(path);
    }
    void Database::open(std::string path)
    {
        hiberlite::Database::open(path);
        createModel();
    }
}