/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Draw
*/

#include "Draw.hpp"

void indie::raylib::Draw::drawText(const std::string text, int posX, int posY, int fontSize, Color color)
{
    ::DrawText(text.c_str(), posX, posY, fontSize, color);
}
