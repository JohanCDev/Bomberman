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
                * @brief Get triangle v1
                */
                ::Vector2 getVec1() const;

                /**
                * @brief Set triangle v1
                */
                void setVec1(::Vector2 v1);

                /**
                * @brief Get triangle v2
                */
                ::Vector2 getVec2() const;

                /**
                * @brief Set triangle v2
                */
                void setVec2(::Vector2 v2);

                /**
                * @brief Get triangle v3
                */
                ::Vector2 getVec3() const;

                /**
                * @brief Set triangle v3
                */
                void setVec3(::Vector2 v3);

                /**
                * @brief Get triangle color
                */
                ::Color getColor() const;

                /**
                * @brief Set triangle color
                */
                void setColor(::Color color);

                /**
                * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
                */
                void draw();

                /**
                * @brief Draw triangle outline (vertex in counter-clockwise order!)
                */
                void drawLines();

                /**
                * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
                */
                void draw3D(Vector3 v1, Vector3 v2, Vector3 v3);

            private:
                ::Vector2 _v1;
                ::Vector2 _v2;
                ::Vector2 _v3;
                ::Color _color;
        };
    }
}

#endif /* !TRIANGLE_HPP_ */
