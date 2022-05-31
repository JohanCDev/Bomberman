/*
** EPITECH PROJECT, 2022
** Drawable2D
** File description:
** Drawable2D
*/

#include "Drawable2D.hpp"
#include "../IComponent.hpp"

indie::ecs::Drawable2D::Drawable2D()
{
    this->_radius = 0.0;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = WHITE;
    this->_compoType = ecs::compoType::DRAWABLE2D;
    this->_drawableType = ecs::drawableType::UNKNOWN;
}

indie::ecs::Drawable2D::Drawable2D(float radius, Color color)
{
    this->_radius = radius;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = color;
    this->_compoType = ecs::compoType::DRAWABLE2D;
    this->_drawableType = ecs::drawableType::CIRCLE;
}

indie::ecs::Drawable2D::Drawable2D(float height, float width, Color color)
{
    this->_radius = 0.0;
    this->_height = height;
    this->_width = width;
    this->_color = color;
    this->_compoType = ecs::compoType::DRAWABLE2D;
    this->_drawableType = ecs::drawableType::RECTANGLE;
}

indie::ecs::Drawable2D::Drawable2D(std::string text, float fontSize, Color color)
{
    this->_radius = 0.0;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = color;
    this->_text = text;
    this->_fontSize = fontSize;
    this->_compoType = ecs::compoType::DRAWABLE2D;
    this->_drawableType = ecs::drawableType::TEXT;
}

std::string indie::ecs::Drawable2D::getText()
{
    return (this->_text);
}

float indie::ecs::Drawable2D::getFontSize()
{
    return (this->_fontSize);
}

indie::ecs::Drawable2D::~Drawable2D()
{
}

indie::ecs::compoType indie::ecs::Drawable2D::getType()
{
    return (this->_compoType);
}

indie::ecs::drawableType indie::ecs::Drawable2D::getDrawType()
{
    return (this->_drawableType);
}

Color indie::ecs::Drawable2D::getColor()
{
    return (this->_color);
}

float indie::ecs::Drawable2D::getRadius()
{
    return (this->_radius);
}

float indie::ecs::Drawable2D::getHeight()
{
    return (this->_height);
}

float indie::ecs::Drawable2D::getWidth()
{
    return (this->_width);
}