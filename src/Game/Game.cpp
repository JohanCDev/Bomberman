/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Game
*/

#include "Game.hpp"
#include "../ecs/raylib/Raylib.hpp"
#include <algorithm>
#include <chrono>
#include <memory>
#include "../Screens/IScreen.hpp"
#include "../Screens/MenuScreen/MenuScreen.hpp"

indie::Game::Game(size_t baseFps)
{
    _fps = baseFps;
    _actualScreen = Screens::Menu;

    _screens[Screens::Menu] = std::make_unique<IScreen>(indie::menu::MenuScreen());
}

indie::Game::~Game()
{
}

bool indie::Game::processEvents() {
    return false;
}

void indie::Game::update(float delta)
{
    (void)delta;
    return;
}

void indie::Game::draw()
{
    if (_screens.find(_actualScreen) != _screens.end())
        _screens.find(_actualScreen)->second->draw();
}

void indie::Game::run()
{
    int64_t newTime = 0;
    int64_t currentTime =
        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
            .count();
    int64_t accumulator = 0;
    int64_t draw_aq = 0;
    const float initUpdateMs = _fps * 1000;
    float updateMs = initUpdateMs;

    while (Raylib::windowShouldClose() == false) {
        newTime =
            std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
                .count();
        accumulator += newTime - currentTime;
        if (accumulator > 10 * initUpdateMs)
            updateMs = accumulator;
        currentTime = newTime;
        if (!processEvents())
            break;
        while (accumulator >= updateMs) {
            update(updateMs / 1000.f);
            accumulator -= updateMs;
        }
        updateMs = initUpdateMs;
        draw_aq += accumulator;
        draw();
        draw_aq = 0;
    }
    Raylib::destroyWindow();
}