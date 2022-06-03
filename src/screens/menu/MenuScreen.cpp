/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** MenuScreen
*/

#include "MenuScreen.hpp"
#include <raylib.h>
#include "../../raylib/Raylib.hpp"

indie::menu::MenuScreen::MenuScreen() : _cursorPosition(NEW_GAME)
{
    std::unique_ptr<ecs::entity::Entity> new_game = std::make_unique<ecs::entity::Entity>();
    new_game->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(500.0), static_cast<float>(0.0), static_cast<float>(0.0));
    new_game->addComponent<ecs::component::Drawable2D>(static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    new_game->addComponent<ecs::component::Drawable2D>("New Game", static_cast<float>(50.0), BLACK);
    addEntity(std::move(new_game));

    std::unique_ptr<ecs::entity::Entity> load_game = std::make_unique<ecs::entity::Entity>();
    load_game->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(600.0), static_cast<float>(0.0), static_cast<float>(0.0));
    load_game->addComponent<ecs::component::Drawable2D>(static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    load_game->addComponent<ecs::component::Drawable2D>("Load Game", static_cast<float>(50.0), BLACK);
    addEntity(std::move(load_game));

    std::unique_ptr<ecs::entity::Entity> options = std::make_unique<ecs::entity::Entity>();
    options->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(700.0), static_cast<float>(0.0), static_cast<float>(0.0));
    options->addComponent<ecs::component::Drawable2D>(static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    options->addComponent<ecs::component::Drawable2D>("Options", static_cast<float>(50.0), BLACK);
    addEntity(std::move(options));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
    quit->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(800.0), static_cast<float>(0.0), static_cast<float>(0.0));
    quit->addComponent<ecs::component::Drawable2D>(static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    quit->addComponent<ecs::component::Drawable2D>("Quit", static_cast<float>(50.0), BLACK);
    addEntity(std::move(quit));

    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(
        static_cast<float>(320.0), static_cast<float>(510.0), static_cast<float>(0.0), static_cast<float>(0.0));
    cursor->addComponent<ecs::component::Drawable2D>(static_cast<float>(40.0), static_cast<float>(40.0), RED);
    addEntity(std::move(cursor));
}

void indie::menu::MenuScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::MenuScreen::handleEvent(indie::Event &event)
{
    if (event.key.down) {
        ecs::component::Transform *transformCompo =
            _entities.at(4)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(static_cast<float>(320.0), static_cast<float>(checkCursorPosition(true)),
            static_cast<float>(0.0), static_cast<float>(0.0));
    }
    if (event.key.up) {
        ecs::component::Transform *transformCompo =
            _entities.at(4)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(static_cast<float>(320.0), static_cast<float>(checkCursorPosition(false)),
            static_cast<float>(0.0), static_cast<float>(0.0));
    }
    if (event.key.enter && _cursorPosition == NEW_GAME)
        return 2;
    if (event.key.enter && _cursorPosition == OPTIONS)
        return 3;
    if (event.key.enter && _cursorPosition == QUIT)
        return 10;
    return 0;
}

void indie::menu::MenuScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::MenuScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

int indie::menu::MenuScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == NEW_GAME) {
            _cursorPosition = LOAD_GAME;
            return LOAD_GAME;
        }
        if (_cursorPosition == LOAD_GAME) {
            _cursorPosition = OPTIONS;
            return OPTIONS;
        }
        if (_cursorPosition == OPTIONS) {
            _cursorPosition = QUIT;
            return QUIT;
        }
        if (_cursorPosition == QUIT)
            return QUIT;
    } else if (!direction) {
        if (_cursorPosition == NEW_GAME)
            return NEW_GAME;
        if (_cursorPosition == LOAD_GAME) {
            _cursorPosition = NEW_GAME;
            return NEW_GAME;
        }
        if (_cursorPosition == OPTIONS) {
            _cursorPosition = LOAD_GAME;
            return LOAD_GAME;
        }
        if (_cursorPosition == QUIT) {
            _cursorPosition = OPTIONS;
            return OPTIONS;
        }
    }
    return 0;
}

void indie::menu::MenuScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}
