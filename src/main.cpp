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

    entity->addComponent<ecs::Transform>(0.0, 0.0, 5.0, 5.0);
    entity->addComponent<ecs::Circle>(100.0, RED);
    entity->addComponent<ecs::Rectangle>(50, 150, BLUE);

    entity2->addComponent<ecs::Transform>(100.0, 100.0, 0.0, 25.0);
    entity2->addComponent<ecs::Rectangle>(100, 100, BLACK);

    world.addEntity(std::move(entity));
    world.addEntity(std::move(entity2));
    world.createSystem();

    raylib.initWindow(1920, 1000, "Indie Studio");
    while (!raylib.windowShouldClose()) {
        if (raylib.isKeyPressed(KEY_SPACE)) {
            for (auto &entity : world.entities) {
                entity->setAlive(!entity->getAlive());
            }
        }
        raylib.beginDrawing();
        raylib.clearBackground();
        raylib.drawText("L'INDIE STUDIO EST FINIIIIIII", 100, 100, 50, BLACK);
        raylib.drawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2,  10.0, RED);
        for (auto &entity : world.entities) {
            entity->draw();
        }
        for (auto &system : world.systems) {
            system->update(world.entities);
        }
        raylib.endDrawing();
    }
    raylib.destroyWindow();
    return (0);
}
