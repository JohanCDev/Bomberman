/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Circle
*/

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        class Circle {
          public:
            Circle(::Vector2 center, float radius, ::Color color = BLACK);
            ~Circle() = default;

            /**
             * @brief Get center
             */
            ::Vector2 getCenter() const;

            /**
             * @brief Set center
             */
            void setCenter(::Vector2 center);

            /**
             * @brief Get radius
             */
            float getRadius() const;

            /**
             * @brief Set radius
             */
            void setRadius(float radius);

            /**
             * @brief Get circle color
             */
            ::Color getColor() const;

            /**
             * @brief Set circle color
             */
            void setColor(::Color color);

            /**
             * @brief Draw a color-filled circle (Vector version)
             */
            static void draw(float x, float y, float radius, ::Color color);
            void draw();

            /**
             * @brief Draw a piece of a circle
             */
            void drawSector(float startAngle, float endAngle, int segments);

            /**
             * @brief Draw circle sector outline
             */
            void drawSectorLines(float startAngle, float endAngle, int segments);

            /**
             * @brief Draw a circle in 3D world space
             */
            void draw3D(Vector3 center, Vector3 rotationAxis, float rotationAngle);

            /**
             * @brief Check collision between two circles
             */
            bool checkCollision(::Vector2 center2, float radius2);

          private:
            ::Vector2 _center;
            float _radius;
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !CIRCLE_HPP_ */
