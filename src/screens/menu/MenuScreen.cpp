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
    background->addComponent<ecs::component::Transform>(
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    background->addComponent<ecs::component::Drawable2D>(
        "assets/menu/bg.png", static_cast<float>(1200.0), static_cast<float>(2000.0), WHITE);
    addEntity(std::move(background));

    std::unique_ptr<ecs::entity::Entity> frame = std::make_unique<ecs::entity::Entity>();
    frame->addComponent<ecs::component::Transform>(
        static_cast<float>(570.0), static_cast<float>(230.0), static_cast<float>(0.0), static_cast<float>(0.0));
    frame->addComponent<ecs::component::Drawable2D>(
        "assets/menu/frame.png", static_cast<float>(700.0), static_cast<float>(700.0), WHITE);
    addEntity(std::move(frame));

    std::unique_ptr<ecs::entity::Entity> left_character = std::make_unique<ecs::entity::Entity>();
    left_character->addComponent<ecs::component::Transform>(
        static_cast<float>(30.0), static_cast<float>(230.0), static_cast<float>(0.0), static_cast<float>(0.0));
    left_character->addComponent<ecs::component::Drawable2D>(
        "assets/menu/character_right.png", static_cast<float>(700.0), static_cast<float>(700.0), WHITE);
    addEntity(std::move(left_character));

    std::unique_ptr<ecs::entity::Entity> right_character = std::make_unique<ecs::entity::Entity>();
    right_character->addComponent<ecs::component::Transform>(
        static_cast<float>(1200.0), static_cast<float>(230.0), static_cast<float>(0.0), static_cast<float>(0.0));
    right_character->addComponent<ecs::component::Drawable2D>(
        "assets/menu/character_left.png", static_cast<float>(700.0), static_cast<float>(700.0), WHITE);
    addEntity(std::move(right_character));

    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(
        static_cast<float>(680.0), static_cast<float>(380.0), static_cast<float>(0.0), static_cast<float>(0.0));
    cursor->addComponent<ecs::component::Drawable2D>(
        "assets/menu/hand.png", static_cast<float>(80.0), static_cast<float>(80.0), WHITE);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> new_game = std::make_unique<ecs::entity::Entity>();
    new_game->addComponent<ecs::component::Transform>(
        static_cast<float>(780.0), static_cast<float>(350.0), static_cast<float>(0.0), static_cast<float>(0.0));
    new_game->addComponent<ecs::component::Drawable2D>(
        "assets/menu/new_game.png", static_cast<float>(105.0), static_cast<float>(280.0), WHITE);
    addEntity(std::move(new_game));

    std::unique_ptr<ecs::entity::Entity> load_game = std::make_unique<ecs::entity::Entity>();
    load_game->addComponent<ecs::component::Transform>(
        static_cast<float>(780.0), static_cast<float>(475.0), static_cast<float>(0.0), static_cast<float>(0.0));
    load_game->addComponent<ecs::component::Drawable2D>(
        "assets/menu/load.png", static_cast<float>(105.0), static_cast<float>(280.0), WHITE);
    addEntity(std::move(load_game));

    std::unique_ptr<ecs::entity::Entity> options = std::make_unique<ecs::entity::Entity>();
    options->addComponent<ecs::component::Transform>(
        static_cast<float>(780.0), static_cast<float>(600.0), static_cast<float>(0.0), static_cast<float>(0.0));
    options->addComponent<ecs::component::Drawable2D>(
        "assets/menu/options.png", static_cast<float>(105.0), static_cast<float>(280.0), WHITE);
    addEntity(std::move(options));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
    quit->addComponent<ecs::component::Transform>(
        static_cast<float>(780.0), static_cast<float>(725.0), static_cast<float>(0.0), static_cast<float>(0.0));
    quit->addComponent<ecs::component::Drawable2D>(
        "assets/menu/quit.png", static_cast<float>(105.0), static_cast<float>(280.0), WHITE);
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
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::DOWN) {
        ecs::component::Transform *transformCompo =
            _entities.at(4)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(static_cast<float>(680.0), static_cast<float>(checkCursorPosition(true)),
            static_cast<float>(0.0), static_cast<float>(0.0));
    }
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::UP) {
        ecs::component::Transform *transformCompo =
            _entities.at(4)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(static_cast<float>(680.0), static_cast<float>(checkCursorPosition(false)),
            static_cast<float>(0.0), static_cast<float>(0.0));
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == NEW_GAME)
        return 4;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == OPTIONS)
        return 3;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == EXIT)
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
        if (_cursorPosition == OPTIONS) {
            _cursorPosition = LOAD_GAME;
            return LOAD_GAME;
        }
        if (_cursorPosition == EXIT) {
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
