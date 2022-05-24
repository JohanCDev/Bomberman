/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sphere
*/

#include "Sphere.hpp"

Raylib::Sphere::Sphere(::Vector3 centerPos, float radius, ::Color color) : _centerPos(centerPos), _radius(radius), _color(color) {}

::Vector3 Raylib::Sphere::getPosition() const
{
    return _centerPos;
}

void Raylib::Sphere::setPosition(float newX, float newY, float newZ)
{
    _centerPos.x = newX;
    _centerPos.y = newY;
    _centerPos.z = newZ;
}

float Raylib::Sphere::getRadius() const
{
    return _radius;
}

void Raylib::Sphere::setRadius(float radius)
{
    _radius = radius;
}

::Color Raylib::Sphere::getColor() const
{
    return _color;
}

void Raylib::Sphere::setColor(::Color color)
{
    _color = color;
}

void Raylib::Sphere::draw()
{
    ::DrawSphere(_centerPos, _radius, _color);
}

void Raylib::Sphere::drawWires(int rings, int slices)
{
    ::DrawSphereWires(_centerPos, _radius, rings, slices, _color);
}

bool Raylib::Sphere::checkCollisionSpheres(const ::Vector3& sphere2, float radius2)
{
    return ::CheckCollisionSpheres(_centerPos, _radius, sphere2, radius2);
}

