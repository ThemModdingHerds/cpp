#include <ThemModdingHerds/TFHRES/Database.hpp>

namespace ThemModdingHerds::TFHResource
{
    static void registerBeans(hiberlite::Database &db)
    {
        db.registerBeanClass<cache_record>();
    }
    static void open(hiberlite::Database &db,const std::string &path)
    {
        db.open(path);
        create(db);
    }
    static void create(hiberlite::Database &db)
    {
        registerBeans(db);
    }
}