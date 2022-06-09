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
}

void indie::menu::SetMusicScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> background = std::make_unique<ecs::entity::Entity>();
    background->addComponent<ecs::component::Transform>(0.0f, 0.0f, 0.0f, 0.0f);
    background->addComponent<ecs::component::Drawable2D>("assets/menu/bg.png", 1200.0f, 2000.0f, WHITE);
    addEntity(std::move(background));

    std::unique_ptr<ecs::entity::Entity> frame = std::make_unique<ecs::entity::Entity>();
    frame->addComponent<ecs::component::Transform>(570.0f, 120.0f, 0.0f, 0.0f);
    frame->addComponent<ecs::component::Drawable2D>("assets/menu/frame.png", 900.0f, 700.0f, WHITE);
    addEntity(std::move(frame));

    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(680.0f, 285.0f, 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("assets/menu/hand.png", 80.0f, 80.0f, WHITE);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
    quit->addComponent<ecs::component::Transform>(730.0f, 900.0f, 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>("Press O to quit !", 40.0f, WHITE);
    addEntity(std::move(quit));

    std::unique_ptr<ecs::entity::Entity> music_0 = std::make_unique<ecs::entity::Entity>();
    music_0->addComponent<ecs::component::Transform>(850.0f, 175.0f, 0.0f, 0.0f);
    music_0->addComponent<ecs::component::Drawable2D>("assets/menu/0%.png", 230.0f, 250.0f, WHITE);
    addEntity(std::move(music_0));

    std::unique_ptr<ecs::entity::Entity> not_valid0 = std::make_unique<ecs::entity::Entity>();
    not_valid0->addComponent<ecs::component::Transform>(770.0f, 265.0f, 0.0f, 0.0f);
    not_valid0->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png", 90.0f, 90.0f, WHITE);
    addEntity(std::move(not_valid0));

    std::unique_ptr<ecs::entity::Entity> music_25 = std::make_unique<ecs::entity::Entity>();
    music_25->addComponent<ecs::component::Transform>(850.0f, 300.0f, 0.0f, 0.0f);
    music_25->addComponent<ecs::component::Drawable2D>("assets/menu/25%.png", 230.0f, 250.0f, WHITE);
    addEntity(std::move(music_25));

    std::unique_ptr<ecs::entity::Entity> not_valid25 = std::make_unique<ecs::entity::Entity>();
    not_valid25->addComponent<ecs::component::Transform>(770.0f, 380.0f, 0.0f, 0.0f);
    not_valid25->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png", 90.0f, 90.0f, WHITE);
    addEntity(std::move(not_valid25));

    std::unique_ptr<ecs::entity::Entity> music_50 = std::make_unique<ecs::entity::Entity>();
    music_50->addComponent<ecs::component::Transform>(850.0f, 425.0f, 0.0f, 0.0f);
    music_50->addComponent<ecs::component::Drawable2D>("assets/menu/50%.png", 230.0f, 250.0f, WHITE);
    addEntity(std::move(music_50));

    std::unique_ptr<ecs::entity::Entity> not_valid50 = std::make_unique<ecs::entity::Entity>();
    not_valid50->addComponent<ecs::component::Transform>(770.0f, 505.0f, 0.0f, 0.0f);
    not_valid50->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png", 90.0f, 90.0f, WHITE);
    addEntity(std::move(not_valid50));

    std::unique_ptr<ecs::entity::Entity> music_75 = std::make_unique<ecs::entity::Entity>();
    music_75->addComponent<ecs::component::Transform>(850.0f, 550.0f, 0.0f, 0.0f);
    music_75->addComponent<ecs::component::Drawable2D>("assets/menu/75%.png", 230.0f, 250.0f, WHITE);
    addEntity(std::move(music_75));

    std::unique_ptr<ecs::entity::Entity> not_valid75 = std::make_unique<ecs::entity::Entity>();
    not_valid75->addComponent<ecs::component::Transform>(770.0f, 620.0f, 0.0f, 0.0f);
    not_valid75->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png", 90.0f, 90.0f, WHITE);
    addEntity(std::move(not_valid75));

    std::unique_ptr<ecs::entity::Entity> music_100 = std::make_unique<ecs::entity::Entity>();
    music_100->addComponent<ecs::component::Transform>(850.0f, 675.0f, 0.0f, 0.0f);
    music_100->addComponent<ecs::component::Drawable2D>("assets/menu/100%.png", 230.0f, 250.0f, WHITE);
    addEntity(std::move(music_100));

    std::unique_ptr<ecs::entity::Entity> not_valid100 = std::make_unique<ecs::entity::Entity>();
    not_valid100->addComponent<ecs::component::Transform>(770.0f, 745.0f, 0.0f, 0.0f);
    not_valid100->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png", 90.0f, 90.0f, WHITE);
    addEntity(std::move(not_valid100));

    std::unique_ptr<ecs::entity::Entity> valid50 = std::make_unique<ecs::entity::Entity>();
    valid50->addComponent<ecs::component::Transform>(770.0f, 505.0f, 0.0f, 0.0f);
    valid50->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png", 90.0f, 90.0f, WHITE);
    addEntity(std::move(valid50));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemOption =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemOption));
}

void indie::menu::SetMusicScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::SetMusicScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::DOWN || event.key.down) {
        indie::ecs::component::Transform *transformCompo =
            _entities.at(2)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(680.0f, checkCursorPosition(true), 0.0f, 0.0f);
    }
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::UP || event.key.up) {
        ecs::component::Transform *transformCompo =
            _entities.at(2)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(680.0f, checkCursorPosition(false), 0.0f, 0.0f);
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == MUSIC_0) {
        // indie::raylib::Sound::setVolume(0.0);
        if (_entities.size() == 15)
            _entities.erase(_entities.begin() + 14);
        std::unique_ptr<ecs::entity::Entity> valid0 = std::make_unique<ecs::entity::Entity>();
        valid0->addComponent<ecs::component::Transform>(770.0f, 265.0f, 0.0f, 0.0f);
        valid0->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png", 90.0f, 90.0f, WHITE);
        addEntity(std::move(valid0));
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == MUSIC_25) {
        // indie::raylib::Sound::setVolume(0.25);
        if (_entities.size() == 15)
            _entities.erase(_entities.begin() + 14);
        std::unique_ptr<ecs::entity::Entity> valid25 = std::make_unique<ecs::entity::Entity>();
        valid25->addComponent<ecs::component::Transform>(770.0f, 380.0f, 0.0f, 0.0f);
        valid25->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png", 90.0f, 90.0f, WHITE);
        addEntity(std::move(valid25));
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == MUSIC_50) {
        // indie::raylib::Sound::setVolume(0.50);
        if (_entities.size() == 15)
            _entities.erase(_entities.begin() + 14);
        std::unique_ptr<ecs::entity::Entity> valid50 = std::make_unique<ecs::entity::Entity>();
        valid50->addComponent<ecs::component::Transform>(770.0f, 505.0f, 0.0f, 0.0f);
        valid50->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png", 90.0f, 90.0f, WHITE);
        addEntity(std::move(valid50));
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == MUSIC_75) {
        // indie::raylib::Sound::setVolume(0.75);
        if (_entities.size() == 15)
            _entities.erase(_entities.begin() + 14);
        std::unique_ptr<ecs::entity::Entity> valid75 = std::make_unique<ecs::entity::Entity>();
        valid75->addComponent<ecs::component::Transform>(770.0f, 620.0f, 0.0f, 0.0f);
        valid75->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png", 90.0f, 90.0f, WHITE);
        addEntity(std::move(valid75));
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == MUSIC_100) {
        // indie::raylib::Sound::setVolume(0.100);
        if (_entities.size() == 15)
            _entities.erase(_entities.begin() + 14);
        std::unique_ptr<ecs::entity::Entity> valid100 = std::make_unique<ecs::entity::Entity>();
        valid100->addComponent<ecs::component::Transform>(770.0f, 745.0f, 0.0f, 0.0f);
        valid100->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png", 90.0f, 90.0f, WHITE);
        addEntity(std::move(valid100));
    }
    if (event.controller[0].code == indie::Event::ControllerCode::O_BUTTON)
        return 4;
    return 0;
}

void indie::menu::SetMusicScreen::update()
{
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
            return MUSIC_100;
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
    }
    return 0;
}