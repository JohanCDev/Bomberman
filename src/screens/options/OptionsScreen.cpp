/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** OptionsScreen.cpp
*/

#include "OptionsScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::OptionsScreen::OptionsScreen() : _cursorPosition(SET_MUSIC)
{
}

void indie::menu::OptionsScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(320.0f, 210.0f, 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("", 40.0f, 40.0f, RED);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> set_music = std::make_unique<ecs::entity::Entity>();
    set_music->addComponent<ecs::component::Transform>(400.0f, 200.0f, 0.0f, 0.0f);
    set_music->addComponent<ecs::component::Drawable2D>("Set music", 50.0f, BLACK);
    set_music->addComponent<ecs::component::Drawable2D>("", 70.0f, 270.0f, BLUE);
    addEntity(std::move(set_music));

    std::unique_ptr<ecs::entity::Entity> set_sound = std::make_unique<ecs::entity::Entity>();
    set_sound->addComponent<ecs::component::Transform>(400.0f, 300.0f, 0.0f, 0.0f);
    set_sound->addComponent<ecs::component::Drawable2D>("Set sound", 50.0f, BLACK);
    set_sound->addComponent<ecs::component::Drawable2D>("", 70.0f, 270.0f, BLUE);
    addEntity(std::move(set_sound));

    std::unique_ptr<ecs::entity::Entity> set_fps = std::make_unique<ecs::entity::Entity>();
    set_fps->addComponent<ecs::component::Transform>(400.0f, 400.0f, 0.0f, 0.0f);
    set_fps->addComponent<ecs::component::Drawable2D>("Set FPS", 50.0f, BLACK);
    set_fps->addComponent<ecs::component::Drawable2D>("", 70.0f, 270.0f, BLUE);
    addEntity(std::move(set_fps));

    std::unique_ptr<ecs::entity::Entity> load_game = std::make_unique<ecs::entity::Entity>();
    load_game->addComponent<ecs::component::Transform>(400.0f, 500.0f, 0.0f, 0.0f);
    load_game->addComponent<ecs::component::Drawable2D>("Menu", 50.0f, BLACK);
    load_game->addComponent<ecs::component::Drawable2D>("", 70.0f, 270.0f, BLUE);
    addEntity(std::move(load_game));

    std::unique_ptr<ecs::entity::Entity> options = std::make_unique<ecs::entity::Entity>();
    options->addComponent<ecs::component::Transform>(400.0f, 600.0f, 0.0f, 0.0f);
    options->addComponent<ecs::component::Drawable2D>("Quit", 50.0f, BLACK);
    options->addComponent<ecs::component::Drawable2D>("", 70.0f, 270.0f, BLUE);
    addEntity(std::move(options));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemOption =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemOption));
}

void indie::menu::OptionsScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::OptionsScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::DOWN || event.key.down) {
        indie::ecs::component::Transform *transformCompo =
            _entities.at(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(320.0f, checkCursorPosition(true), 0.0f, 0.0f);
    }
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::UP || event.key.up) {
        ecs::component::Transform *transformCompo =
            _entities.at(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(320.0f, checkCursorPosition(false), 0.0f, 0.0f);
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter) && _cursorPosition == SET_FPS)
        return 9;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter) && _cursorPosition == SET_SOUND)
        return 8;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter) && _cursorPosition == SET_MUSIC)
        return 7;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter) && _cursorPosition == MENU)
        return 1;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter) && _cursorPosition == EXIT)
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
        if (_cursorPosition == SET_MUSIC) {
            _cursorPosition = SET_SOUND;
            return SET_SOUND;
        }
        if (_cursorPosition == SET_SOUND) {
            _cursorPosition = SET_FPS;
            return SET_FPS;
        }
        if (_cursorPosition == SET_FPS) {
            _cursorPosition = MENU;
            return MENU;
        }
        if (_cursorPosition == MENU) {
            _cursorPosition = EXIT;
            return EXIT;
        }
        if (_cursorPosition == EXIT) {
            return EXIT;
        }
    } else if (!direction) {
        if (_cursorPosition == SET_MUSIC) {
            return SET_MUSIC;
        }
        if (_cursorPosition == SET_SOUND) {
            _cursorPosition = SET_MUSIC;
            return SET_MUSIC;
        }
        if (_cursorPosition == SET_FPS) {
            _cursorPosition = SET_SOUND;
            return SET_SOUND;
        }
        if (_cursorPosition == MENU) {
            _cursorPosition = SET_FPS;
            return SET_FPS;
        }
        if (_cursorPosition == EXIT) {
            _cursorPosition = MENU;
            return MENU;
        }
    }
    return 0;
}
