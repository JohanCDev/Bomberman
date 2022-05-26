/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

raylib::Rectangle::Rectangle(float x, float y, float width, float height)
{
    _rectangle.x = x;
    _rectangle.y = y;
    _rectangle.width = width;
    _rectangle.height = height;
}

raylib::Rectangle::Rectangle(float x, float y, float width, float height, ::Color color)
{
    _rectangle.x = x;
    _rectangle.y = y;
    _rectangle.width = width;
    _rectangle.height = height;
    _color = color;
}

::Vector2 raylib::Rectangle::getSize() const {
    return {_rectangle.width, _rectangle.height};
}

void raylib::Rectangle::setSize(float newWidth, float newHeight) {
    _rectangle.width = newWidth;
    _rectangle.height = newHeight;
}

::Vector2 raylib::Rectangle::getPosition() const {
    return {_rectangle.width, _rectangle.height};
}

void raylib::Rectangle::setPosition(float posX, float posY) {
    _rectangle.x = posX;
    _rectangle.y = posY;
}

::Color raylib::Rectangle::getColor() const {
    return _color;
}

void raylib::Rectangle::setColor(::Color color) {
    _color = color;
}

void raylib::Rectangle::draw()
{
    ::DrawRectangle(_rectangle.x, _rectangle.y,  _rectangle.width,  _rectangle.height, _color);
}

void raylib::Rectangle::draw(Color color)
{
    ::DrawRectangle(_rectangle.x, _rectangle.y,  _rectangle.width,  _rectangle.height, color);
}

::Rectangle raylib::Rectangle::getCollision(::Rectangle rec2) const {
    return ::GetCollisionRec(_rectangle, rec2);
}

bool raylib::Rectangle::checkCollision(::Rectangle rec2) const {
    return ::CheckCollisionRecs(_rectangle, rec2);
}
