/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** GameScreen
*/

#include "GameScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::GameScreen::GameScreen()
{
}

void indie::menu::GameScreen::draw()
{
    std::cout << "GAME SCREEN BOYIIIII" << std::endl;
    indie::vec2u WindowDim = indie::Raylib::getWindowDimensions();
    indie::Raylib::beginDrawing();
    indie::Raylib::clearBackground();

    indie::Raylib::drawRectangle(WindowDim.x / 2 - 250 / 2, WindowDim.y / 4 - 100 / 2, 250, 100, GREEN);
    indie::Raylib::endDrawing();
}

void indie::menu::GameScreen::handleEvent(indie::Event &event)
{
    (void)event;
}

void indie::menu::GameScreen::update(float delta)
{
    (void)delta;
}