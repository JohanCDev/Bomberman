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
#include "../map/MapGenerator.hpp"
#include "../raylib/Raylib.hpp"
#include "../screens/IScreen.hpp"

indie::Game::Game(size_t baseFps)
{
    _fps = baseFps;
    _actualScreen = Screens::Menu;
    _menu = new indie::menu::MenuScreen;
    _game = new indie::menu::GameScreen;
    _options = new indie::menu::OptionsScreen;
    _premenu = new indie::menu::PreMenuScreen;
    _gameoptions = new indie::menu::GameOptionsScreen;
    _end = new indie::menu::EndScreen;
    _setFps = new indie::menu::SetFpsScreen;
    _setSound = new indie::menu::SetSoundScreen;
    _setMusic = new indie::menu::SetMusicScreen;
}

indie::Game::~Game()
{
    delete _menu;
    delete _game;
    delete _options;
    delete _premenu;
    delete _gameoptions;
    delete _end;
    delete _setFps;
    delete _setSound;
    delete _setMusic;
}

void indie::Game::init_scenes()
{
    _menu->init();
    _game->init();
    _options->init();
    _premenu->init();
    _gameoptions->init();
    _end->init();
    _setFps->init();
    _setSound->init();
    _setMusic->init();
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
        case Screens::PreMenu: _premenu->draw(); break;
        case Screens::GameOptions: _gameoptions->draw(); break;
        case Screens::End: _end->draw(); break;
        case Screens::SetFps: _setFps->draw(); break;
        case Screens::SetSound: _setSound->draw(); break;
        case Screens::SetMusic: _setMusic->draw(); break;
        default: break;
    }
}

int indie::Game::handleEvent()
{
    switch (_actualScreen) {
        case Screens::Menu: return (_menu->handleEvent(_event));
        case Screens::Game: return (_game->handleEvent(_event));
        case Screens::Options: return (_options->handleEvent(_event));
        case Screens::PreMenu: return (_premenu->handleEvent(_event));
        case Screens::GameOptions: return (_gameoptions->handleEvent(_event));
        case Screens::End: return (_end->handleEvent(_event));
        case Screens::SetFps: return (_setFps->handleEvent(_event));
        case Screens::SetSound: return (_setSound->handleEvent(_event));
        case Screens::SetMusic: return (_setMusic->handleEvent(_event));
        default: break;
    }
    return true;
}

void indie::Game::run()
{
    int ret = 0;
    indie::map::MapGenerator map;

    init_scenes();
    map.createWall();
    this->_game->initMap(map.getMap());

    int64_t newTime = 0;
    int64_t currentTime =
        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
            .count();
    int64_t accumulator = 0;
    int64_t draw_aq = 0;
    const float initUpdateMs = static_cast<float>(_fps) * 1000;
    float updateMs = initUpdateMs;

    while (!indie::raylib::Window::windowShouldClose()) {
        newTime =
            std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
                .count();
        accumulator += newTime - currentTime;
        if (accumulator > 10 * initUpdateMs)
            updateMs = accumulator;
        currentTime = newTime;
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
        handleScreensSwap(ret);
        draw();
        // _actualScreen = Screens::Game;
        // draw_aq = 0;
    }
    indie::raylib::Window::destroyWindow();
}

void indie::Game::handleScreensSwap(int ret)
{
    if (ret == 1) {
        reinitGame();
        setActualScreen(Screens::Menu);
    }
    if (ret == 2)
        setActualScreen(Screens::Game);
    if (ret == 3)
        setActualScreen(Screens::Options);
    if (ret == 4)
        setActualScreen(Screens::PreMenu);
    if (ret == 5)
        setActualScreen(Screens::GameOptions);
    if (ret == 6)
        setActualScreen(Screens::End);
    if (ret == 7)
        setActualScreen(Screens::SetFps);
    if (ret == 8)
        setActualScreen(Screens::SetSound);
    if (ret == 9)
        setActualScreen(Screens::SetMusic);
}

void indie::Game::reinitGame()
{
    delete _game;
    _game = new indie::menu::GameScreen;
    _game->init();
    indie::map::MapGenerator map;
    map.createWall();
    this->_game->initMap(map.getMap());
    delete _premenu;
    _premenu = new indie::menu::PreMenuScreen;
    _premenu->init();
}

void indie::Game::setActualScreen(Screens newScreen)
{
    _actualScreen = newScreen;
}
