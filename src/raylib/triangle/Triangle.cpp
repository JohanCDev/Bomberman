/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Triangle
*/

#include "Triangle.hpp"

indie::raylib::Triangle::Triangle(::Vector2 v1, ::Vector2 v2, ::Vector2 v3, ::Color color) : _v1(v1), _v2(v2), _v3(v3) {}

::Vector2 indie::raylib::Triangle::getVec1() const
{
    return _v1;
}

void indie::raylib::Triangle::setVec1(::Vector2 v1)
{
    _v1 = v1;
}

::Vector2 indie::raylib::Triangle::getVec2() const
{
    return _v2;
}

void indie::raylib::Triangle::setVec2(::Vector2 v2)
{
    _v2 = v2;
}

::Vector2 indie::raylib::Triangle::getVec3() const
{
    return _v3;
}

void indie::raylib::Triangle::setVec3(::Vector2 v3)
{
    _v3 = v3;
}

::Color indie::raylib::Triangle::getColor() const {
    return _color;
}

void indie::raylib::Triangle::setColor(::Color color) {
    _color = color;
}

void indie::raylib::Triangle::draw()
{
    ::DrawTriangle(_v1, _v2, _v3, _color);
}

void indie::raylib::Triangle::drawLines()
{
    ::DrawTriangleLines(_v1, _v2, _v3, _color);
}

void indie::raylib::Triangle::draw3D(Vector3 v1, Vector3 v2, Vector3 v3)
{
    ::DrawTriangle3D(v1, v2, v3, _color);
}
