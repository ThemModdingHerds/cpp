#include <ThemModdingHerds/IO/Reader.hpp>
#include <iostream>
#include <fstream>

int main(int argc,char** argv)
{
    std::ifstream file(argv[0]);
    ThemModdingHerds::IO::Reader reader(file);
    uint32_t value = reader.read<uint32_t>();
    // 7887437
    std::cout << value << std::endl;
    return EXIT_SUCCESS;
}