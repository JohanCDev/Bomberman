/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <iostream>
#include "RColor.hpp"
#include "ecs/component/Component.hpp"
#include "ecs/entity/Entity.hpp"
#include "game/Game.hpp"
#include "map/MapGenerator.hpp"
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
    indie::Game Game(60);

    indie::Raylib::initWindow(1420, 800, "Indie Studio", false);
    ToggleFullscreen();

    Game.run();
    return (0);
}
