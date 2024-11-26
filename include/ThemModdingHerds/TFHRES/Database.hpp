#ifndef __TMH_TFHRES_DATABASE_HPP
#define __TMH_TFHRES_DATABASE_HPP

#include <hiberlite.h>
#include "Data.hpp"

namespace ThemModdingHerds::TFHResource
{
    /**
     * @brief Open a TFHResource database at path for `db`
     * @param db The hiberlite Database to use
     * @param path The path to the TFHResource database file
     */
    static void open(hiberlite::Database &db,const std::string &path);
    /**
     * @brief Create a TFHResource database for `db`
     * @param db The hiberlite Database to use
     */
    static void create(hiberlite::Database &db);
}

#endif