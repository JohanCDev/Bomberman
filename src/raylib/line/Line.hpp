/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Line
*/

#ifndef LINE_HPP_
#define LINE_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        class Line {
            public:
                Line(::Vector2 startPos, ::Vector2 endPos, ::Color color = BLACK);
                ~Line() = default;

                /**
                * @brief Draw a line (Vector version)
                */
                void draw();

                /**
                * @brief Draw a line defining thickness
                */
                void drawEx(float thick);

                /**
                * @brief Draw a line using cubic-bezier curves in-out
                */
                void drawBezier(float thick);

                /**
                * @brief Draw line using quadratic bezier curves with a control point
                */
                void drawBezierQuad(::Vector2 controlPos, float thick);

                /**
                * @brief Draw line using cubic bezier curves with 2 control points
                */
                void drawBezierCubic(::Vector2 startControlPos, ::Vector2 endControlPos, float thick);

            private:
                ::Vector2 _startPos;
                ::Vector2 _endPos;
                ::Color _color;
        };
    }
}

#endif /* !LINE_HPP_ */
