# Cmake version
cmake_minimum_required(VERSION 3.17)

# Project name
project(IndieStudio)

# Variables
set(TARGET_NAME indie)
set(CMAKE_CXX_STANDARD 17)

# Paths
set(ECS_PATH ecs)


# Include directories
include_directories(${ECS_PATH}/component/)
include_directories(${ECS_PATH}/entity/)
include_directories(${ECS_PATH}/raylib/)
include_directories(${ECS_PATH}/system/)

# Source files
set(ECS_SRCS
  ${ECS_PATH}/entity/Entity.cpp
  ${ECS_PATH}/raylib/Raylib.cpp
)

set(INDIE_SRCS
        ${ECS_SRCS}
  )
# Compilation
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/)

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

add_executable(${TARGET_NAME} main.cpp ${INDIE_SRCS})

target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)
target_link_libraries(${TARGET_NAME} raylib)