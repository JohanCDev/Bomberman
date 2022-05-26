/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Cube
*/

#include "Cube.hpp"

indie::raylib::Cube::Cube(float x, float y, float z, float width, float height, float length)
{
    _position.x = x;
    _position.y = y;
    _position.z = z;
    _size.x = width;
    _size.y = height;
    _size.z = length;
}

indie::raylib::Cube::Cube(float x, float y, float z, float width, float height, float length, ::Color color)
{
    _position.x = x;
    _position.y = y;
    _position.z = z;
    _size.x = width;
    _size.y = height;
    _size.z = length;
    _color = color;
}

::Vector3 indie::raylib::Cube::getPosition() const
{
    return _position;
}

void indie::raylib::Cube::setPosition(float newX, float newY, float newZ)
{
    _position.x = newX;
    _position.y = newY;
    _position.z = newZ;
}

::Vector3 indie::raylib::Cube::getSize() const
{
    return _size;
}

void indie::raylib::Cube::setSize(float newWidth, float newHeight, float newLength)
{
    _size.x = newWidth;
    _size.y = newHeight;
    _size.z = newLength;
}

::Color indie::raylib::Cube::getColor() const {
    return _color;
}

void indie::raylib::Cube::setColor(::Color color) {
    _color = color;
}

void indie::raylib::Cube::draw()
{
    ::DrawCubeV(_position, _size, _color);
}

void indie::raylib::Cube::drawWires()
{
    ::DrawCubeWiresV(_position, _size, _color);
}