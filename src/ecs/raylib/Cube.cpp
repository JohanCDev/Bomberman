/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Cube
*/

#include "Cube.hpp"

Raylib::Cube::Cube(float x, float y, float z, float width, float height, float length)
{
    _position.x = x;
    _position.y = y;
    _position.z = z;
    _size.x = width;
    _size.y = height;
    _size.z = length;
}

Raylib::Cube::Cube(float x, float y, float z, float width, float height, float length, ::Color color)
{
    _position.x = x;
    _position.y = y;
    _position.z = z;
    _size.x = width;
    _size.y = height;
    _size.z = length;
    _color = color;
}

::Vector3 Raylib::Cube::getPosition() const
{
    return _position;
}

void Raylib::Cube::setPosition(float newX, float newY, float newZ)
{
    _position.x = newX;
    _position.y = newY;
    _position.z = newZ;
}

::Vector3 Raylib::Cube::getSize() const
{
    return _size;
}

void Raylib::Cube::setSize(float newWidth, float newHeight, float newLength)
{
    _size.x = newWidth;
    _size.y = newHeight;
    _size.z = newLength;
}

::Color Raylib::Cube::getColor() const {
    return _color;
}

void Raylib::Cube::setColor(::Color color) {
    _color = color;
}

void Raylib::Cube::draw()
{
    ::DrawCubeV(_position, _size, _color);
}

void Raylib::Cube::drawWires()
{
    ::DrawCubeWiresV(_position, _size, _color);
}

bool Raylib::Cube::checkCollisionSpheres(float radius1, const ::Vector3& sphere2, float radius2)
{
    return ::CheckCollisionSpheres(_position, radius1, sphere2, radius2);
}

