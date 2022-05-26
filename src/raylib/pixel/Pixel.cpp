/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Pixel
*/

#include "Pixel.hpp"

indie::raylib::Pixel::Pixel(::Vector2 position, ::Color color) : _position(position), _color(color) {}

void indie::raylib::Pixel::draw()
{
    ::DrawPixelV(_position, _color);
}
