/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sphere
*/

#include "Sphere.hpp"

indie::raylib::Sphere::Sphere(::Vector3 centerPos, float radius, ::Color color) : _centerPos(centerPos), _radius(radius), _color(color) {}

::Vector3 indie::raylib::Sphere::getPosition() const
{
    return _centerPos;
}

void indie::raylib::Sphere::setPosition(float newX, float newY, float newZ)
{
    _centerPos.x = newX;
    _centerPos.y = newY;
    _centerPos.z = newZ;
}

float indie::raylib::Sphere::getRadius() const
{
    return _radius;
}

void indie::raylib::Sphere::setRadius(float radius)
{
    _radius = radius;
}

::Color indie::raylib::Sphere::getColor() const
{
    return _color;
}

void indie::raylib::Sphere::setColor(::Color color)
{
    _color = color;
}

void indie::raylib::Sphere::draw()
{
    ::DrawSphere(_centerPos, _radius, _color);
}

void indie::raylib::Sphere::drawWires(int rings, int slices)
{
    ::DrawSphereWires(_centerPos, _radius, rings, slices, _color);
}

bool indie::raylib::Sphere::checkCollisionSpheres(const ::Vector3& sphere2, float radius2)
{
    return ::CheckCollisionSpheres(_centerPos, _radius, sphere2, radius2);
}

