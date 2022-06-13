/**
 * @file Sphere.cpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Sphere encapsulation source file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Sphere.hpp"

indie::raylib::Sphere::Sphere(::Vector3 centerPos, float radius, ::Color color)
    : _centerPosition(centerPos), _radius(radius), _color(color)
{
}

::Vector3 indie::raylib::Sphere::getCenterPosition() const
{
    return _centerPosition;
}

void indie::raylib::Sphere::setCenterPosition(::Vector3 centerPos)
{
    _centerPosition = centerPos;
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
    ::DrawSphere(_centerPosition, _radius, _color);
}

void indie::raylib::Sphere::draw(::Vector3 centerPosition, float radius, ::Color color)
{
    ::DrawSphere(centerPosition, radius, color);
}

void indie::raylib::Sphere::drawWires(int rings, int slices)
{
    ::DrawSphereWires(_centerPosition, _radius, rings, slices, _color);
}

void indie::raylib::Sphere::drawWires(::Vector3 centerPosition, float radius, int rings, int slices, ::Color color)
{
    ::DrawSphereWires(centerPosition, radius, rings, slices, color);
}

bool indie::raylib::Sphere::checkCollisionSpheres(const ::Vector3 &sphere2, float radius2)
{
    return ::CheckCollisionSpheres(_centerPosition, _radius, sphere2, radius2);
}

bool indie::raylib::Sphere::checkCollisionSpheres(
    const ::Vector3 &centerPosition, float radius, const ::Vector3 &sphere2, float radius2)
{
    return ::CheckCollisionSpheres(centerPosition, radius, sphere2, radius2);
}
