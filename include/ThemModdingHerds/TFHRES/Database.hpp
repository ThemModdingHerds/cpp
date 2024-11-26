#ifndef __TMH_TFHRES_DATABASE_HPP
#define __TMH_TFHRES_DATABASE_HPP

#include <hiberlite.h>
#include "Data.hpp"

namespace ThemModdingHerds::TFHResource
{
    class Database : public hiberlite::Database
    {
    public:
        Database();
        Database(std::string path);

        void open(std::string path);
    };
}

#endif