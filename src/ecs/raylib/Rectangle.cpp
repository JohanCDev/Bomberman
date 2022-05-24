/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Rectangle
*/

#include "Rectangle.hpp"

Raylib::Rectangle::Rectangle(float x, float y, float width, float height)
{
    _rectangle.x = x;
    _rectangle.y = y;
    _rectangle.width = width;
    _rectangle.height = height;
}

bool Raylib::Rectangle::CheckCollision(::Rectangle rec2) const {
    return ::CheckCollisionRecs(_rectangle, rec2);
}

::Rectangle Raylib::Rectangle::GetCollision(::Rectangle rec2) const {
    return ::GetCollisionRec(_rectangle, rec2);
}
