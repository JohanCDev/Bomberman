/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** MenuScreen
*/

#include "MenuScreen.hpp"
#include "../../ecs/raylib/Raylib.hpp"

void indie::menu::MenuScreen::CreateMenuEntities()
{
    ecs::Entity background;
}

void indie::menu::MenuScreen::draw()
{
    Raylib::beginDrawing();
    Raylib::clearBackground();

    indie::vec2u WindowDim = Raylib::getWindowDimensions();
    Raylib::drawRectangle((WindowDim.x + 250) / 2, (WindowDim.y + 100) / 2, 250, 100, GREEN);
    Raylib::endDrawing();
}

void indie::menu::MenuScreen::handleEvent(indie::Event &event)
{
    (void)event;
}

void indie::menu::MenuScreen::update(float delta)
{
    (void)delta;
}