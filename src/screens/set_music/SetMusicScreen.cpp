/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** SetMusicScreen.cpp
*/

#include "SetMusicScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::SetMusicScreen::SetMusicScreen() : _cursorPosition(MUSIC_0)
{
    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(320.0f, 310.0f, 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("", 40.0f, 40.0f, RED);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> music_text = std::make_unique<ecs::entity::Entity>();
    music_text->addComponent<ecs::component::Transform>(400.0f, 200.0f, 0.0f, 0.0f);
    music_text->addComponent<ecs::component::Drawable2D>("Choose the Music", 50.0f, BLACK);
    music_text->addComponent<ecs::component::Drawable2D>("", 70.0f, 470.0f, BLUE);
    addEntity(std::move(music_text));

    std::unique_ptr<ecs::entity::Entity> set_music_0 = std::make_unique<ecs::entity::Entity>();
    set_music_0->addComponent<ecs::component::Transform>(400.0f, 300.0f, 0.0f, 0.0f);
    set_music_0->addComponent<ecs::component::Drawable2D>("0", 50.0f, BLACK);
    set_music_0->addComponent<ecs::component::Drawable2D>("", 70.0f, 70.0f, BLUE);
    addEntity(std::move(set_music_0));

    std::unique_ptr<ecs::entity::Entity> set_music_25 = std::make_unique<ecs::entity::Entity>();
    set_music_25->addComponent<ecs::component::Transform>(400.0f, 400.0f, 0.0f, 0.0f);
    set_music_25->addComponent<ecs::component::Drawable2D>("25", 50.0f, BLACK);
    set_music_25->addComponent<ecs::component::Drawable2D>("", 70.0f, 70.0f, BLUE);
    addEntity(std::move(set_music_25));

    std::unique_ptr<ecs::entity::Entity> set_music_50 = std::make_unique<ecs::entity::Entity>();
    set_music_50->addComponent<ecs::component::Transform>(400.0f, 500.0f, 0.0f, 0.0f);
    set_music_50->addComponent<ecs::component::Drawable2D>("50", 50.0f, BLACK);
    set_music_50->addComponent<ecs::component::Drawable2D>("", 70.0f, 70.0f, BLUE);
    addEntity(std::move(set_music_50));

    std::unique_ptr<ecs::entity::Entity> set_music_75 = std::make_unique<ecs::entity::Entity>();
    set_music_75->addComponent<ecs::component::Transform>(400.0f, 600.0f, 0.0f, 0.0f);
    set_music_75->addComponent<ecs::component::Drawable2D>("75", 50.0f, BLACK);
    set_music_75->addComponent<ecs::component::Drawable2D>("", 70.0f, 70.0f, BLUE);
    addEntity(std::move(set_music_75));

    std::unique_ptr<ecs::entity::Entity> set_music_100 = std::make_unique<ecs::entity::Entity>();
    set_music_100->addComponent<ecs::component::Transform>(400.0f, 700.0f, 0.0f, 0.0f);
    set_music_100->addComponent<ecs::component::Drawable2D>("100", 50.0f, BLACK);
    set_music_100->addComponent<ecs::component::Drawable2D>("", 70.0f, 70.0f, BLUE);
    addEntity(std::move(set_music_100));

    std::unique_ptr<ecs::entity::Entity> options = std::make_unique<ecs::entity::Entity>();
    options->addComponent<ecs::component::Transform>(400.0f, 800.0f, 0.0f, 0.0f);
    options->addComponent<ecs::component::Drawable2D>("Back to options", 50.0f, BLACK);
    options->addComponent<ecs::component::Drawable2D>("", 70.0f, 470.0f, BLUE);
    addEntity(std::move(options));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemOption = std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemOption));
}

void indie::menu::SetMusicScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::SetMusicScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::DOWN) {
        indie::ecs::component::Transform *transformCompo =
            _entities.at(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(320.0f, checkCursorPosition(true), 0.0f, 0.0f);
    }
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::UP) {
        ecs::component::Transform *transformCompo =
            _entities.at(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(320.0f, checkCursorPosition(false), 0.0f, 0.0f);
    }
    // if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == MUSIC_0) {
    //     indie::raylib::Sound::setVolume(0.0);
    // }
    // if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == MUSIC_25) {
    //     indie::raylib::Sound::setVolume(0.25);
    // }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == OPTIONS)
        return 3;
    return 0;
}

void indie::menu::SetMusicScreen::update(float delta)
{
    (void) delta;
}

void indie::menu::SetMusicScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::SetMusicScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

int indie::menu::SetMusicScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == MUSIC_0) {
            _cursorPosition = MUSIC_25;
            return MUSIC_25;
        }
        if (_cursorPosition == MUSIC_25) {
            _cursorPosition = MUSIC_50;
            return MUSIC_50;
        }
        if (_cursorPosition == MUSIC_50) {
            _cursorPosition = MUSIC_75;
            return MUSIC_75;
        }
        if (_cursorPosition == MUSIC_75) {
            _cursorPosition = MUSIC_100;
            return MUSIC_100;
        }
        if (_cursorPosition == MUSIC_100) {
            _cursorPosition = OPTIONS;
            return OPTIONS;
        }
        if (_cursorPosition == OPTIONS) {
            return OPTIONS;
        }
    } else if (!direction) {
        if (_cursorPosition == MUSIC_0) {
            return MUSIC_0;
        }
        if (_cursorPosition == MUSIC_25) {
            _cursorPosition = MUSIC_0;
            return MUSIC_0;
        }
        if (_cursorPosition == MUSIC_50) {
            _cursorPosition = MUSIC_25;
            return MUSIC_25;
        }
        if (_cursorPosition == MUSIC_75) {
            _cursorPosition = MUSIC_50;
            return MUSIC_50;
        }
        if (_cursorPosition == MUSIC_100) {
            _cursorPosition = MUSIC_75;
            return MUSIC_75;
        }
        if (_cursorPosition == OPTIONS) {
            _cursorPosition = MUSIC_100;
            return MUSIC_100;
        }
    }
    return 0;
}
