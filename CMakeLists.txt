cmake_minimum_required(VERSION 3.0)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMake
                              ${CMAKE_SOURCE_DIR}/CMake/common)

find_package(PythonLibs REQUIRED)
find_package(NumPy REQUIRED)
include_directories(
  ${PYTHON_INCLUDE_DIR}
  ${PYTHON_NUMPY_INCLUDE_DIR}
)

add_library(noddy SHARED
  noddy.c
)
target_link_libraries(noddy ${PYTHON_LIBRARIES})
set_target_properties(noddy PROPERTIES PREFIX "")

add_library(mynum SHARED
  mynum.c
)
target_link_libraries(mynum ${PYTHON_LIBRARIES})
set_target_properties(mynum PROPERTIES PREFIX "")
