/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../Raylib.hpp"

namespace raylib {
    class Sphere {
        public:
            Sphere(::Vector3 centerPos, float radius, ::Color color);
            ~Sphere() = default;

            /**
            * @brief Get cube center position
            */
            ::Vector3 getPosition() const;

            /**
            * @brief Set cube center position
            */
            void setPosition(float newX, float newY, float newZ);

            /**
            * @brief Get cube radius
            */
            float getRadius() const;

            /**
            * @brief Set cube radius
            */
            void setRadius(float radius);

            /**
            * @brief Get cube color
            */
            ::Color getColor() const;

            /**
            * @brief Set cube color
            */
            void setColor(::Color color);

            /**
            * @brief Draw sphere
            */
            void draw();

            /**
            * @brief Draw sphere wire
            */
            void drawWires(int rings, int slices);

            /**
            * @brief Check collision spheres
            */
            bool checkCollisionSpheres(const ::Vector3& sphere2, float radius2);

        private:
            ::Vector3 _centerPos;
            float _radius;
            ::Color _color;
    };
}

#endif /* !SPHERE_HPP_ */
