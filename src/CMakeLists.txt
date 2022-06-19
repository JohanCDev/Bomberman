set(INCROOT ${PROJECT_SOURCE_DIR}/include/)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/)
set(RAYLIBROOT ${SRCROOT}raylib/)
set(ECSROOT ${SRCROOT}ecs/)
set(RAYLIBROOT ${SRCROOT}raylib/)
set(MAPROOT ${SRCROOT}map/)
set(SCREENSROOT ${SRCROOT}screens/)
set(GAMEROOT ${SRCROOT}game/)
set(EVENTSROOT ${SRCROOT}gameEvents/)
set(PLAYERROOT ${SRCROOT}player/)
set(TOOLSROOT ${SRCROOT}tools/)

set(SRC_ECS
    ${ECSROOT}component/IComponent.hpp
    ${ECSROOT}component/Transform/Transform.cpp
    ${ECSROOT}component/Transform/Transform.hpp
    ${ECSROOT}component/Drawable2D/Drawable2D.cpp
    ${ECSROOT}component/Drawable2D/Drawable2D.hpp
    ${ECSROOT}component/Drawable3D/Drawable3D.cpp
    ${ECSROOT}component/Drawable3D/Drawable3D.hpp
    ${ECSROOT}component/Alive/Alive.cpp
    ${ECSROOT}component/Alive/Alive.hpp
    ${ECSROOT}component/Collectable/Collectable.cpp
    ${ECSROOT}component/Collectable/Collectable.hpp
    ${ECSROOT}component/Inventory/Inventory.cpp
    ${ECSROOT}component/Inventory/Inventory.hpp
    ${ECSROOT}component/Explodable/Explodable.cpp
    ${ECSROOT}component/Explodable/Explodable.hpp
    ${ECSROOT}component/Collide/Collide.cpp
    ${ECSROOT}component/Collide/Collide.hpp
    ${ECSROOT}component/Object/Object.cpp
    ${ECSROOT}component/Object/Object.hpp
    ${ECSROOT}component/Sound/Sound.cpp
    ${ECSROOT}component/Sound/Sound.hpp
    ${ECSROOT}component/Destroyable/Destroyable.cpp
    ${ECSROOT}component/Destroyable/Destroyable.hpp
    ${ECSROOT}entity/Entity.cpp
    ${ECSROOT}entity/Entity.hpp
    ${ECSROOT}system/Draw2D/Draw2D.cpp
    ${ECSROOT}system/Draw2D/Draw2D.hpp
    ${ECSROOT}system/Draw3D/Draw3D.cpp
    ${ECSROOT}system/Draw3D/Draw3D.hpp
    ${ECSROOT}system/Movement/Movement.cpp
    ${ECSROOT}system/Movement/Movement.hpp
    ${ECSROOT}system/Collide/Collide.cpp
    ${ECSROOT}system/Collide/Collide.hpp
    ${ECSROOT}system/Sound/Sound.cpp
    ${ECSROOT}system/Sound/Sound.hpp
    ${ECSROOT}system/Explodable/Explodable.cpp
    ${ECSROOT}system/Explodable/Explodable.hpp
    ${ECSROOT}system/Object/Object.cpp
    ${ECSROOT}system/Object/Object.hpp
    ${ECSROOT}system/ISystem.hpp
)

set(SRC_RAY
    ${RAYLIBROOT}/boundingbox/BoundingBox.cpp
    ${RAYLIBROOT}/boundingbox/BoundingBox.hpp
    ${RAYLIBROOT}/camera3d/Camera3D.cpp
    ${RAYLIBROOT}/camera3d/Camera3D.hpp
    ${RAYLIBROOT}/circle/Circle.cpp
    ${RAYLIBROOT}/circle/Circle.hpp
    ${RAYLIBROOT}/cube/Cube.cpp
    ${RAYLIBROOT}/cube/Cube.hpp
    ${RAYLIBROOT}/cylinder/Cylinder.cpp
    ${RAYLIBROOT}/cylinder/Cylinder.hpp
    ${RAYLIBROOT}/draw/Draw.cpp
    ${RAYLIBROOT}/draw/Draw.hpp
    ${RAYLIBROOT}/event/Event.cpp
    ${RAYLIBROOT}/event/Event.hpp
    ${RAYLIBROOT}/model/Model.cpp
    ${RAYLIBROOT}/model/Model.hpp
    ${RAYLIBROOT}/rectangle/Rectangle.cpp
    ${RAYLIBROOT}/rectangle/Rectangle.hpp
    ${RAYLIBROOT}/sound/Sound.cpp
    ${RAYLIBROOT}/sound/Sound.hpp
    ${RAYLIBROOT}/sphere/Sphere.cpp
    ${RAYLIBROOT}/sphere/Sphere.hpp
    ${RAYLIBROOT}/triangle/Triangle.cpp
    ${RAYLIBROOT}/triangle/Triangle.hpp
    ${RAYLIBROOT}/texture2d/Texture2D.cpp
    ${RAYLIBROOT}/texture2d/Texture2D.hpp
    ${RAYLIBROOT}/window/Window.cpp
    ${RAYLIBROOT}/window/Window.hpp
    ${RAYLIBROOT}Raylib.hpp
)

set(SRC_SCREEN
    ${SCREENSROOT}IScreen.hpp
    ${SCREENSROOT}menu/MenuScreen.cpp
    ${SCREENSROOT}menu/MenuScreen.hpp
    ${SCREENSROOT}game/GameScreen.cpp
    ${SCREENSROOT}game/GameScreen.hpp
    ${SCREENSROOT}pre_menu/PreMenuScreen.cpp
    ${SCREENSROOT}pre_menu/PreMenuScreen.hpp
    ${SCREENSROOT}game_options/GameOptionsScreen.hpp
    ${SCREENSROOT}game_options/GameOptionsScreen.cpp
    ${SCREENSROOT}set_fps/SetFpsScreen.cpp
    ${SCREENSROOT}set_fps/SetFpsScreen.hpp
    ${SCREENSROOT}set_music/SetMusicScreen.cpp
    ${SCREENSROOT}set_music/SetMusicScreen.hpp
    ${SCREENSROOT}set_sound/SetSoundScreen.cpp
    ${SCREENSROOT}set_sound/SetSoundScreen.hpp
    ${SCREENSROOT}game/uiPlayerDisplay/UIPlayerDisplay.cpp
    ${SCREENSROOT}game/uiPlayerDisplay/UIPlayerDisplay.hpp
)

set(SRC_MAP
    ${MAPROOT}/MapGenerator.cpp
    ${MAPROOT}/MapGenerator.hpp
)

set(SRC_EVENTS
    ${EVENTSROOT}/GameEvents.cpp
    ${EVENTSROOT}/GameEvents.hpp
)

set(SRC_GAME
    ${GAMEROOT}Game.cpp
    ${GAMEROOT}Game.hpp
)

set(SRC_PLAYER
    ${PLAYERROOT}Player.cpp
    ${PLAYERROOT}Player.hpp
)

set(SRC_TOOLS
    ${TOOLSROOT}Tools.cpp
    ${TOOLSROOT}Tools.hpp
)


set(SRC
    ${SRCROOT}main.cpp
    ${SRC_TOOLS}
    ${SRC_ECS}
    ${SRC_RAY}
    ${SRC_SCREEN}
    ${SRC_MAP}
    ${SRC_EVENTS}
    ${SRC_GAME}
    ${SRC_PLAYER}
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
if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework OpenGL")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
