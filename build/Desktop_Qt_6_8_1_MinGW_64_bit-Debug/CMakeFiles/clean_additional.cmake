# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Amazonka_autogen"
  "CMakeFiles\\Amazonka_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Amazonka_autogen.dir\\ParseCache.txt"
  )
endif()
