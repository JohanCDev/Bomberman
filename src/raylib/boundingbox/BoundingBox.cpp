/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** BoundingBox
*/

#include "BoundingBox.hpp"

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

bool indie::raylib::BoundingBox::checkCollisionBoxes(::BoundingBox box1, ::BoundingBox box2)
{
    return ::CheckCollisionBoxes(box1, box2);
}
