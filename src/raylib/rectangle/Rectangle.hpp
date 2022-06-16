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
        /// @brief Rectangle class encapsulation
        class Rectangle {
          public:
            /**
             * @brief Construct a new Rectangle object
             * 
             * @param x Rectangle X position
             * @param y Rectangle Y position
             * @param width Rectangle Width
             * @param height Rectangle Height
             */
            Rectangle(float x, float y, float width, float height);
            /**
             * @brief Construct a new Rectangle object
             * 
             * @param x Rectangle X position
             * @param y Rectangle Y position
             * @param width Rectangle Width
             * @param height Rectangle Height
             * @param color Rectangle Color
             */
            Rectangle(float x, float y, float width, float height, Color color);
            /**
             * @brief Destroy the Rectangle object
             * 
             */
            ~Rectangle() = default;
            /**
             * @brief Get rectangle size
             * 
             * @return Vector2 Rectangle size
             */
            ::Vector2 getSize() const;
            /**
             * @brief Set rectangle width and height
             * 
             * @param newWidth Rectangle width
             * @param newHeight Rectangle height
             */
            void setSize(float newWidth, float newHeight);
            /**
             * @brief Get rectangle posX and posY
             * 
             * @return Vector2 Rectangle position
             */
            ::Vector2 getPosition() const;
            /**
             * @brief Set rectangle posX and posY
             * 
             * @param posX Rectangle X position
             * @param posY Rectangle Y position
             */
            void setPosition(float posX, float posY);
            /**
             * @brief Get rectangle color
             * 
             * @return Color Rectangle color
             */
            ::Color getColor() const;
            /**
             * @brief Set rectangle color
             * 
             * @param color Rectangle color
             */
            void setColor(::Color color);
            /**
             * @brief Draw rectangle
             */
            void draw();
            /**
             * @brief Draw rectangle
             * 
             * @param color Rectangle color
             */
            void draw(::Color color);
            /**
             * @brief Draw rectangle
             * 
             * @param posX Rectangle X position
             * @param posY Rectangle Y position
             * @param width Rectangle width
             * @param height Rectangle height
             * @param color Rectangle color
             */
            static void draw(int posX, int posY, int width, int height, ::Color color);
            /**
             * @brief Get collision rectangle for two rectangles collision
             * 
             * @param rec2 Rectangle object
             * 
             * @return Rectangle The rectangle who's in collision with the first one
             */
            ::Rectangle getCollision(::Rectangle rec2) const;
            /**
             * @brief Check collision between two rectangles
             * 
             * @param rec2 Rectangle object
             * 
             * @return true There is a collision
             * @return false There isn't a collision
             */
            bool checkCollision(::Rectangle rec2) const;

          private:
            /**
             * @brief The rectangle object
             * 
             */
            ::Rectangle _rectangle;
            /**
             * @brief The rectangle color object
             * 
             */
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !RECTANGLE_HPP_ */
