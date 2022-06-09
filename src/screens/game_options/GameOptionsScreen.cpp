/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** GameOptionsScreen.cpp
*/

#include "GameOptionsScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::GameOptionsScreen::GameOptionsScreen() : _cursorPosition(RESUME)
{
}

void indie::menu::GameOptionsScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> background = std::make_unique<ecs::entity::Entity>();
    background->addComponent<ecs::component::Transform>(0.0f, 0.0f, 0.0f, 0.0f);
    background->addComponent<ecs::component::Drawable2D>("assets/menu/bg.png", 1200.0f, 2000.0f, WHITE);
    addEntity(std::move(background));

    std::unique_ptr<ecs::entity::Entity> frame = std::make_unique<ecs::entity::Entity>();
    frame->addComponent<ecs::component::Transform>(570.0f, 120.0f, 0.0f, 0.0f);
    frame->addComponent<ecs::component::Drawable2D>("assets/menu/frame.png", 950.0f, 700.0f, WHITE);
    addEntity(std::move(frame));

    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(680.0f, 200.0f, 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("assets/menu/hand.png", 80.0f, 80.0f, WHITE);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> resume = std::make_unique<ecs::entity::Entity>();
    resume->addComponent<ecs::component::Transform>(780.0f, 175.0f, 0.0f, 0.0f);
    resume->addComponent<ecs::component::Drawable2D>("assets/menu/resume.png", 105.0f, 280.0f, WHITE);
    addEntity(std::move(resume));

    std::unique_ptr<ecs::entity::Entity> menu = std::make_unique<ecs::entity::Entity>();
    menu->addComponent<ecs::component::Transform>(780.0f, 300.0f, 0.0f, 0.0f);
    menu->addComponent<ecs::component::Drawable2D>("assets/menu/menu.png", 105.0f, 280.0f, WHITE);
    addEntity(std::move(menu));

    std::unique_ptr<ecs::entity::Entity> save = std::make_unique<ecs::entity::Entity>();
    save->addComponent<ecs::component::Transform>(780.0f, 425.0f, 0.0f, 0.0f);
    save->addComponent<ecs::component::Drawable2D>("assets/menu/save.png", 105.0f, 280.0f, WHITE);
    addEntity(std::move(save));

    std::unique_ptr<ecs::entity::Entity> music = std::make_unique<ecs::entity::Entity>();
    music->addComponent<ecs::component::Transform>(780.0f, 550.0f, 0.0f, 0.0f);
    music->addComponent<ecs::component::Drawable2D>("assets/menu/music.png", 105.0f, 280.0f, WHITE);
    addEntity(std::move(music));

    std::unique_ptr<ecs::entity::Entity> sound = std::make_unique<ecs::entity::Entity>();
    sound->addComponent<ecs::component::Transform>(780.0f, 675.0f, 0.0f, 0.0f);
    sound->addComponent<ecs::component::Drawable2D>("assets/menu/sound.png", 105.0f, 280.0f, WHITE);
    addEntity(std::move(sound));

    std::unique_ptr<ecs::entity::Entity> fps = std::make_unique<ecs::entity::Entity>();
    fps->addComponent<ecs::component::Transform>(780.0f, 800.0f, 0.0f, 0.0f);
    fps->addComponent<ecs::component::Drawable2D>("assets/menu/fps.png", 105.0f, 280.0f, WHITE);
    addEntity(std::move(fps));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
    quit->addComponent<ecs::component::Transform>(780.0f, 925.0f, 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>("assets/menu/quit.png", 105.0f, 280.0f, WHITE);
    addEntity(std::move(quit));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemGameOptions =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemGameOptions));
}

void indie::menu::GameOptionsScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::GameOptionsScreen::handleEvent(indie::Event &event)
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
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == RESUME)
        return 2;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == MENU)
        return 1;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == MUSIC)
        return 6;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == SOUND)
        return 7;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == FPS)
        return 8;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == EXIT)
        return 10;
    return 0;
}

void indie::menu::GameOptionsScreen::update()
{
}

void indie::menu::GameOptionsScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::GameOptionsScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

int indie::menu::GameOptionsScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == RESUME) {
            _cursorPosition = SAVE;
            return SAVE;
        }
        if (_cursorPosition == MENU) {
            _cursorPosition = SAVE;
            return SAVE;
        }
        if (_cursorPosition == SAVE) {
            _cursorPosition = MUSIC;
            return MUSIC;
        }
        if (_cursorPosition == MUSIC) {
            _cursorPosition = SOUND;
            return SOUND;
        }
        if (_cursorPosition == SOUND) {
            _cursorPosition = FPS;
            return FPS;
        }
        if (_cursorPosition == FPS) {
            _cursorPosition = EXIT;
            return EXIT;
        }
        if (_cursorPosition == EXIT)
            return EXIT;
    } else if (!direction) {
        if (_cursorPosition == RESUME) {
            return RESUME;
        }
        if (_cursorPosition == MENU) {
            _cursorPosition = RESUME;
            return RESUME;
        }
        if (_cursorPosition == SAVE) {
            _cursorPosition = MENU;
            return MENU;
        }
        if (_cursorPosition == MUSIC) {
            _cursorPosition = SAVE;
            return SAVE;
        }
        if (_cursorPosition == SOUND) {
            _cursorPosition = MUSIC;
            return MUSIC;
        }
        if (_cursorPosition == FPS) {
            _cursorPosition = SOUND;
            return SOUND;
        }
        if (_cursorPosition == EXIT) {
            _cursorPosition = FPS;
            return FPS;
        }
    }
    return 0;
}
