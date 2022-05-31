/*
** EPITECH PROJECT, 2022
** Drawable3D
** File description:
** Drawable3D
*/

#include "Drawable3D.hpp"
#include "../IComponent.hpp"

indie::ecs::Drawable3D::Drawable3D()
{
    this->_radius = 0.0;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = WHITE;
    this->_compoType = ecs::compoType::DRAWABLE3D;
    this->_drawableType = ecs::drawableType::UNKNOWN;
}

indie::ecs::Drawable3D::Drawable3D(float radius, Color color)
{
    this->_radius = radius;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = color;
    this->_compoType = ecs::compoType::DRAWABLE3D;
    this->_drawableType = ecs::drawableType::SPHERE;
}

indie::ecs::Drawable3D::Drawable3D(float width, float height, float length, Color color)
{
    this->_radius = 0.0;
    this->_height = height;
    this->_width = width;
    this->_color = color;
    this->_compoType = ecs::compoType::DRAWABLE3D;
    this->_drawableType = ecs::drawableType::CUBE;
}

indie::ecs::Drawable3D::~Drawable3D()
{
}

indie::ecs::compoType indie::ecs::Drawable3D::getType()
{
    return (this->_compoType);
}

indie::ecs::drawableType indie::ecs::Drawable3D::getDrawType()
{
    return (this->_drawableType);
}

Color indie::ecs::Drawable3D::getColor()
{
    return (this->_color);
}

float indie::ecs::Drawable3D::getRadius()
{
    return (this->_radius);
}

float indie::ecs::Drawable3D::getHeight()
{
    return (this->_height);
}

float indie::ecs::Drawable3D::getWidth()
{
    return (this->_width);
}

float indie::ecs::Drawable3D::getLength()
{
    return (this->_length);
}