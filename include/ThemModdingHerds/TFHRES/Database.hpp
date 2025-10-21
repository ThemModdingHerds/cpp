#ifndef __TMH_TFHRES_DATABASE_HPP
#define __TMH_TFHRES_DATABASE_HPP

#include "Data.hpp"
#include "SQLiteCpp/Database.h"

namespace ThemModdingHerds::TFHResource
{
    class Database : SQLite::Database
    {
    public:
        Database(const std::string &path);
    };
}

#endif