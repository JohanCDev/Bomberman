/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "ecs/entity/Entity.hpp"
#include "ecs/component/Component.hpp"
#include <iostream>
#include "ecs/raylib/Raylib.hpp"
#include <unistd.h>

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
    entity.addComponent<ecs::Position>(100.0, 100.0);
    entity.addComponent<ecs::Movement>(30.0, 30.0);
    entity.getPosition();
    entity.getMovement();
    return (0);
}