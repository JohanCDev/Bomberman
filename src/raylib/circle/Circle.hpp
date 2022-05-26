/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Circle
*/

#ifndef CIRCLE_HPP_
#define CIRCLE_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        class Circle {
            public:
                Circle(::Vector2 center, float radius, ::Color color = BLACK);
                ~Circle() = default;

                /**
                * @brief Draw a color-filled circle (Vector version)
                */
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
                * @brief Check collision between two circles
                */
                bool checkCollision(::Vector2 center2, float radius2);
            private:
                ::Vector2 _center;
                float _radius;
                ::Color _color;
        };
    }
}

#endif /* !CIRCLE_HPP_ */
