/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** MenuScreen
*/

#include <raylib.h>
#include "MenuScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::MenuScreen::MenuScreen()
{
}

void indie::menu::MenuScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

    for (auto &system: this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Rectangle rectangle(indie::raylib::Window::getWidth() / 2 - 250 / 2, indie::raylib::Window::getHeight() / 4 - 100 / 2, 250, 100, BLUE);
    rectangle.draw();
    indie::raylib::Window::endDrawing();
}

void indie::menu::MenuScreen::handleEvent(indie::Event &event)
{
    (void)event;
}

void indie::menu::MenuScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::MenuScreen::addEntity(std::unique_ptr<ecs::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::MenuScreen::addSystem(std::unique_ptr<ecs::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}
