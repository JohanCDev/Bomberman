cmake_minimum_required(VERSION 3.17)

project(IndieStudio LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)

if (NOT WIN32)
    add_compile_options(
        "-Wall" "-Wextra" "-Wshadow" "-pedantic" "-Wpointer-arith"
    )
endif()

add_subdirectory(src)