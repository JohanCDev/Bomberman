/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** EndScreen.cpp
*/

#include "EndScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::EndScreen::EndScreen()
{
    std::unique_ptr<ecs::entity::Entity> launch_game = std::make_unique<ecs::entity::Entity>();
    launch_game->addComponent<ecs::component::Transform>(
        static_cast<float>(600.0), static_cast<float>(850.0), static_cast<float>(0.0), static_cast<float>(0.0));
    launch_game->addComponent<ecs::component::Drawable2D>(
        "Press X to go back to the menu", static_cast<float>(40.0), BLACK);
    addEntity(std::move(launch_game));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemEnd = std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemEnd));
}

void indie::menu::EndScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::EndScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].code == indie::Event::ControllerCode::X_BUTTON)
        return 1;
    return 0;
}

void indie::menu::EndScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::EndScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::EndScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}
