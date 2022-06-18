/**
 * @file BoundingBox.cpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Bounding Box encapsulation source file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "BoundingBox.hpp"

indie::raylib::BoundingBox::BoundingBox(::Vector3 min, ::Vector3 max, ::Color color)
{
    _boundingBox.min = min;
    _boundingBox.max = max;
    _color = color;
}

::BoundingBox indie::raylib::BoundingBox::getBoundingBox() const
{
    return _boundingBox;
}

void indie::raylib::BoundingBox::setBoundingBox(::Vector3 min, ::Vector3 max)
{
    _boundingBox.min = min;
    _boundingBox.max = max;
}

::Color indie::raylib::BoundingBox::getColor() const
{
    return _color;
}

void indie::raylib::BoundingBox::setColor(::Color color)
{
    _color = color;
}

void indie::raylib::BoundingBox::draw()
{
    ::DrawBoundingBox(_boundingBox, _color);
}

void indie::raylib::BoundingBox::draw(::Color color)
{
    ::DrawBoundingBox(_boundingBox, color);
}

void indie::raylib::BoundingBox::draw(::BoundingBox boundingBox, ::Color color)
{
    ::DrawBoundingBox(boundingBox, color);
}

void indie::raylib::BoundingBox::draw(::Vector3 min, ::Vector3 max, ::Color color)
{
    ::BoundingBox box;

    box.min = min;
    box.max = max;
    ::DrawBoundingBox(box, color);
}

bool indie::raylib::BoundingBox::checkCollisionBoxes(::BoundingBox box2)
{
    return ::CheckCollisionBoxes(_boundingBox, box2);
}

bool indie::raylib::BoundingBox::checkCollisionBoxes(::BoundingBox box1, ::BoundingBox box2)
{
    return ::CheckCollisionBoxes(box1, box2);
}

bool indie::raylib::BoundingBox::checkCollisionBoxSphere(::Vector3 center, float radius)
{
    return ::CheckCollisionBoxSphere(_boundingBox, center, radius);
}

bool indie::raylib::BoundingBox::checkCollisionBoxSphere(::BoundingBox box, ::Vector3 center, float radius)
{
    return ::CheckCollisionBoxSphere(box, center, radius);
}

::BoundingBox indie::raylib::BoundingBox::getModelBox(::Model model)
{
    return ::GetModelBoundingBox(model);
}
