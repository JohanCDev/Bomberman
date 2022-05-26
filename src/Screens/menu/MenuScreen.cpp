/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** MenuScreen
*/

#include "MenuScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::MenuScreen::MenuScreen()
{
}

void indie::menu::MenuScreen::draw()
{
    std::cout << "MENU SCREEN BOYIIII" << std::endl;
    indie::vec2u WindowDim = indie::Raylib::getWindowDimensions();
    indie::Raylib::beginDrawing();
    indie::Raylib::clearBackground();

    indie::Raylib::drawRectangle(WindowDim.x / 2 - 250 / 2, WindowDim.y / 4 - 100 / 2, 250, 100, BLUE);
    indie::Raylib::endDrawing();
}

void indie::menu::MenuScreen::handleEvent(indie::Event &event)
{
    (void)event;
}

void indie::menu::MenuScreen::update(float delta)
{
    (void)delta;
}