/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Pixel
*/

#include "Pixel.hpp"

indie::raylib::Pixel::Pixel(::Vector2 position, ::Color color) : _position(position), _color(color) {}

::Vector2 indie::raylib::Pixel::getPosition() const
{
    return _position;
}

void indie::raylib::Pixel::setPosition(::Vector2 pos)
{
    _position = pos;
}


::Color indie::raylib::Pixel::getColor() const {
    return _color;
}

void indie::raylib::Pixel::setColor(::Color color) {
    _color = color;
}

void indie::raylib::Pixel::draw()
{
    ::DrawPixelV(_position, _color);
}
