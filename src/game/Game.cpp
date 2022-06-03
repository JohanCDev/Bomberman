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
#include "../ecs/system/Movement/Movement.hpp"
#include "../ecs/system/Sound/Sound.hpp"
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
    int ret = 0;

    int64_t newTime = 0;
    int64_t currentTime =
        std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch())
            .count();
    int64_t accumulator = 0;
    int64_t draw_aq = 0;
    const float initUpdateMs = static_cast<float>(_fps) * 1000;
    float updateMs = initUpdateMs;
    std::unique_ptr<indie::ecs::entity::Entity> entity = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::entity::Entity> entity2 = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::entity::Entity> entity3 = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::entity::Entity> entity4 = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::entity::Entity> entity5 = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystem = std::make_unique<indie::ecs::system::Draw2DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemMenu =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemOption =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> draw3DSystem = std::make_unique<indie::ecs::system::Draw3DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> movementSystem =
        std::make_unique<indie::ecs::system::MovementSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> soundSystem = std::make_unique<indie::ecs::system::Sound>();
    std::unique_ptr<indie::ecs::system::ISystem> collideSystem = std::make_unique<indie::ecs::system::Collide>();

    entity->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(100.0), static_cast<float>(100.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity->addComponent<indie::ecs::component::Drawable2D>(
        "INDIE STUDIOOOO MENU BONJOURRRRRR", static_cast<float>(50.0), BLACK);
    this->_menu->addEntity(std::move(entity));
    this->_menu->addSystem(std::move(draw2DSystemMenu));

    this->_options->addSystem(std::move(draw2DSystemOption));

    entity2->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(100.0), static_cast<float>(100.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity2->addComponent<indie::ecs::component::Drawable2D>(
        "INDIE STUDIOOOO GAME BONJOURRRRRR", static_cast<float>(50.0), BLACK);
    entity3->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(500.0), static_cast<float>(500.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity3->addComponent<indie::ecs::component::Drawable2D>(
        "src/boite.png", static_cast<float>(100.0), static_cast<float>(250.0), WHITE);
    entity4->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(1.0), static_cast<float>(1.0), static_cast<float>(-0.02), static_cast<float>(0.0));
    entity4->addComponent<indie::ecs::component::Drawable3D>(
        "src/boite.png", static_cast<float>(1.0), static_cast<float>(1.0), static_cast<float>(1.0), WHITE);
    entity4->addComponent<indie::ecs::component::Collide>();
    entity5->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(-2.0), static_cast<float>(1.0), static_cast<float>(0.02), static_cast<float>(0.0));
    entity5->addComponent<indie::ecs::component::Drawable3D>(
        "src/boite.png", static_cast<float>(1.0), static_cast<float>(1.0), static_cast<float>(1.0), BLUE);
    entity5->addComponent<indie::ecs::component::Collide>();
    // entity4->addComponent<indie::ecs::component::Sound>("src/maybe-next-time.wav", false);
    this->_game->addEntity(std::move(entity2));
    this->_game->addEntity(std::move(entity3));
    this->_game->addEntity(std::move(entity4));
    this->_game->addEntity(std::move(entity5));
    this->_game->addSystem(std::move(draw2DSystem));
    this->_game->addSystem(std::move(draw3DSystem));
    this->_game->addSystem(std::move(movementSystem));
    this->_game->addSystem(std::move(soundSystem));
    this->_game->addSystem(std::move(collideSystem));

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
    indie::raylib::Window::destroyWindow();
}

void indie::Game::setActualScreen(Screens newScreen)
{
    _actualScreen = newScreen;
}
