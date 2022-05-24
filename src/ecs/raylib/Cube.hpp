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
            * @brief Check collision between two spheres
            */
            bool checkCollisionSpheres(float radius1, const ::Vector3& sphere2, float radius2);

            // /**
            // * @brief Check collision between two boxes
            // */
            // bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2)

            /**
            * @brief Check collision between box and sphere
            */
            // bool checkCollisionBoxSphere(BoundingBox box, Vector3 center, float radius)

        private:
            ::Vector3 _position;
            ::Vector3 _size;
            ::Color _color;
    };
}

#endif /* !CUBE_HPP_ */
