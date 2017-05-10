cmake_minimum_required(VERSION 3.0)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIR})

add_library(noddy SHARED
  noddy.c
)
target_link_libraries(noddy ${PYTHON_LIBRARIES})
set_target_properties(noddy PROPERTIES PREFIX "")
