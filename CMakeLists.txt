project(ThemModdingHerds)

# Settings

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# 3rd-Party libraries

#add_subdirectory(thirdparty/hiberlite)

# Libraries

add_library(tmhio io/reader.cpp io/writer.cpp)
target_include_directories(tmhio PRIVATE include)

add_library(tmhgfs gfs/revergepackage.cpp)
target_include_directories(tmhgfs PRIVATE include)
target_link_libraries(tmhgfs PRIVATE tmhio)
add_dependencies(tmhgfs tmhio)

#add_library(tmhtfhres tfhres/database.cpp)
#target_include_directories(tmhtfhres PRIVATE include thirdparty/hiberlite/include)
#target_link_libraries(tmhtfhres PRIVATE hiberlite)
#add_dependencies(tmhtfhres hiberlite)

# Executables

add_executable(tmhgfscli cli/gfs.cpp)
target_include_directories(tmhgfscli PRIVATE include)
target_link_libraries(tmhgfscli PRIVATE tmhgfs tmhio)
add_dependencies(tmhgfscli tmhgfs tmhio)

# Testing

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    add_executable(tmhtest tests/test.cpp)
    target_include_directories(tmhtest PRIVATE include)
    target_link_libraries(tmhtest PRIVATE tmhio tmhgfs)
endif()