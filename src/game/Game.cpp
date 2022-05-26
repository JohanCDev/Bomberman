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
#include "../raylib/Raylib.hpp"
#include "../screens/IScreen.hpp"

indie::Game::Game(size_t baseFps)
{
    _fps = baseFps;
    _actualScreen = Screens::Menu;
    _menu = new indie::menu::MenuScreen;
    _game = new indie::menu::GameScreen;
}

indie::Game::~Game()
{
    delete _menu;
    delete _game;
}

bool indie::Game::processEvents()
{
    return true;
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
        default: break;
    }
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
    std::unique_ptr<ecs::Entity> entity = std::make_unique<ecs::Entity>();
    std::unique_ptr<ecs::Entity> entity2 = std::make_unique<ecs::Entity>();
    std::unique_ptr<ecs::Entity> entity3 = std::make_unique<ecs::Entity>();

    entity->addComponent<ecs::Transform>(static_cast<float>(100.0), static_cast<float>(100.0), static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity->addComponent<ecs::Text>("INDIE STUDIOOOO MENU BONJOURRRRRR", static_cast<float>(50.0), BLACK);
    this->_menu->addEntity(std::move(entity));

    entity2->addComponent<ecs::Transform>(static_cast<float>(100.0), static_cast<float>(100.0), static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity2->addComponent<ecs::Text>("INDIE STUDIOOOO GAME BONJOURRRRRR", static_cast<float>(50.0), BLACK);
    entity3->addComponent<ecs::Transform>(static_cast<float>(500.0), static_cast<float>(500.0), static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity3->addComponent<ecs::Rectangle>("", static_cast<float>(100.0), static_cast<float>(250.0), GREEN);
    this->_game->addEntity(std::move(entity2));
    this->_game->addEntity(std::move(entity3));

    while (!Raylib::windowShouldClose()) {
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
        _actualScreen = Screens::Game;
        draw_aq = 0;
    }
    indie::Raylib::destroyWindow();
}

void indie::Game::setActualScreen(Screens newScreen)
{
    _actualScreen = newScreen;
}
