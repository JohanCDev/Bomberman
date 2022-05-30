/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Cube
*/

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
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

                /**
                * @brief Draw cube wire
                */
                void drawWires();

                /**
                * @brief Draw cube textured
                */
                void drawTexture(::Texture2D texture, float width, float height, float length);

            private:
                ::Vector3 _position;
                ::Vector3 _size;
                ::Color _color;
        };
    }
}

#endif /* !CUBE_HPP_ */
