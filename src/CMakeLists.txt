set(INCROOT ${PROJECT_SOURCE_DIR}/include/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)
set(ECSROOT ${SRCROOT}ecs/)

set(SRC
    ${SRCROOT}/main.cpp
    ${ECSROOT}component/Component.hpp
    ${ECSROOT}entity/Entity.cpp
    ${ECSROOT}entity/Entity.hpp
    ${ECSROOT}raylib/Raylib.hpp
    ${ECSROOT}raylib/Window.cpp
    ${ECSROOT}raylib/Window.hpp
    ${ECSROOT}raylib/Draw.cpp
    ${ECSROOT}raylib/Draw.hpp
    ${ECSROOT}raylib/Event.cpp
    ${ECSROOT}raylib/Event.hpp
    ${ECSROOT}raylib/Sound.cpp
    ${ECSROOT}raylib/Sound.hpp
    ${ECSROOT}raylib/Rectangle.cpp
    ${ECSROOT}raylib/Rectangle.hpp
    ${ECSROOT}system/System.hpp
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
