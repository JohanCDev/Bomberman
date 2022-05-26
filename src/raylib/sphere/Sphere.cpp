/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sphere
*/

#include "Sphere.hpp"

raylib::Sphere::Sphere(::Vector3 centerPos, float radius, ::Color color) : _centerPos(centerPos), _radius(radius), _color(color) {}

::Vector3 raylib::Sphere::getPosition() const
{
    return _centerPos;
}

void raylib::Sphere::setPosition(float newX, float newY, float newZ)
{
    _centerPos.x = newX;
    _centerPos.y = newY;
    _centerPos.z = newZ;
}

float raylib::Sphere::getRadius() const
{
    return _radius;
}

void raylib::Sphere::setRadius(float radius)
{
    _radius = radius;
}

::Color raylib::Sphere::getColor() const
{
    return _color;
}

void raylib::Sphere::setColor(::Color color)
{
    _color = color;
}

void raylib::Sphere::draw()
{
    ::DrawSphere(_centerPos, _radius, _color);
}

void raylib::Sphere::drawWires(int rings, int slices)
{
    ::DrawSphereWires(_centerPos, _radius, rings, slices, _color);
}

bool raylib::Sphere::checkCollisionSpheres(const ::Vector3& sphere2, float radius2)
{
    return ::CheckCollisionSpheres(_centerPos, _radius, sphere2, radius2);
}

