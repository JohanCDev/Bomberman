/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Draw
*/

#include "Draw.hpp"

indie::raylib::Draw::Draw(int posX, int posY, float fontSize, ::Color color) : _posX(posX), _posY(posY), _fontSize(fontSize), _color(color) {}

int indie::raylib::Draw::getPositionX() const
{
    return _posX;
}

void indie::raylib::Draw::setPositionX(int positionX)
{
    _posX = positionX;
}

int indie::raylib::Draw::getPositionY() const
{
    return _posY;
}

void indie::raylib::Draw::setPositionY(int positionY)
{
    _posY = positionY;
}

float indie::raylib::Draw::getFontSize() const
{
    return _fontSize;
}

void indie::raylib::Draw::setFontSize(float fontSize)
{
    _fontSize = fontSize;
}

::Color indie::raylib::Draw::getColor() const
{
    return _color;
}

void indie::raylib::Draw::setColor(::Color color)
{
    _color = color;
}

void indie::raylib::Draw::drawText(const std::string text)
{
    ::DrawText(text.c_str(), _posX, _posY, _fontSize, _color);
}

void indie::raylib::Draw::drawFPS()
{
    ::DrawFPS(_posX, _posY);
}

void indie::raylib::Draw::drawTextEx(::Font font, const char *text, ::Vector2 position, float spacing)
{
    ::DrawTextEx(font, text, position, _fontSize, spacing, _color);
}

void indie::raylib::Draw::drawTextPro(::Font font, const char *text, ::Vector2 position, ::Vector2 origin, float rotation, float spacing)
{
    ::DrawTextPro(font, text, position, origin, rotation, _fontSize, spacing, _color);
}

void indie::raylib::Draw::drawTextCodepoint(::Font font, int codepoint, ::Vector2 position)
{
    ::DrawTextCodepoint(font, codepoint, position,  _fontSize, _color);
}

void indie::raylib::Draw::drawPlane(::Vector3 centerPos, ::Vector2 size)
{
    ::DrawPlane(centerPos, size, _color);
}

void indie::raylib::Draw::drawRay(::Ray ray)
{
    ::DrawRay(ray, _color);
}

void indie::raylib::Draw::drawGrid(int slices, float spacing)
{
    ::DrawGrid(slices, spacing);
}

