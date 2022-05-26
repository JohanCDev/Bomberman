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
    ::CheckCollisionBoxes(_boundingBox, box2);
}

// /**
// * @brief Check collision between this box and a sphere
// */
// bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);


