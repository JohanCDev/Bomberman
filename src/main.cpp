/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <unistd.h>
#include "ecs/component/Component.hpp"
#include "ecs/entity/Entity.hpp"
#include "ecs/raylib/Raylib.hpp"
#include "ecs/system/System.hpp"
#include "World.hpp"

int main(void)
{
    ecs::World world;
    std::unique_ptr<ecs::Entity> entity = std::make_unique<ecs::Entity>();
    std::unique_ptr<ecs::Entity> entity2 = std::make_unique<ecs::Entity>();
    Raylib raylib;

    raylib.initWindow(1920, 1000, "Indie Studio");

    entity->addComponent<ecs::Transform>(static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0),
        static_cast<float>(0.05), static_cast<float>(0.0), static_cast<float>(0.0));
    entity->addComponent<ecs::Wall>("", static_cast<float>(2.0), static_cast<float>(2.0), RED);

    entity2->addComponent<ecs::Transform>(static_cast<float>(1.0), static_cast<float>(1.0), static_cast<float>(0.0),
        static_cast<float>(-0.05), static_cast<float>(0.0), static_cast<float>(0.0));
    entity2->addComponent<ecs::Player>("", static_cast<float>(2.0), BLACK);

    Camera3D camera = {{0, 10.0, 10.0}, {0, 0, 0}, {0, 1.0, 0}, 45.0, CAMERA_PERSPECTIVE};
    world.addEntity(std::move(entity));
    world.addEntity(std::move(entity2));
    world.createSystem();

    while (!raylib.windowShouldClose()) {
        if (raylib.isKeyPressed(KEY_SPACE)) {
            for (auto &entity : world.entities) {
                entity->setAlive(!entity->getAlive());
            }
        }
        raylib.beginDrawing();
        raylib.clearBackground();
        BeginMode3D(camera);
        for (auto &entity : world.entities) {
            entity->draw();
        }
        for (auto &system : world.systems) {
            system->update(world.entities);
        }
        EndMode3D();
        raylib.drawText("L'INDIE STUDIO EST FINIIIIIII", 100, 100, 50, BLACK);
        raylib.endDrawing();
    }
    raylib.destroyWindow();
    return (0);
}
