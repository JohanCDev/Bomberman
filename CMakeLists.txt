# Cmake version
cmake_minimum_required(VERSION 3.17)

# Project name
project(IndieStudio)

# Variables
set(TARGET_NAME indie)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SRCROOT)

# Raylib start

add_compile_definitions(_USE_MATH_DEFINES)

find_package(raylib 4.0.0 QUIET)
 if (NOT raylib_FOUND)
   include(FetchContent)
   FetchContent_Declare(
     raylib
     URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
   )
   FetchContent_GetProperties(raylib)
   if (NOT raylib_POPULATED)
     set(FETCHCONTENT_QUIET NO)
     FetchContent_Populate(raylib)
     set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
     add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
   endif()
 endif()

# Raylib end

add_subdirectory(src)
