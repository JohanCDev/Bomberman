cmake_minimum_required(VERSION 3.17)
set(CMAKE_C_COMPILER "C:/TDM-GCC-64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/TDM-GCC-64/bin/g++.exe")
 project(bomberman)

 # Dependencies
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

 set(TARGET_NAME indie)
 add_executable(${TARGET_NAME} ${SRCROOT}src/main.cpp)
 set_target_properties(${TARGET_NAME} PROPERTIES
     RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
 )
 #set(raylib_VERBOSE 1)
 target_link_libraries(${TARGET_NAME} raylib)

 # Checks if OSX and links appropriate frameworks (Only required on MacOS)
 if (APPLE)
     target_link_libraries(${TARGET_NAME} "-framework IOKit")
     target_link_libraries(${TARGET_NAME} "-framework Cocoa")
     target_link_libraries(${TARGET_NAME} "-framework OpenGL")
 endif()