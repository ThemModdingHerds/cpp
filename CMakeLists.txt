project(ThemModdingHerds)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(tmhio io/reader.cpp)
target_include_directories(tmhio PRIVATE include)

if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    add_executable(testreader tests/reader.cpp)
    target_include_directories(testreader PRIVATE include)
    target_link_libraries(testreader PRIVATE tmhio)
endif()