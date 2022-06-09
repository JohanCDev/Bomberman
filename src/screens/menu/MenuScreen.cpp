/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** MenuScreen.cpp
*/

#include "MenuScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::MenuScreen::MenuScreen() : _cursorPosition(NEW_GAME)
{
}

void indie::menu::MenuScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> background = std::make_unique<ecs::entity::Entity>();
    background->addComponent<ecs::component::Transform>(0.0f, 0.0f, 0.0f, 0.0f);
    background->addComponent<ecs::component::Drawable2D>("assets/menu/bg.png", 1200.0f, 2000.0f, WHITE);
    addEntity(std::move(background));

    std::unique_ptr<ecs::entity::Entity> frame = std::make_unique<ecs::entity::Entity>();
    frame->addComponent<ecs::component::Transform>(570.0f, 230.0f, 0.0f, 0.0f);
    frame->addComponent<ecs::component::Drawable2D>("assets/menu/frame.png", 600.0f, 700.0f, WHITE);
    addEntity(std::move(frame));

    std::unique_ptr<ecs::entity::Entity> left_character = std::make_unique<ecs::entity::Entity>();
    left_character->addComponent<ecs::component::Transform>(30.0f, 230.0f, 0.0f, 0.0f);
    left_character->addComponent<ecs::component::Drawable2D>("assets/menu/character_right.png", 700.0f, 700.0f, WHITE);
    addEntity(std::move(left_character));

    std::unique_ptr<ecs::entity::Entity> right_character = std::make_unique<ecs::entity::Entity>();
    right_character->addComponent<ecs::component::Transform>(1200.0f, 230.0f, 0.0f, 0.0f);
    right_character->addComponent<ecs::component::Drawable2D>("assets/menu/character_left.png", 700.0f, 700.0f, WHITE);
    addEntity(std::move(right_character));

    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(680.0f, 380.0f, 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("assets/menu/hand.png", 80.0f, 80.0f, WHITE);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> new_game = std::make_unique<ecs::entity::Entity>();
    new_game->addComponent<ecs::component::Transform>(780.0f, 350.0f, 0.0f, 0.0f);
    new_game->addComponent<ecs::component::Drawable2D>("assets/menu/new_game.png", 105.0f, 280.0f, WHITE);
    addEntity(std::move(new_game));

    std::unique_ptr<ecs::entity::Entity> load_game = std::make_unique<ecs::entity::Entity>();
    load_game->addComponent<ecs::component::Transform>(780.0f, 475.0f, 0.0f, 0.0f);
    load_game->addComponent<ecs::component::Drawable2D>("assets/menu/load.png", 105.0f, 280.0f, WHITE);
    addEntity(std::move(load_game));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
    quit->addComponent<ecs::component::Transform>(780.0f, 600.0f, 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>("assets/menu/quit.png", 105.0f, 280.0f, WHITE);
    addEntity(std::move(quit));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemMenu =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemMenu));
}

void indie::menu::MenuScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::MenuScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::DOWN || event.key.down) {
        ecs::component::Transform *transformCompo =
            _entities.at(4)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(680.0f, checkCursorPosition(true), 0.0f, 0.0f);
    }
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::UP || event.key.up) {
        ecs::component::Transform *transformCompo =
            _entities.at(4)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(680.0f, checkCursorPosition(false), 0.0f, 0.0f);
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == NEW_GAME)
        return 3;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == EXIT)
        return 10;
    if (_cursorPosition == NEW_GAME) {
        if (_entities[8] != NULL)
            _entities.erase(_entities.begin() + 8);
        std::unique_ptr<ecs::entity::Entity> new_game = std::make_unique<ecs::entity::Entity>();
        new_game->addComponent<ecs::component::Transform>(780.0f, 350.0f, 0.0f, 0.0f);
        new_game->addComponent<ecs::component::Drawable2D>("assets/menu/new_game.png", 115.0f, 290.0f, WHITE);
        addEntity(std::move(new_game));
    }
    if (_cursorPosition == LOAD_GAME) {
        if (_entities[8] != NULL)
            _entities.erase(_entities.begin() + 8);
        std::unique_ptr<ecs::entity::Entity> load_game = std::make_unique<ecs::entity::Entity>();
        load_game->addComponent<ecs::component::Transform>(780.0f, 475.0f, 0.0f, 0.0f);
        load_game->addComponent<ecs::component::Drawable2D>("assets/menu/load.png", 115.0f, 290.0f, WHITE);
        addEntity(std::move(load_game));
    }
    if (_cursorPosition == EXIT) {
        if (_entities[8] != NULL)
            _entities.erase(_entities.begin() + 8);
        std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
        quit->addComponent<ecs::component::Transform>(780.0f, 600.0f, 0.0f, 0.0f);
        quit->addComponent<ecs::component::Drawable2D>("assets/menu/quit.png", 115.0f, 290.0f, WHITE);
        addEntity(std::move(quit));
    }
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
            _cursorPosition = EXIT;
            return EXIT;
        }
        if (_cursorPosition == EXIT)
            return EXIT;
    } else if (!direction) {
        if (_cursorPosition == NEW_GAME)
            return NEW_GAME;
        if (_cursorPosition == LOAD_GAME) {
            _cursorPosition = NEW_GAME;
            return NEW_GAME;
        }
        if (_cursorPosition == EXIT) {
            _cursorPosition = LOAD_GAME;
            return LOAD_GAME;
        }
    }
    return 0;
}

void indie::menu::MenuScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}
