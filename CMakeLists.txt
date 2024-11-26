project(ThemModdingHerds)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(thirdparty/hiberlite)

add_library(tmhio io/reader.cpp io/writer.cpp)
target_include_directories(tmhio PRIVATE include)

add_library(tmhgfs gfs/revergepackage.cpp)
target_include_directories(tmhgfs PRIVATE include)

add_library(tmhtfhres tfhres/database.cpp)
target_include_directories(tmhtfhres PRIVATE include thirdparty/hiberlite/include)
target_link_libraries(tmhtfhres PRIVATE hiberlite)
add_dependencies(tmhtfhres hiberlite)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    add_executable(tmhtest tests/test.cpp)
    target_include_directories(tmhtest PRIVATE include)
    target_link_libraries(tmhtest PRIVATE tmhio tmhgfs tmhtfhres hiberlite)
endif()