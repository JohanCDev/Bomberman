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
    // int width = indie::raylib::Window::getWidth();
    // int height = indie::raylib::Window::getHeight();
    // int width = indie::
    // indie::vec2u WindowDim = indie::raylib::Window::getWindowDimensions();
    // indie::vec2u WindowDim = {1920.0, 1080.0}

    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

    for (auto &ent : this->_entities) {
        ent->draw(ecs::drawableType::D2);
    }

    indie::raylib::Rectangle rectangle(indie::raylib::Window::getWidth() / 2 - 250 / 2, indie::raylib::Window::getHeight() / 4 - 100 / 2, 250, 100, BLUE);
    rectangle.draw();
    indie::raylib::Window::endDrawing();
    // indie::Raylib::drawRectangle(WindowDim.x / 2 - 250 / 2, WindowDim.y / 4 - 100 / 2, 250, 100, BLUE);
    // indie::Raylib::endDrawing();
}

void indie::menu::MenuScreen::handleEvent(indie::Event &event)
{
    (void)event;
}

void indie::menu::MenuScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::MenuScreen::addEntity(std::unique_ptr<ecs::Entity> entity) {
    this->_entities.push_back(std::move(entity));
}
