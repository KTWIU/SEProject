# CMake generated Testfile for 
# Source directory: C:/Projekte/Projekt/repo
# Build directory: C:/Projekte/Projekt/repo/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(simple_test "C:/Projekte/Projekt/repo/build/simple_test.exe")
set_tests_properties(simple_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Projekte/Projekt/repo/CMakeLists.txt;51;add_test;C:/Projekte/Projekt/repo/CMakeLists.txt;0;")
subdirs("googletest")
