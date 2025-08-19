# CMake generated Testfile for 
# Source directory: C:/Projekte/Projekt/repo
# Build directory: C:/Projekte/Projekt/repo/build_release
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(simple_test "C:/Projekte/Projekt/repo/build_release/simple_test.exe")
set_tests_properties(simple_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Projekte/Projekt/repo/CMakeLists.txt;59;add_test;C:/Projekte/Projekt/repo/CMakeLists.txt;0;")
subdirs("googletest")
