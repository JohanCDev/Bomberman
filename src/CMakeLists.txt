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
    ${RAYLIBROOT}/boundingbox/BoundingBox.cpp
    ${RAYLIBROOT}/boundingbox/BoundingBox.hpp
    ${RAYLIBROOT}/camera3d/Camera3D.cpp
    ${RAYLIBROOT}/camera3d/Camera3D.hpp
    ${RAYLIBROOT}/circle/Circle.cpp
    ${RAYLIBROOT}/circle/Circle.hpp
    ${RAYLIBROOT}/cube/Cube.cpp
    ${RAYLIBROOT}/cube/Cube.hpp
    ${RAYLIBROOT}/draw/Draw.cpp
    ${RAYLIBROOT}/draw/Draw.hpp
    ${RAYLIBROOT}/event/Event.cpp
    ${RAYLIBROOT}/event/Event.hpp
    ${RAYLIBROOT}/line/Line.cpp
    ${RAYLIBROOT}/line/Line.hpp
    ${RAYLIBROOT}/pixel/Pixel.cpp
    ${RAYLIBROOT}/pixel/Pixel.hpp
    ${RAYLIBROOT}/rectangle/Rectangle.cpp
    ${RAYLIBROOT}/rectangle/Rectangle.hpp
    ${RAYLIBROOT}/sound/Sound.cpp
    ${RAYLIBROOT}/sound/Sound.hpp
    ${RAYLIBROOT}/sphere/Sphere.cpp
    ${RAYLIBROOT}/sphere/Sphere.hpp
    ${RAYLIBROOT}/triangle/Triangle.cpp
    ${RAYLIBROOT}/triangle/Triangle.hpp
    ${RAYLIBROOT}/window/Window.cpp
    ${RAYLIBROOT}/window/Window.hpp
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
