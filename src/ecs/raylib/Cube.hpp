/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Cube
*/

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "Raylib.hpp"

namespace Raylib {
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
            * @brief Draw cube
            */
            void draw();

            /**
            * @brief Draw cube with color as parameter
            */
            void draw(::Color color);

            /**
            * @brief Detect collision between two spheres
            */
            bool checkCollision(float radius1, const ::Vector3& sphere2, float radius2);

        private:
            ::Vector3 _position;
            ::Vector3 _size;
            ::Color _color;
    };
}

#endif /* !CUBE_HPP_ */
