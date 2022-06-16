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
        /// @brief Sphere class encapsulation
        class Sphere {
          public:
            /**
             * @brief Construct a new Sphere object
             * 
             * @param centerPos Sphere centerPos
             * @param radius Sphere radius
             * @param color Sphere color
             */
            Sphere(::Vector3 centerPos, float radius, ::Color color = BLACK);
            /**
             * @brief Destroy the Sphere object
             * 
             */
            ~Sphere() = default;
            /**
             * @brief Get sphere center position
             * 
             * @return Vector3 Sphere center pos
             */
            ::Vector3 getCenterPosition() const;
            /**
             * @brief Set sphere center position
             * 
             * @param centerPosition Sphere centerPosition
             */
            void setCenterPosition(::Vector3 centerPosition);
            /**
             * @brief Get sphere radius
             * 
             * @return float Sphere radius
             */
            float getRadius() const;
            /**
             * @brief Set sphere radius
             * 
             * @param radius Sphere radius
             */
            void setRadius(float radius);
            /**
             * @brief Get sphere color
             * 
             * @return Color Sphere color
             */
            ::Color getColor() const;
            /**
             * @brief Set sphere color
             * 
             * @param color Sphere color
             */
            void setColor(::Color color);
            /**
             * @brief Draw sphere
             */
            void draw();
            /**
             * @brief Draw sphere
             * 
             * @param centerPosition Sphere centerPosition
             * @param radius Sphere radius
             * @param color Sphere color
             */
            static void draw(::Vector3 centerPosition, float radius, ::Color color);
            /**
             * @brief Draw sphere wires
             * 
             * @param rings Sphere rings
             * @param slices Sphere slices
             */
            void drawWires(int rings, int slices);
            /**
             * @brief Draw sphere wires
             * 
             * @param centerPosition Sphere centerPosition
             * @param radius Sphere radius
             * @param rings Sphere rings
             * @param slices Sphere slices
             * @param color Sphere color
             */
            static void drawWires(::Vector3 centerPosition, float radius, int rings, int slices, ::Color color);
            /**
             * @brief Check collision spheres
             * 
             * @param sphere2 Sphere position
             * @param radius2 Sphere radius
             * 
             * @return true There is a collision
             * @return false There isn't a collision
             */
            bool checkCollisionSpheres(const ::Vector3 &sphere2, float radius2);
            /**
             * @brief Check collision spheres
             * 
             * @param centerPosition Sphere centerPosition
             * @param radius Sphere radius
             * @param sphere2 Sphere 2 position
             * @param radius2 Sphere 2 radius
             * 
             * @return true There is a collision
             * @return false There isn't a collision
             */
            static bool checkCollisionSpheres(
                const ::Vector3 &centerPosition, float radius, const ::Vector3 &sphere2, float radius2);

          private:
            /**
             * @brief Sphere centerPosition vector
             * 
             */
            ::Vector3 _centerPosition;
            /**
             * @brief Sphere radius value
             * 
             */
            float _radius;
            /**
             * @brief Sphere color object
             * 
             */
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !SPHERE_HPP_ */
