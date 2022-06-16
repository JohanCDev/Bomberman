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

int main(void)
{
    try {
        indie::Game Game(60);
        indie::raylib::Window::getInstance(1495, 982, "Indie Studio", true, 60);

        Game.init();
        Game.run();
        Game.destroy();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}
