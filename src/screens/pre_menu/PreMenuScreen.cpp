/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** PreMenuScreen.hpp
*/

#include "PreMenuScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::PreMenuScreen::PreMenuScreen()
{
    std::unique_ptr<ecs::entity::Entity> launch_game = std::make_unique<ecs::entity::Entity>();
    launch_game->addComponent<ecs::component::Transform>(
        static_cast<float>(600.0), static_cast<float>(850.0), static_cast<float>(0.0), static_cast<float>(0.0));
    launch_game->addComponent<ecs::component::Drawable2D>(
        "Press Triangle to start the game", static_cast<float>(40.0), BLACK);
    addEntity(std::move(launch_game));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemPreMenu =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemPreMenu));
}

void indie::menu::PreMenuScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::PreMenuScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].code == indie::Event::ControllerCode::T_BUTTON)
        return 2;
    return 0;
}

void indie::menu::PreMenuScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::PreMenuScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::PreMenuScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}
