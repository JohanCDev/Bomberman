/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Line
*/

#include "Line.hpp"

indie::raylib::Line::Line(::Vector2 startPos, ::Vector2 endPos, ::Color color) : _startPos(startPos), _endPos(endPos), _color(color) {}

void indie::raylib::Line::draw()
{
    ::DrawLineV(_startPos, _endPos, _color);
}

void indie::raylib::Line::drawEx(float thick)
{
    ::DrawLineEx(_startPos, _endPos, thick, _color);
}

void indie::raylib::Line::drawBezier(float thick)
{
    ::DrawLineBezier(_startPos, _endPos, thick, _color);                    // Draw a line using cubic-bezier curves in-out
}

void indie::raylib::Line::drawBezierCubic(::Vector2 startControlPos, ::Vector2 endControlPos, float thick)
{
    ::DrawLineBezierCubic(_startPos, _endPos, startControlPos, endControlPos, thick, _color);
}

void indie::raylib::Line::drawBezierQuad(::Vector2 controlPos, float thick)
{
    DrawLineBezierQuad(_startPos, _endPos, controlPos, thick, _color);
}
