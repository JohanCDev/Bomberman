/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Pixel
*/

#include "Pixel.hpp"

indie::raylib::Pixel::Pixel(::Vector2 vector2, ::Color color) : _vector2(vector2), _color(color) {}

void indie::raylib::Pixel::draw()
{
    ::DrawPixelV(_vector2, _color);
}
