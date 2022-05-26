set(INCROOT ${PROJECT_SOURCE_DIR}/include/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)
set(RAYLIBROOT ${SRCROOT}raylib/)
set(ECSROOT ${SRCROOT}ecs/)
set(MAPROOT ${SRCROOT}map/)
set(SCREENSROOT ${SRCROOT}screens/)
set(GAMEROOT ${SRCROOT}game/)

set(SRC
    ${SRCROOT}main.cpp
    ${ECSROOT}component/Component.hpp
    ${ECSROOT}entity/Entity.cpp
    ${ECSROOT}entity/Entity.hpp
    ${RAYLIBROOT}Raylib.cpp
    ${RAYLIBROOT}Raylib.hpp
    ${ECSROOT}system/System.hpp
    ${MAPROOT}/MapGenerator.cpp
    ${MAPROOT}/MapGenerator.hpp
    ${SCREENSROOT}IScreen.hpp
    ${SCREENSROOT}menu/MenuScreen.cpp
    ${SCREENSROOT}menu/MenuScreen.hpp
    ${SCREENSROOT}game/GameScreen.cpp
    ${SCREENSROOT}game/GameScreen.hpp
    ${GAMEROOT}Game.cpp
    ${GAMEROOT}Game.hpp
)

set(INCDIRS
    ${MAPROOT}
    ${GAMEROOT}
    ${SCREENSROOT}
)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(${PROJECT_NAME} PRIVATE ${INCDIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${INTERFACES_NAME})
# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
