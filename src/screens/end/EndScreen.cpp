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
}

void indie::menu::EndScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> launch_game = std::make_unique<ecs::entity::Entity>();
    launch_game->addComponent<ecs::component::Transform>(600.0f, 850.0f, 0.0f, 0.0f);
    launch_game->addComponent<ecs::component::Drawable2D>("Press X to go back to the menu", 40.0f, BLACK);
    addEntity(std::move(launch_game));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemEnd = std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemEnd));
}

void indie::menu::EndScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::EndScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
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
