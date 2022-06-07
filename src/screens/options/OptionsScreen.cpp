/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** OptionsScreen.cpp
*/

#include "OptionsScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::OptionsScreen::OptionsScreen() : _cursorPosition(SET_FPS)
{
    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(
        static_cast<float>(320.0), static_cast<float>(410.0), static_cast<float>(0.0), static_cast<float>(0.0));
    cursor->addComponent<ecs::component::Drawable2D>("", static_cast<float>(40.0), static_cast<float>(40.0), RED);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> set_fps = std::make_unique<ecs::entity::Entity>();
    set_fps->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(400.0), static_cast<float>(0.0), static_cast<float>(0.0));
    set_fps->addComponent<ecs::component::Drawable2D>("Set Fps", static_cast<float>(50.0), BLACK);
    set_fps->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    addEntity(std::move(set_fps));

    std::unique_ptr<ecs::entity::Entity> new_game = std::make_unique<ecs::entity::Entity>();
    new_game->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(500.0), static_cast<float>(0.0), static_cast<float>(0.0));
    new_game->addComponent<ecs::component::Drawable2D>("Resume", static_cast<float>(50.0), BLACK);
    new_game->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    addEntity(std::move(new_game));

    std::unique_ptr<ecs::entity::Entity> load_game = std::make_unique<ecs::entity::Entity>();
    load_game->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(600.0), static_cast<float>(0.0), static_cast<float>(0.0));
    load_game->addComponent<ecs::component::Drawable2D>("Menu", static_cast<float>(50.0), BLACK);
    load_game->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    addEntity(std::move(load_game));

    std::unique_ptr<ecs::entity::Entity> options = std::make_unique<ecs::entity::Entity>();
    options->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(700.0), static_cast<float>(0.0), static_cast<float>(0.0));
    options->addComponent<ecs::component::Drawable2D>("EXIT", static_cast<float>(50.0), BLACK);
    options->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    addEntity(std::move(options));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemOption =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemOption));
}

void indie::menu::OptionsScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::OptionsScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::DOWN) {
        indie::ecs::component::Transform *transformCompo =
            _entities.at(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(static_cast<float>(320.0), static_cast<float>(checkCursorPosition(true)),
            static_cast<float>(0.0), static_cast<float>(0.0));
    }
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::UP) {
        ecs::component::Transform *transformCompo =
            _entities.at(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(static_cast<float>(320.0), static_cast<float>(checkCursorPosition(false)),
            static_cast<float>(0.0), static_cast<float>(0.0));
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == SET_FPS)
        return 99;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == RESUME)
        return 2;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == MENU)
        return 1;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == EXIT)
        return 10;
    return 0;
}

void indie::menu::OptionsScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::OptionsScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::OptionsScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

int indie::menu::OptionsScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == SET_FPS) {
            _cursorPosition = RESUME;
            return RESUME;
        }
        if (_cursorPosition == RESUME) {
            _cursorPosition = MENU;
            return MENU;
        }
        if (_cursorPosition == MENU) {
            _cursorPosition = EXIT;
            return EXIT;
        }
        if (_cursorPosition == EXIT)
            return EXIT;
    } else if (!direction) {
        if (_cursorPosition == SET_FPS)
            return SET_FPS;
        if (_cursorPosition == RESUME) {
            _cursorPosition = SET_FPS;
            return SET_FPS;
        }
        if (_cursorPosition == MENU) {
            _cursorPosition = RESUME;
            return RESUME;
        }
        if (_cursorPosition == EXIT) {
            _cursorPosition = MENU;
            return MENU;
        }
    }
    return 0;
}
