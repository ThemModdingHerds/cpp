#include <ThemModdingHerds/GFS/RevergePackage.hpp>
#include <filesystem>
#include <iostream>

static void printHelp()
{
    std::cout << "Usage: tmhgfscli <path> [<alignment>]" << std::endl;
}

int main(int argc,char** argv)
{
    if(argc < 2)
    {
        printHelp();
        return EXIT_FAILURE;
    }
    char* arg = argv[1];
    std::filesystem::path path = std::filesystem::relative(arg,std::filesystem::current_path());
    std::cout << "path: " << path << std::endl;
    uint32_t alignment = argc > 2 ? std::stoi(argv[2]) : 1;
    std::cout << "alignment: " << alignment << std::endl;
    ThemModdingHerds::GFS::RevergePackage gfs;
    if(std::filesystem::is_regular_file(path))
    {
        std::cout << "reading file at " << path << std::endl;
        gfs.read(path);
        gfs.extract(path.replace_extension(""));
        return EXIT_SUCCESS;
    }
    if(std::filesystem::is_directory(path))
    {
        std::cout << "reading folder at " << path << " with alignment " << alignment << std::endl;
        gfs.readFromFolder(path,alignment);
        gfs.write(path.replace_extension(REVERGEPACKAGE_EXTENSION));
        return EXIT_SUCCESS;
    }
    std::cerr << "The path provided is not a valid path" << std::endl;
    return EXIT_FAILURE;
}