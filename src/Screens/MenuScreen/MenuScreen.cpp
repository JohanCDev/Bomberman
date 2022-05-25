/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** MenuScreen
*/

#include "MenuScreen.hpp"
#include "../../ecs/raylib/Raylib.hpp"

indie::menu::MenuScreen::MenuScreen()
{
}

void indie::menu::MenuScreen::draw()
{
    std::cout << "MENU SCREEN BOYIIII" << std::endl;
    indie::vec2u WindowDim = Raylib::getWindowDimensions();
    Raylib::beginDrawing();
    Raylib::clearBackground();

    Raylib::drawRectangle(WindowDim.x / 2 - 250 / 2, WindowDim.y / 4 - 100 / 2, 250, 100, BLUE);
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