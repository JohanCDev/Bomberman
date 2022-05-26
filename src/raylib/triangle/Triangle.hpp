/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Triangle
*/

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        class Triangle {
            public:
                Triangle(::Vector2 v1, ::Vector2 v2, ::Vector2 v3, ::Color color = BLACK);
                ~Triangle() = default;

                /**
                * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
                */
                void draw();
                /**
                * @brief Draw triangle outline (vertex in counter-clockwise order!)
                */
                void drawLines();

            private:
                ::Vector2 _v1;
                ::Vector2 _v2;
                ::Vector2 _v3;
                ::Color _color;
        };
    }
}

#endif /* !TRIANGLE_HPP_ */
