/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "../Raylib.hpp"

namespace raylib {
    class Rectangle {
        public:
            Rectangle(float x, float y, float width, float height);
            Rectangle(float x, float y, float width, float height, Color color);
            ~Rectangle() = default;

            /**
            * @brief Get rectangle width and height
            */
            ::Vector2 getSize() const;

            /**
            * @brief Set rectangle width and height
            */
            void setSize(float newWidth, float newHeight);

            /**
            * @brief Get rectangle posX and posY
            */
            ::Vector2 getPosition() const;

            /**
            * @brief Set rectangle posX and posY
            */
            void setPosition(float posX, float posY);

            /**
            * @brief Get rectangle color
            */
            ::Color getColor() const;

            /**
            * @brief Set rectangle color
            */
            void setColor(::Color color);

            /**
            * @brief Draw rectangle
            */
            void draw();

            /**
            * @brief Draw rectangle with color as parameter
            */
            void draw(Color color);

            /**
            * @brief Get collision rectangle for two rectangles collision
            */
            ::Rectangle getCollision(::Rectangle rec2) const;

            /**
            * @brief Check collision between two rectangles
            */
            bool checkCollision(::Rectangle rec2) const;

        private:
            ::Rectangle _rectangle;
            ::Color _color;
    };
}

#endif /* !RECTANGLE_HPP_ */
