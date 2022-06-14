/**
 * @file Rectangle.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Rectangle encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef RECTANGLE_HPP_
#define RECTANGLE_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// Rectangle class encapsulation
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
            void draw(::Color color);
            static void draw(int posX, int posY, int width, int height, ::Color color);

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
    } // namespace raylib
} // namespace indie

#endif /* !RECTANGLE_HPP_ */
