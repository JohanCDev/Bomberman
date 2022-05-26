/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Triangle
*/

#include "Triangle.hpp"

indie::raylib::Triangle::Triangle(::Vector2 v1, ::Vector2 v2, ::Vector2 v3, ::Color color) : _v1(v1), _v2(v2), _v3(v3) {}

void indie::raylib::Triangle::draw()
{
    ::DrawTriangle(_v1, _v2, _v3, _color);
}

void indie::raylib::Triangle::drawLines()
{
    ::DrawTriangleLines(_v1, _v2, _v3, _color);
}
