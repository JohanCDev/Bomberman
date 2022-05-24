/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "Raylib.hpp"

namespace Raylib {
    class Rectangle {
        public:
            Rectangle(float x, float y, float width, float height);
            ~Rectangle() = default;

            /**
            * Check collision between two rectangles
            */
            bool CheckCollision(::Rectangle rec2) const;

            /**
            * Get collision rectangle for two rectangles collision
            */
            ::Rectangle GetCollision(::Rectangle rec2) const;
        private:
            ::Rectangle _rectangle;
    };
}

#endif /* !RECTANGLE_HPP_ */
