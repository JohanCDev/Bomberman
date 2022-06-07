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
    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(
        static_cast<float>(320.0), static_cast<float>(510.0), static_cast<float>(0.0), static_cast<float>(0.0));
    cursor->addComponent<ecs::component::Drawable2D>("", static_cast<float>(40.0), static_cast<float>(40.0), RED);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> new_game = std::make_unique<ecs::entity::Entity>();
    new_game->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(500.0), static_cast<float>(0.0), static_cast<float>(0.0));
    new_game->addComponent<ecs::component::Drawable2D>("Resume", static_cast<float>(50.0), BLACK);
    new_game->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    addEntity(std::move(new_game));

    std::unique_ptr<ecs::entity::Entity> save = std::make_unique<ecs::entity::Entity>();
    save->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(600.0), static_cast<float>(0.0), static_cast<float>(0.0));
    save->addComponent<ecs::component::Drawable2D>("Save", static_cast<float>(50.0), BLACK);
    save->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    addEntity(std::move(save));

    std::unique_ptr<ecs::entity::Entity> load_game = std::make_unique<ecs::entity::Entity>();
    load_game->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(700.0), static_cast<float>(0.0), static_cast<float>(0.0));
    load_game->addComponent<ecs::component::Drawable2D>("Menu", static_cast<float>(50.0), BLACK);
    load_game->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    addEntity(std::move(load_game));

    std::unique_ptr<ecs::entity::Entity> options = std::make_unique<ecs::entity::Entity>();
    options->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(800.0), static_cast<float>(0.0), static_cast<float>(0.0));
    options->addComponent<ecs::component::Drawable2D>("Exit", static_cast<float>(50.0), BLACK);
    options->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(270.0), BLUE);
    addEntity(std::move(options));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemGameOptions =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemGameOptions));
}

void indie::menu::GameOptionsScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::GameOptionsScreen::handleEvent(indie::Event &event)
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
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == RESUME)
        return 2;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == MENU)
        return 1;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == EXIT)
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
