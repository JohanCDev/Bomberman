# Cmake version
cmake_minimum_required(VERSION 3.17)
project(bomberman)

SET(CMAKE_BUILD_TYPE Release)

if (EMSCRIPTEN)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
endif ()

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