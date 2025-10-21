#include <ThemModdingHerds/TFHRES/Database.hpp>

namespace ThemModdingHerds::TFHResource
{
    Database::Database(const std::string &path): SQLite::Database(path)
    {

    }
}