/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** SetFpsScreen.cpp
*/

#include "SetFpsScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::SetFpsScreen::SetFpsScreen() : _cursorPosition(FPS_30)
{
}

void indie::menu::SetFpsScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(
        static_cast<float>(320.0), static_cast<float>(410.0), static_cast<float>(0.0), static_cast<float>(0.0));
    cursor->addComponent<ecs::component::Drawable2D>("", static_cast<float>(40.0), static_cast<float>(40.0), RED);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> fps_text = std::make_unique<ecs::entity::Entity>();
    fps_text->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(300.0), static_cast<float>(0.0), static_cast<float>(0.0));
    fps_text->addComponent<ecs::component::Drawable2D>("Choose the FPS", static_cast<float>(50.0), BLACK);
    fps_text->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(470.0), BLUE);
    addEntity(std::move(fps_text));

    std::unique_ptr<ecs::entity::Entity> set_fps_30 = std::make_unique<ecs::entity::Entity>();
    set_fps_30->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(400.0), static_cast<float>(0.0), static_cast<float>(0.0));
    set_fps_30->addComponent<ecs::component::Drawable2D>("30", static_cast<float>(50.0), BLACK);
    set_fps_30->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(70.0), BLUE);
    addEntity(std::move(set_fps_30));

    std::unique_ptr<ecs::entity::Entity> set_fps_60 = std::make_unique<ecs::entity::Entity>();
    set_fps_60->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(500.0), static_cast<float>(0.0), static_cast<float>(0.0));
    set_fps_60->addComponent<ecs::component::Drawable2D>("60", static_cast<float>(50.0), BLACK);
    set_fps_60->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(70.0), BLUE);
    addEntity(std::move(set_fps_60));

    std::unique_ptr<ecs::entity::Entity> options = std::make_unique<ecs::entity::Entity>();
    options->addComponent<ecs::component::Transform>(
        static_cast<float>(400.0), static_cast<float>(600.0), static_cast<float>(0.0), static_cast<float>(0.0));
    options->addComponent<ecs::component::Drawable2D>("Back to options", static_cast<float>(50.0), BLACK);
    options->addComponent<ecs::component::Drawable2D>("", static_cast<float>(70.0), static_cast<float>(470.0), BLUE);
    addEntity(std::move(options));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemOption =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemOption));
}

void indie::menu::SetFpsScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::SetFpsScreen::handleEvent(indie::Event &event)
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
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == FPS_30) {
        indie::raylib::Window::setTargetFPS(30);
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == FPS_60) {
        indie::raylib::Window::setTargetFPS(60);
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == OPTIONS)
        return 3;
    return 0;
}

void indie::menu::SetFpsScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::SetFpsScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::SetFpsScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

int indie::menu::SetFpsScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == FPS_30) {
            _cursorPosition = FPS_60;
            return FPS_60;
        }
        if (_cursorPosition == FPS_60) {
            _cursorPosition = OPTIONS;
            return OPTIONS;
        }
        if (_cursorPosition == OPTIONS)
            return OPTIONS;
    } else if (!direction) {
        if (_cursorPosition == FPS_30)
            return FPS_30;
        if (_cursorPosition == FPS_60) {
            _cursorPosition = FPS_30;
            return FPS_30;
        }
        if (_cursorPosition == OPTIONS) {
            _cursorPosition = FPS_60;
            return FPS_60;
        }
    }
    return 0;
}
