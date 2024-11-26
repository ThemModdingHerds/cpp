#include <ThemModdingHerds/TFHRES/Database.hpp>
#include <iostream>
#include <fstream>

int main(int argc,char** argv)
{
    hiberlite::Database db;
    ThemModdingHerds::TFHResource::create(db);
    db.open("output.tfhres");
    return EXIT_SUCCESS;
}