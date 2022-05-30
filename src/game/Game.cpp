/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Game
*/

#include "Game.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include "../gameEvents/GameEvents.hpp"
#include "../raylib/Raylib.hpp"
#include "../screens/IScreen.hpp"

indie::Game::Game(size_t baseFps)
{
    _fps = baseFps;
    _actualScreen = Screens::Menu;
    _menu = new indie::menu::MenuScreen;
    _game = new indie::menu::GameScreen;
    _options = new indie::menu::OptionsScreen;
}

indie::Game::~Game()
{
    delete _menu;
    delete _game;
    delete _options;
}

bool indie::Game::processEvents()
{
    GameEvents gameEvent;

    return gameEvent.inputUpdate(_event);
}

void indie::Game::update(float delta)
{
    (void)delta;
    return;
}

void indie::Game::draw()
{
    switch (_actualScreen) {
        case Screens::Menu: _menu->draw(); break;
        case Screens::Game: _game->draw(); break;
        case Screens::Options: _options->draw(); break;
        default: break;
    }
}

int indie::Game::handleEvent()
{
    switch (_actualScreen) {
        case Screens::Menu: return (_menu->handleEvent(_event));
        case Screens::Game: return (_game->handleEvent(_event));
        case Screens::Options: return (_options->handleEvent(_event));
        default: break;
    }
    return true;
}

void indie::Game::run()
{
    // int64_t newTime = 0;
    // int64_t currentTime =
    //     std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
    //         .count();
    // int64_t accumulator = 0;
    // int64_t draw_aq = 0;
    // const float initUpdateMs = static_cast<float>(_fps) * 1000;
    // float updateMs = initUpdateMs;

    int ret = 0;
    while (!Raylib::windowShouldClose()) {
        // newTime =
        //     std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
        //         .count();
        // accumulator += newTime - currentTime;
        // if (accumulator > 10 * initUpdateMs)
        //     updateMs = accumulator;
        // currentTime = newTime;
        if (!processEvents())
            break;

        // while (accumulator >= updateMs) {
        //     update(updateMs / 1000.f);
        //     accumulator -= updateMs;
        // }
        // updateMs = initUpdateMs;
        // draw_aq += accumulator;
        ret = handleEvent();
        if (ret == 10)
            break;
        if (ret == 1)
            setActualScreen(Screens::Menu);
        if (ret == 2)
            setActualScreen(Screens::Game);
        if (ret == 3)
            setActualScreen(Screens::Options);
        draw();
        // _actualScreen = Screens::Game;
        // draw_aq = 0;
    }
    indie::Raylib::destroyWindow();
}

void indie::Game::setActualScreen(Screens newScreen)
{
    _actualScreen = newScreen;
}
