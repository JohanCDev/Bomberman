/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <iostream>
#include "Map/MapGenerator.hpp"
#include "RColor.hpp"
#include "ecs/component/Component.hpp"
#include "ecs/entity/Entity.hpp"
#include "ecs/raylib/Raylib.hpp"

void printMap(std::vector<std::vector<char>> const &map)
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
}

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
        Raylib::drawText("L'INDIE STUDIO EST FINIIIIIII", 100, 100, 50, BLACK);
        Raylib::drawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 10.0, RED);
        Raylib::endDrawing();
    }
    Raylib::destroyWindow();
    entity.addComponent<ecs::Position>(100.0, 100.0);
    entity.addComponent<ecs::Movement>(30.0, 30.0);
    entity.getPosition();
    entity.getMovement();

    MapGenerator map;
    map.createWall();
    printMap(map.getMap());
    return (0);
}
