cmake_minimum_required(VERSION 3.16)

project(AufgabenTracker LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.6.2/mingw_64/lib/cmake")


find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(AufgabenTracker main.cpp)
target_link_libraries(AufgabenTracker Qt6::Widgets)


