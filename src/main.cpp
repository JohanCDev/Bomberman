/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <iostream>
#include "map/MapGenerator.hpp"
#include "RColor.hpp"
#include "ecs/component/Component.hpp"
#include "ecs/entity/Entity.hpp"
#include "raylib/Raylib.hpp"

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
    indie::ecs::Entity entity;

    indie::Raylib::initWindow(1920, 1000, "Indie Studio", true);
    while (!indie::Raylib::windowShouldClose()) {
        if (indie::Raylib::isKeyPressed(KEY_SPACE)) {
            std::cout << "a" << std::endl;
        }
        indie::Raylib::beginDrawing();
        indie::Raylib::clearBackground();
        indie::Raylib::drawText("L'INDIE STUDIO EST FINIIIIIII", 100, 100, 50, BLACK);
        indie::Raylib::drawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 10.0, RED);
        indie::Raylib::endDrawing();
    }
    indie::Raylib::destroyWindow();
    entity.addComponent<indie::ecs::Position>(100.0, 100.0);
    entity.addComponent<indie::ecs::Movement>(30.0, 30.0);
    entity.getPosition();
    entity.getMovement();

    indie::map::MapGenerator map;
    map.createWall();
    printMap(map.getMap());
    return (0);
}
