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

int main(void)
{
    indie::Game Game(60);

    indie::Raylib::initWindow(1420, 800, "Indie Studio", true);
    Game.run();
    // Raylib::destroyWindow();
    return (0);
}
