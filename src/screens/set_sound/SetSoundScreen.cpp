/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** SetSoundScreen.cpp
*/

#include "SetSoundScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::SetSoundScreen::SetSoundScreen() : _cursorPosition(SOUND_0)
{
}

void indie::menu::SetSoundScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(320.0f, 310.0f, 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("", 40.0f, 40.0f, RED);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> sound_text = std::make_unique<ecs::entity::Entity>();
    sound_text->addComponent<ecs::component::Transform>(400.0f, 200.0f, 0.0f, 0.0f);
    sound_text->addComponent<ecs::component::Drawable2D>("Choose the Sound", 50.0f, BLACK);
    sound_text->addComponent<ecs::component::Drawable2D>("", 70.0f, 470.0f, BLUE);
    addEntity(std::move(sound_text));

    std::unique_ptr<ecs::entity::Entity> set_sound_0 = std::make_unique<ecs::entity::Entity>();
    set_sound_0->addComponent<ecs::component::Transform>(400.0f, 300.0f, 0.0f, 0.0f);
    set_sound_0->addComponent<ecs::component::Drawable2D>("0", 50.0f, BLACK);
    set_sound_0->addComponent<ecs::component::Drawable2D>("", 70.0f, 70.0f, BLUE);
    addEntity(std::move(set_sound_0));

    std::unique_ptr<ecs::entity::Entity> set_sound_25 = std::make_unique<ecs::entity::Entity>();
    set_sound_25->addComponent<ecs::component::Transform>(400.0f, 400.0f, 0.0f, 0.0f);
    set_sound_25->addComponent<ecs::component::Drawable2D>("25", 50.0f, BLACK);
    set_sound_25->addComponent<ecs::component::Drawable2D>("", 70.0f, 70.0f, BLUE);
    addEntity(std::move(set_sound_25));

    std::unique_ptr<ecs::entity::Entity> set_sound_50 = std::make_unique<ecs::entity::Entity>();
    set_sound_50->addComponent<ecs::component::Transform>(400.0f, 500.0f, 0.0f, 0.0f);
    set_sound_50->addComponent<ecs::component::Drawable2D>("50", 50.0f, BLACK);
    set_sound_50->addComponent<ecs::component::Drawable2D>("", 70.0f, 70.0f, BLUE);
    addEntity(std::move(set_sound_50));

    std::unique_ptr<ecs::entity::Entity> set_sound_75 = std::make_unique<ecs::entity::Entity>();
    set_sound_75->addComponent<ecs::component::Transform>(400.0f, 600.0f, 0.0f, 0.0f);
    set_sound_75->addComponent<ecs::component::Drawable2D>("75", 50.0f, BLACK);
    set_sound_75->addComponent<ecs::component::Drawable2D>("", 70.0f, 70.0f, BLUE);
    addEntity(std::move(set_sound_75));

    std::unique_ptr<ecs::entity::Entity> set_sound_100 = std::make_unique<ecs::entity::Entity>();
    set_sound_100->addComponent<ecs::component::Transform>(400.0f, 700.0f, 0.0f, 0.0f);
    set_sound_100->addComponent<ecs::component::Drawable2D>("100", 50.0f, BLACK);
    set_sound_100->addComponent<ecs::component::Drawable2D>("", 70.0f, 70.0f, BLUE);
    addEntity(std::move(set_sound_100));

    std::unique_ptr<ecs::entity::Entity> options = std::make_unique<ecs::entity::Entity>();
    options->addComponent<ecs::component::Transform>(400.0f, 800.0f, 0.0f, 0.0f);
    options->addComponent<ecs::component::Drawable2D>("Back to options", 50.0f, BLACK);
    options->addComponent<ecs::component::Drawable2D>("", 70.0f, 470.0f, BLUE);
    addEntity(std::move(options));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemOption =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemOption));
}

void indie::menu::SetSoundScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::SetSoundScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::DOWN  || event.key.down) {
        indie::ecs::component::Transform *transformCompo =
            _entities.at(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(320.0f, checkCursorPosition(true), 0.0f, 0.0f);
    }
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::UP  || event.key.up) {
        ecs::component::Transform *transformCompo =
            _entities.at(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(320.0f, checkCursorPosition(false), 0.0f, 0.0f);
    }
    // if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == SOUND_0) {
    //     indie::raylib::Sound::setVolume(0.0);
    // }
    // if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == SOUND_25) {
    //     indie::raylib::Sound::setVolume(0.25);
    // }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter) && _cursorPosition == OPTIONS)
        return 3;
    return 0;
}

void indie::menu::SetSoundScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::SetSoundScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::SetSoundScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

int indie::menu::SetSoundScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == SOUND_0) {
            _cursorPosition = SOUND_25;
            return SOUND_25;
        }
        if (_cursorPosition == SOUND_25) {
            _cursorPosition = SOUND_50;
            return SOUND_50;
        }
        if (_cursorPosition == SOUND_50) {
            _cursorPosition = SOUND_75;
            return SOUND_75;
        }
        if (_cursorPosition == SOUND_75) {
            _cursorPosition = SOUND_100;
            return SOUND_100;
        }
        if (_cursorPosition == SOUND_100) {
            _cursorPosition = OPTIONS;
            return OPTIONS;
        }
        if (_cursorPosition == OPTIONS) {
            return OPTIONS;
        }
    } else if (!direction) {
        if (_cursorPosition == SOUND_0) {
            return SOUND_0;
        }
        if (_cursorPosition == SOUND_25) {
            _cursorPosition = SOUND_0;
            return SOUND_0;
        }
        if (_cursorPosition == SOUND_50) {
            _cursorPosition = SOUND_25;
            return SOUND_25;
        }
        if (_cursorPosition == SOUND_75) {
            _cursorPosition = SOUND_50;
            return SOUND_50;
        }
        if (_cursorPosition == SOUND_100) {
            _cursorPosition = SOUND_75;
            return SOUND_75;
        }
        if (_cursorPosition == OPTIONS) {
            _cursorPosition = SOUND_100;
            return SOUND_100;
        }
    }
    return 0;
}
