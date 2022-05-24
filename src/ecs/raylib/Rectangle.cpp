/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

Raylib::Rectangle::Rectangle(float x, float y, float width, float height)
{
    _rectangle.x = x;
    _rectangle.y = y;
    _rectangle.width = width;
    _rectangle.height = height;
}

Raylib::Rectangle::Rectangle(float x, float y, float width, float height, ::Color color)
{
    _rectangle.x = x;
    _rectangle.y = y;
    _rectangle.width = width;
    _rectangle.height = height;
    _color = color;
}

::Vector2 Raylib::Rectangle::getSize() {
    return {_rectangle.width, _rectangle.height};
}

::Rectangle &Raylib::Rectangle::setSize(float newWidth, float newHeight) {
    _rectangle.width = newWidth;
    _rectangle.height = newHeight;
    return _rectangle;
}

::Vector2 Raylib::Rectangle::getPosition() {
    return {_rectangle.width, _rectangle.height};
}

::Rectangle &Raylib::Rectangle::setPosition(float posX, float posY) {
    _rectangle.x = posX;
    _rectangle.y = posY;
    return _rectangle;
}

::Color Raylib::Rectangle::getColor() {
    return _color;
}

void Raylib::Rectangle::setColor(::Color color) {
    _color = color;
}

void Raylib::Rectangle::draw()
{
    ::DrawRectangle(_rectangle.x, _rectangle.y,  _rectangle.width,  _rectangle.height, _color);
}

void Raylib::Rectangle::draw(Color color)
{
    ::DrawRectangle(_rectangle.x, _rectangle.y,  _rectangle.width,  _rectangle.height, color);
}

::Rectangle Raylib::Rectangle::getCollision(::Rectangle rec2) const {
    return ::GetCollisionRec(_rectangle, rec2);
}

bool Raylib::Rectangle::checkCollision(::Rectangle rec2) const {
    return ::CheckCollisionRecs(_rectangle, rec2);
}
