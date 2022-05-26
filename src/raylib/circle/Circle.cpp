/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Circle
*/

#include "Circle.hpp"

indie::raylib::Circle::Circle(::Vector2 center, float radius, ::Color color) : _center(center), _radius(radius), _color(color) {}

void indie::raylib::Circle::draw() {
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


