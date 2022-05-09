set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)

find_package(raylib QUIET)

set(TARGET_NAME indie)
add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp)
set_target_properties(${TARGET_NAME} PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)

target_link_libraries(${TARGET_NAME} PRIVATE raylib)

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${TARGET_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${TARGET_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${TARGET_NAME} PRIVATE "-framework OpenGL")
endif()