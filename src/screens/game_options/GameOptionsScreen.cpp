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
    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(320.0f, 510.0f, 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("", 40.0f, 40.0f, RED);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> new_game = std::make_unique<ecs::entity::Entity>();
    new_game->addComponent<ecs::component::Transform>(400.0f, 500.0f, 0.0f, 0.0f);
    new_game->addComponent<ecs::component::Drawable2D>("Resume", 50.0f, BLACK);
    new_game->addComponent<ecs::component::Drawable2D>("", 70.0f, 270.0f, BLUE);
    addEntity(std::move(new_game));

    std::unique_ptr<ecs::entity::Entity> save = std::make_unique<ecs::entity::Entity>();
    save->addComponent<ecs::component::Transform>(400.0f, 600.0f, 0.0f, 0.0f);
    save->addComponent<ecs::component::Drawable2D>("Save", 50.0f, BLACK);
    save->addComponent<ecs::component::Drawable2D>("", 70.0f, 270.0f, BLUE);
    addEntity(std::move(save));

    std::unique_ptr<ecs::entity::Entity> load_game = std::make_unique<ecs::entity::Entity>();
    load_game->addComponent<ecs::component::Transform>(400.0f, 700.0f, 0.0f, 0.0f);
    load_game->addComponent<ecs::component::Drawable2D>("Menu", 50.0f, BLACK);
    load_game->addComponent<ecs::component::Drawable2D>("", 70.0f, 270.0f, BLUE);
    addEntity(std::move(load_game));

    std::unique_ptr<ecs::entity::Entity> options = std::make_unique<ecs::entity::Entity>();
    options->addComponent<ecs::component::Transform>(400.0f, 800.0f, 0.0f, 0.0f);
    options->addComponent<ecs::component::Drawable2D>("Exit", 50.0f, BLACK);
    options->addComponent<ecs::component::Drawable2D>("", 70.0f, 270.0f, BLUE);
    addEntity(std::move(options));

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
            _entities.at(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(320.0f, checkCursorPosition(true), 0.0f, 0.0f);
    }
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::UP || event.key.up) {
        ecs::component::Transform *transformCompo =
            _entities.at(0)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(320.0f, checkCursorPosition(false), 0.0f, 0.0f);
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter) && _cursorPosition == RESUME)
        return 2;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter) && _cursorPosition == MENU)
        return 1;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter) && _cursorPosition == EXIT)
        return 10;
    return 0;
}

void indie::menu::GameOptionsScreen::update(float delta)
{
    (void)delta;
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
        if (_cursorPosition == SAVE) {
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
        if (_cursorPosition == RESUME) {
            return RESUME;
        }
        if (_cursorPosition == SAVE) {
            _cursorPosition = RESUME;
            return RESUME;
        }
        if (_cursorPosition == MENU) {
            _cursorPosition = SAVE;
            return SAVE;
        }
        if (_cursorPosition == EXIT) {
            _cursorPosition = MENU;
            return MENU;
        }
    }
    return 0;
}
