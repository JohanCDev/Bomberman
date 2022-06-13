/**
 * @file Cylinder.cpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Cylinder encapsulation source file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Cylinder.hpp"

indie::raylib::Cylinder::Cylinder(
    ::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, ::Color color)
    : _position(position), _radiusTop(radiusTop), _radiusBottom(radiusBottom), _height(height), _slices(slices),
      _color(color)
{
}

::Vector3 indie::raylib::Cylinder::getPosition() const
{
    return _position;
}

void indie::raylib::Cylinder::setPosition(::Vector3 position)
{
    _position = position;
}

float indie::raylib::Cylinder::getRadiusTop() const
{
    return _radiusTop;
}

void indie::raylib::Cylinder::setRadiusTop(float radiusTop)
{
    _radiusTop = radiusTop;
}

float indie::raylib::Cylinder::getRadiusBottom() const
{
    return _radiusBottom;
}

void indie::raylib::Cylinder::setRadiusBottom(float radiusBottom)
{
    _radiusBottom = radiusBottom;
}

float indie::raylib::Cylinder::getHeight() const
{
    return _height;
}

void indie::raylib::Cylinder::setHeight(float height)
{
    _height = height;
}

int indie::raylib::Cylinder::getSlices() const
{
    return _slices;
}

void indie::raylib::Cylinder::setSlices(int slices)
{
    _slices = slices;
}

::Color indie::raylib::Cylinder::getColor() const
{
    return _color;
}

void indie::raylib::Cylinder::setColor(::Color color)
{
    _color = color;
}

void indie::raylib::Cylinder::draw()
{
    ::DrawCylinder(_position, _radiusTop, _radiusBottom, _height, _slices, _color);
}

void indie::raylib::Cylinder::draw(
    ::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, ::Color color)
{
    ::DrawCylinder(position, radiusTop, radiusBottom, height, slices, color);
}

void indie::raylib::Cylinder::drawEx(
    ::Vector3 startPos, ::Vector3 endPos, float radiusTop, float radiusBottom, float height, int slices, ::Color color)
{
    ::DrawCylinderEx(startPos, endPos, radiusTop, radiusBottom, slices, color);
}

void indie::raylib::Cylinder::drawWires()
{
    ::DrawCylinderWires(_position, _radiusTop, _radiusBottom, _height, _slices, _color);
}

void indie::raylib::Cylinder::drawWires(
    ::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, ::Color color)
{
    ::DrawCylinderWires(position, radiusTop, radiusBottom, height, slices, color);
}

void indie::raylib::Cylinder::drawWiresEx(Vector3 startPos, Vector3 endPos)
{
    ::DrawCylinderWiresEx(startPos, endPos, _radiusTop, _radiusBottom, _slices, _color);
}

void indie::raylib::Cylinder::drawWiresEx(
    ::Vector3 startPos, ::Vector3 endPos, float radiusTop, float radiusBottom, float height, int slices, ::Color color)
{
    ::DrawCylinderWiresEx(startPos, endPos, radiusTop, radiusBottom, slices, color);
}
