set(INCROOT ${PROJECT_SOURCE_DIR}/include/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)
set(ECSROOT ${SRCROOT}ecs/)
set(RAYLIBROOT ${SRCROOT}raylib/)

set(SRC
    ${SRCROOT}/main.cpp
    ${ECSROOT}component/Component.hpp
    ${ECSROOT}entity/Entity.cpp
    ${ECSROOT}entity/Entity.hpp
    ${ECSROOT}system/System.hpp
    ${RAYLIBROOT}/Raylib.hpp
    ${RAYLIBROOT}/Window.cpp
    ${RAYLIBROOT}/Window.hpp
    ${RAYLIBROOT}/Draw.cpp
    ${RAYLIBROOT}/Draw.hpp
    ${RAYLIBROOT}/Event.cpp
    ${RAYLIBROOT}/Event.hpp
    ${RAYLIBROOT}/Sound.cpp
    ${RAYLIBROOT}/Sound.hpp
    ${RAYLIBROOT}/Rectangle.cpp
    ${RAYLIBROOT}/Rectangle.hpp
    ${RAYLIBROOT}/Cube.cpp
    ${RAYLIBROOT}/Cube.hpp
    ${RAYLIBROOT}/Sphere.cpp
    ${RAYLIBROOT}/Sphere.hpp
    ${RAYLIBROOT}/Camera3D.cpp
    ${RAYLIBROOT}/Camera3D.hpp
)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_link_libraries(${PROJECT_NAME} PUBLIC ${INTERFACES_NAME})
# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
