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

bool  indie::raylib::BoundingBox::checkCollisionBoxes(::BoundingBox box2)
{
    return ::CheckCollisionBoxes(_boundingBox, box2);
}

// /**
// * @brief Check collision between this box and a sphere
// */
// bool indie::raylib::BoudingBox::checkCollisionBoxSphere(indie::raylib::Sphere sphere)
// {
//     ::CheckCollisionBoxSphere(_box, sphere.getCenterPosition(), sphere.getRadius());
// }
