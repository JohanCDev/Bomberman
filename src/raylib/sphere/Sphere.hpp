/**
 * @file Sphere.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Sphere encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// Sphere class encapsulation
        class Sphere {
          public:
            Sphere(::Vector3 centerPos, float radius, ::Color color = BLACK);
            ~Sphere() = default;

            /**
             * @brief Get cube center position
             */
            ::Vector3 getCenterPosition() const;

            /**
             * @brief Set cube center position
             */
            void setCenterPosition(::Vector3 centerPosition);

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
            static void draw(::Vector3 centerPosition, float radius, ::Color color);

            /**
             * @brief Draw sphere wire
             */
            void drawWires(int rings, int slices);
            static void drawWires(::Vector3 centerPosition, float radius, int rings, int slices, ::Color color);

            /**
             * @brief Check collision spheres
             */
            bool checkCollisionSpheres(const ::Vector3 &sphere2, float radius2);
            static bool checkCollisionSpheres(
                const ::Vector3 &centerPosition, float radius, const ::Vector3 &sphere2, float radius2);

          private:
            ::Vector3 _centerPosition;
            float _radius;
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !SPHERE_HPP_ */
