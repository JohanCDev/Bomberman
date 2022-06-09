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
    std::unique_ptr<ecs::entity::Entity> background = std::make_unique<ecs::entity::Entity>();
    background->addComponent<ecs::component::Transform>(0.0f, 0.0f, 0.0f, 0.0f);
    background->addComponent<ecs::component::Drawable2D>("assets/menu/bg.png", 1200.0f, 2000.0f, WHITE);
    addEntity(std::move(background));

    std::unique_ptr<ecs::entity::Entity> frame = std::make_unique<ecs::entity::Entity>();
    frame->addComponent<ecs::component::Transform>(570.0f, 120.0f, 0.0f, 0.0f);
    frame->addComponent<ecs::component::Drawable2D>("assets/menu/frame.png", 700.0f, 700.0f, WHITE);
    addEntity(std::move(frame));

    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(680.0f, 285.0f, 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("assets/menu/hand.png", 80.0f, 80.0f, WHITE);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
    quit->addComponent<ecs::component::Transform>(730.0f, 600.0f, 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>("Press O to quit !", 40.0f, WHITE);
    addEntity(std::move(quit));

    std::unique_ptr<ecs::entity::Entity> fps30 = std::make_unique<ecs::entity::Entity>();
    fps30->addComponent<ecs::component::Transform>(850.0f, 175.0f, 0.0f, 0.0f);
    fps30->addComponent<ecs::component::Drawable2D>("assets/menu/30fps.png", 230.0f, 250.0f, WHITE);
    addEntity(std::move(fps30));

    std::unique_ptr<ecs::entity::Entity> not_valid30 = std::make_unique<ecs::entity::Entity>();
    not_valid30->addComponent<ecs::component::Transform>(770.0f, 265.0f, 0.0f, 0.0f);
    not_valid30->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png", 90.0f, 90.0f, WHITE);
    addEntity(std::move(not_valid30));

    std::unique_ptr<ecs::entity::Entity> fps60 = std::make_unique<ecs::entity::Entity>();
    fps60->addComponent<ecs::component::Transform>(850.0f, 300.0f, 0.0f, 0.0f);
    fps60->addComponent<ecs::component::Drawable2D>("assets/menu/60fps.png", 250.0f, 250.0f, WHITE);
    addEntity(std::move(fps60));

    std::unique_ptr<ecs::entity::Entity> not_valid60 = std::make_unique<ecs::entity::Entity>();
    not_valid60->addComponent<ecs::component::Transform>(770.0f, 415.0f, 0.0f, 0.0f);
    not_valid60->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png", 90.0f, 90.0f, WHITE);
    addEntity(std::move(not_valid60));

    std::unique_ptr<ecs::entity::Entity> valid60 = std::make_unique<ecs::entity::Entity>();
    valid60->addComponent<ecs::component::Transform>(770.0f, 415.0f, 0.0f, 0.0f);
    valid60->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png", 90.0f, 90.0f, WHITE);
    addEntity(std::move(valid60));

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
        && _cursorPosition == FPS_30) {
        indie::raylib::Window::setTargetFPS(30);
        if (_entities.size() == 9)
            _entities.erase(_entities.begin() + 8);
        std::unique_ptr<ecs::entity::Entity> valid30 = std::make_unique<ecs::entity::Entity>();
        valid30->addComponent<ecs::component::Transform>(770.0f, 265.0f, 0.0f, 0.0f);
        valid30->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png", 90.0f, 90.0f, WHITE);
        addEntity(std::move(valid30));
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == FPS_60) {
        indie::raylib::Window::setTargetFPS(60);
        if (_entities.size() == 9)
            _entities.erase(_entities.begin() + 8);
        std::unique_ptr<ecs::entity::Entity> valid60 = std::make_unique<ecs::entity::Entity>();
        valid60->addComponent<ecs::component::Transform>(770.0f, 415.0f, 0.0f, 0.0f);
        valid60->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png", 90.0f, 90.0f, WHITE);
        addEntity(std::move(valid60));
    }
    if (event.controller[0].code == indie::Event::ControllerCode::O_BUTTON)
        return 4;
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
            return FPS_60;
        }
    } else if (!direction) {
        if (_cursorPosition == FPS_30)
            return FPS_30;
        if (_cursorPosition == FPS_60) {
            _cursorPosition = FPS_30;
            return FPS_30;
        }
    }
    return 0;
}
