/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <iostream>
#include <unistd.h>
#include <vector>
#include "ecs/component/Component.hpp"
#include "ecs/entity/Entity.hpp"
#include "ecs/raylib/Raylib.hpp"

int main(void)
{
    ecs::Entity entity;
    Raylib raylib;

    raylib.initWindow(1920, 1000, "Indie Studio");
    while (!raylib.windowShouldClose()) {
        if (raylib.isKeyPressed(KEY_SPACE)) {
            std::cout << "a" << std::endl;
        }
        raylib.beginDrawing();
        raylib.clearBackground();
        raylib.drawText("L'INDIE STUDIO EST FINIIIIIII", 100, 100, 50, BLACK);
        raylib.drawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2,  10.0, RED);
        raylib.endDrawing();
    }
    raylib.destroyWindow();
    entity.addComponent<ecs::Transform>();
    if (entity.hasCompoType(ecs::compoType::TRANSFORM) == true) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    ecs::Transform *compo = entity.getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
    //entity.addComponent<ecs::Position>(100.0, 100.0);
    //entity.addComponent<ecs::Movement>(30.0, 30.0);
    //entity.getPosition();
    //entity.getMovement();
    // entity.getCircleRadius();
    return (0);
}
