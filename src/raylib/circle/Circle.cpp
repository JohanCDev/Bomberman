/**
 * @file Circle.cpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Circle encapsulation source file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Circle.hpp"

indie::raylib::Circle::Circle(::Vector2 center, float radius, ::Color color)
    : _center(center), _radius(radius), _color(color)
{
}

::Vector2 indie::raylib::Circle::getCenter() const
{
    return _center;
}

void indie::raylib::Circle::setCenter(::Vector2 center)
{
    _center = center;
}

float indie::raylib::Circle::getRadius() const
{
    return _radius;
}

void indie::raylib::Circle::setRadius(float radius)
{
    _radius = radius;
}

::Color indie::raylib::Circle::getColor() const
{
    return _color;
}

void indie::raylib::Circle::setColor(::Color color)
{
    _color = color;
}

void indie::raylib::Circle::draw(float x, float y, float radius, ::Color color)
{
    ::DrawCircle(x, y, radius, color);
}

void indie::raylib::Circle::draw(::Vector2 center, float radius, ::Color color)
{
    ::DrawCircleV(center, radius, color);
}

void indie::raylib::Circle::draw()
{
    ::DrawCircleV(_center, _radius, _color);
}

void indie::raylib::Circle::drawSector(float startAngle, float endAngle, int segments)
{
    ::DrawCircleSector(_center, _radius, startAngle, endAngle, segments, _color);
}

void indie::raylib::Circle::drawSectorLines(float startAngle, float endAngle, int segments)
{
    ::DrawCircleSectorLines(_center, _radius, startAngle, endAngle, segments, _color);
}

void indie::raylib::Circle::draw3D(Vector3 center, Vector3 rotationAxis, float rotationAngle)
{
    ::DrawCircle3D(center, _radius, rotationAxis, rotationAngle, _color);
}

bool indie::raylib::Circle::checkCollision(::Vector2 center2, float radius2)
{
    return ::CheckCollisionCircles(_center, _radius, center2, radius2);
}
