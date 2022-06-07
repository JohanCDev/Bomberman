# Cmake version
cmake_minimum_required(VERSION 3.17)
project(bomberman)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/)

if (MSVC)
    add_compile_options(/W2)
else ()
    add_compile_options(-Wall -Wshadow -Wno-unused -Wno-deprecated-copy -Wno-deprecated-declarations)
endif ()

find_package(raylib REQUIRED)
set(INCROOT ${PROJECT_SOURCE_DIR}/include/)

set(SRC_INTERFACE
    ${INCROOT}Colors.hpp
    ${INCROOT}events.hpp
    ${INCROOT}vec2.hpp
    ${INCROOT}vec3.hpp
    ${INCROOT}vec4.hpp
)

set(INTERFACES_NAME interface)

add_library(${INTERFACES_NAME} INTERFACE)

target_include_directories(${INTERFACES_NAME} INTERFACE ${INCROOT})

add_subdirectory(src)