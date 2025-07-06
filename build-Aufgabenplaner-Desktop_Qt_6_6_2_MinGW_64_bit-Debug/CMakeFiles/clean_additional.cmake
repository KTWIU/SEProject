# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Aufgabenplaner_autogen"
  "CMakeFiles\\Aufgabenplaner_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Aufgabenplaner_autogen.dir\\ParseCache.txt"
  )
endif()
