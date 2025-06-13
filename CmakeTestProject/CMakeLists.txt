cmake_minimum_required(VERSION 4.0.1)

# CACHE type "docstring" -> setting global variable
set(CMAKE_CXX_STANDARD 11 CACHE STRING "C++ standard to be used")
set(CMAKE_CXX_EXTENSIONS ON CACHE BOOL "c++ extensions to be used")
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "c++ standard required")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON CACHE BOOL "windows export all symbols to be used")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CACHE STRING "set runtime output directory")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" CACHE STRING "set library output directory")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib" CACHE STRING "set archive output directory")





project(CMakeTestProject)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(./dynamiclib)
add_subdirectory(./staticlib1)
add_subdirectory(./staticlib2)
add_subdirectory(./project1)
add_subdirectory(./project2_link_lib)
add_subdirectory(./project3_link_staticlib)
add_subdirectory(./project4_link_dynamiclib)

