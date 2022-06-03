/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Cube
*/

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        class Cube {
          public:
            Cube(float x, float y, float z, float width, float height, float length);
            Cube(float x, float y, float z, float width, float height, float length, ::Color color);
            ~Cube() = default;

            /**
             * @brief Get cube position
             */
            ::Vector3 getPosition() const;

            /**
             * @brief Set cube position
             */
            void setPosition(float newX, float newY, float newZ);

            /**
             * @brief Get cube size
             */
            ::Vector3 getSize() const;

            /**
             * @brief Set cube size
             */
            void setSize(float newWidth, float newHeight, float newLength);

            /**
             * @brief Get rectangle color
             */
            ::Color getColor() const;

            /**
             * @brief Set rectangle color
             */
            void setColor(::Color color);

            /**
             * @brief Draw cube
             */
            void draw();
            static void draw(::Vector3 position, ::Vector3 size, ::Color color);

            /**
             * @brief Draw cube wire
             */
            void drawWires();
            static void drawWires(::Vector3 position, ::Vector3 size, ::Color color);

            /**
             * @brief Draw cube textured
             */
            static void drawTexture(
                ::Texture2D texture, ::Vector3 position, float width, float height, float length, ::Color color);

          private:
            ::Vector3 _position;
            ::Vector3 _size;
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !CUBE_HPP_ */
