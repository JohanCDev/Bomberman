/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "ecs/component/Component.hpp"
#include "ecs/entity/Entity.hpp"
#include "raylib/Raylib.hpp"
#include "RColor.hpp"
#include <iostream>

int main(void)
{
    // ecs::Entity entity;
    indie::raylib::Window window;
    indie::raylib::Draw draw;
    indie::raylib::Event event;

    window.initWindow(1920, 1000, "Indie Studio", true);
    while (!window.windowShouldClose()) {
        if (event.isKeyPressed(KEY_SPACE)) {
            std::cout << "a" << std::endl;
        }
        window.beginDrawing();
        window.clearBackground();
        draw.drawText("L'INDIE STUDIO EST FINIIIIIII", 100, 100, 50, BLACK);
        // draw.drawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2,  10.0, RED);
        window.endDrawing();
    }
    window.destroyWindow();
    // entity.addComponent<ecs::Position>(100.0, 100.0);
    // entity.addComponent<ecs::Movement>(30.0, 30.0);
    // entity.getPosition();
    // entity.getMovement();
    // entity.getCircleRadius();
    return (0);
}
