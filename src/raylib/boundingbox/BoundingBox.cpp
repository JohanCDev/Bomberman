/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** BoundingBox
*/

#include "BoundingBox.hpp"

indie::raylib::BoundingBox::BoundingBox(::Vector3 min, ::Vector3 max, ::Color color) {
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

::Color indie::raylib::BoundingBox::getColor() const {
    return _color;
}

void indie::raylib::BoundingBox::setColor(::Color color) {
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

bool  indie::raylib::BoundingBox::checkCollisionBoxes(::BoundingBox box2)
{
    return ::CheckCollisionBoxes(_boundingBox, box2);
}

bool indie::raylib::BoundingBox::checkCollisionBoxes(::BoundingBox box1, ::BoundingBox box2)
{
    return ::CheckCollisionBoxes(box1, box2);
}
