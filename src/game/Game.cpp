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
#include "../ecs/system/Collide/Collide.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"
#include "../ecs/system/Draw3D/Draw3D.hpp"
#include "../ecs/system/Explodable/Explodable.hpp"
#include "../ecs/system/Movement/Movement.hpp"
#include "../ecs/system/Sound/Sound.hpp"
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
}

indie::Game::~Game()
{
    delete _menu;
    delete _game;
}

bool indie::Game::processEvents()
{
    GameEvents gameEvent;

    bool ret = gameEvent.inputUpdate(_event);
    this->_game->handleEvent(_event);
    return (ret);
}

void indie::Game::update()
{
    switch (_actualScreen) {
        case Screens::Menu: _menu->update(); break;
        case Screens::Game: _game->update(); break;
        default: break;
    }
}

void indie::Game::draw()
{
    switch (_actualScreen) {
        case Screens::Menu: _menu->draw(); break;
        case Screens::Game: _game->draw(); break;
        default: break;
    }
}

void indie::Game::init()
{
    indie::map::MapGenerator map;
    std::unique_ptr<indie::ecs::entity::Entity> entity = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystem = std::make_unique<indie::ecs::system::Draw2DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> draw3DSystem = std::make_unique<indie::ecs::system::Draw3DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> movementSystem =
        std::make_unique<indie::ecs::system::MovementSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> soundSystem = std::make_unique<indie::ecs::system::Sound>();
    std::unique_ptr<indie::ecs::system::ISystem> collideSystem = std::make_unique<indie::ecs::system::Collide>();
    std::unique_ptr<indie::ecs::entity::Entity> entityX = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::system::Explodable> explodeSystem = std::make_unique<indie::ecs::system::Explodable>();

    map.createWall();
    entityX->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entityX->addComponent<indie::ecs::component::Drawable3D>(
        "", static_cast<float>(10.5), static_cast<float>(0.05), static_cast<float>(10), LIGHTGRAY);
    entityX->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM)->setZ(-0.25);
    this->_game->initEntity();
    this->_game->addEntity(std::move(entityX));
    this->_game->initMap(map.getMap());
    this->_game->addSystem(std::move(draw2DSystem));
    this->_game->addSystem(std::move(draw3DSystem));
    this->_game->addSystem(std::move(movementSystem));
    this->_game->addSystem(std::move(soundSystem));
    this->_game->addSystem(std::move(collideSystem));
    this->_game->addSystem(std::move(explodeSystem));
    _actualScreen = Screens::Game;
}

void indie::Game::run()
{
    while (!indie::raylib::Window::windowShouldClose()) {
        if (!processEvents())
            break;
        update();
        draw();
    }
    indie::raylib::Window::destroyWindow();
}

void indie::Game::setActualScreen(Screens newScreen)
{
    _actualScreen = newScreen;
}
