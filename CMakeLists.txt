set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

cmake_minimum_required(VERSION 3.16)

project(AufgabenTracker LANGUAGES CXX)

if (MSVC)
  add_compile_options(/std:c++17 /Zc:__cplusplus)
endif()


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.6.2/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(AufgabenTracker
    main.cpp
    Task.cpp
    Task.h
    TaskManager.cpp
    TaskManager.h
    TaskController.h
    TaskController.cpp
    TaskFactory.h
    TaskFactory.cpp  
    ../Aufgabenplaner/mainwindow.cpp
    ../Aufgabenplaner/mainwindow.h
    ../Aufgabenplaner/mainwindow.ui
    ../Aufgabenplaner/dialogtaskbearbeiten.cpp
    ../Aufgabenplaner/dialogtaskbearbeiten.h
    ../Aufgabenplaner/dialogtaskbearbeiten.ui
    ../Aufgabenplaner/dialogtaskhinzufuegen.cpp
    ../Aufgabenplaner/dialogtaskhinzufuegen.h
    ../Aufgabenplaner/dialogtaskhinzufuegen.ui
    ../Aufgabenplaner/erledigteaufgabenliste.cpp
    ../Aufgabenplaner/erledigteaufgabenliste.h
    ../Aufgabenplaner/erledigteaufgabenliste.ui
    ../Aufgabenplaner/ueberfaelligeaufgaben.cpp
    ../Aufgabenplaner/ueberfaelligeaufgaben.h
    ../Aufgabenplaner/ueberfaelligeaufgaben.ui
)

target_link_libraries(AufgabenTracker Qt6::Widgets)

# Test-Setup
add_subdirectory(googletest)
add_executable(simple_test 
  test_simple.cpp
  Task.cpp
  TaskManager.cpp
  TaskController.cpp
  TaskFactory.cpp)
target_link_libraries(simple_test PRIVATE Qt6::Core gtest gtest_main)
enable_testing()
add_test(NAME simple_test COMMAND simple_test)
