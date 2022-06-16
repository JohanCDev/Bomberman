/**
 * @file Circle.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Circle encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// Circle class encapsulation
        class Circle {
          public:
            /**
             * @brief Construct a new Circle object
             * 
             * @param center The center value for the Circle
             * @param radius The radius value for the Circle
             * @param color The color for the Circle
             */
            Circle(::Vector2 center, float radius, ::Color color = BLACK);
            /**
             * @brief Destroy the Circle object
             * 
             */
            ~Circle() = default;

            /**
             * @brief Get center
             * 
             * @return Vector2 The Circle Center position
             */
            ::Vector2 getCenter() const;

            /**
             * @brief Set the Center object
             * 
             * @param center The Center position for the Circle
             */
            void setCenter(::Vector2 center);

            /**
             * @brief Get radius
             * 
             * @return float The Circle radius
             */
            float getRadius() const;

            /**
             * @brief Set the Circle radius
             * 
             * @param radius The Circle radius
             */
            void setRadius(float radius);

            /**
             * @brief Get circle color
             * 
             * @return Color The Circle color
             */
            ::Color getColor() const;

            /**
             * @brief Set circle color
             * 
             * @param color The Circle Color
             */
            void setColor(::Color color);
            /**
             * @brief Draw a color-filled circle (Float x, y version)
             * 
             * @param x The Circle position X
             * @param y The Circle position Y
             * @param radius The Circle radius
             * @param color The Circle color
             */
            static void draw(float x, float y, float radius, ::Color color);
            /**
             * @brief Draw a color-filled circle (Vector version)
             * 
             * @param center The Circle Center position
             * @param radius The Circle Radius position
             * @param color The Circle color
             */
            static void draw(::Vector2 center, float radius, ::Color color);
            /**
             * @brief Draw a circle
             * 
             */
            void draw();

            /**
             * @brief Draw a piece of circle
             * 
             * @param startAngle The angle to start drawing
             * @param endAngle The angle to stop drawing
             * @param segments The segment to draw
             */
            void drawSector(float startAngle, float endAngle, int segments);

            /**
             * @brief Draw Sector lines of a circle
             * 
             * @param startAngle The angle to start drawing
             * @param endAngle The angle to stop drawing
             * @param segments The segment to draw
             */
            void drawSectorLines(float startAngle, float endAngle, int segments);

            /**
             * @brief Draw a circle in 3D world space
             * 
             * @param center The Center of the circle
             * @param rotationAxis The Rotation Axis
             * @param rotationAngle The Rotation Angle
             */
            void draw3D(Vector3 center, Vector3 rotationAxis, float rotationAngle);

            /**
             * @brief Check collision between two circles
             * 
             * @param center2 The Center of the circle
             * @param radius2 The Radius of the circle
             * 
             * @return true There is a collision
             * @return false There isn't a collision
             */
            bool checkCollision(::Vector2 center2, float radius2);

          private:
            /**
             * @brief Vector for Circle center
             * 
             */
            ::Vector2 _center;
            /**
             * @brief Circle Radius
             * 
             */
            float _radius;
            /**
             * @brief Circle Color
             * 
             */
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !CIRCLE_HPP_ */
