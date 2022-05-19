/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "ecs/component/Component.hpp"
#include "ecs/entity/Entity.hpp"
#include "ecs/raylib/Raylib.hpp"
#include "RColor.hpp"

#if defined(WIN32)
    #include <windows.h>
#else
    #include <unistd.h>
    #include <iostream>
#endif

int main(void)
{
    ecs::Entity entity;

    Raylib::initWindow(1920, 1000, "Indie Studio", true);
    while (!Raylib::windowShouldClose()) {
        if (Raylib::isKeyPressed(KEY_SPACE)) {
            std::cout << "a" << std::endl;
        }
        Raylib::beginDrawing();
        Raylib::clearBackground();
        Raylib::drawText("L'INDIE STUDIO EST FINIIIIIII", 100, 100, 50, RBLACK);
        Raylib::drawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2,  10.0, RRED);
        Raylib::endDrawing();
    }
    Raylib::destroyWindow();
    entity.addComponent<ecs::Position>(100.0, 100.0);
    entity.addComponent<ecs::Movement>(30.0, 30.0);
    entity.getPosition();
    entity.getMovement();
    // entity.getCircleRadius();
    return (0);
}
