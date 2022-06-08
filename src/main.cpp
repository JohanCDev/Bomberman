/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <iostream>
#include "Colors.hpp"
#include "ecs/component/IComponent.hpp"
#include "ecs/entity/Entity.hpp"
#include "game/Game.hpp"
#include "map/MapGenerator.hpp"
#include "player/Player.hpp"
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
    try {
        indie::Game Game(60);
        indie::raylib::Window::getInstance(1420, 800, "Indie Studio", false, 60);
        Game.run();
    } catch (std::exception) {
        std::cerr << "An error occured" << std::endl;
    }
    return (0);
}
