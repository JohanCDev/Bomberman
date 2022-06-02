/*
** EPITECH PROJECT, 2022
** Drawable3D
** File description:
** Drawable3D
*/

#include "Drawable3D.hpp"
#include "../IComponent.hpp"

indie::ecs::component::Drawable3D::Drawable3D()
{
    this->_radius = 0.0;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = WHITE;
    this->_compoType = indie::ecs::component::compoType::DRAWABLE3D;
    this->_drawableType = indie::ecs::component::drawableType::UNKNOWNDRAWABLE;
}

indie::ecs::component::Drawable3D::Drawable3D(float radius, Color color)
{
    this->_radius = radius;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = color;
    this->_compoType = indie::ecs::component::compoType::DRAWABLE3D;
    this->_drawableType = indie::ecs::component::drawableType::SPHERE;
}

indie::ecs::component::Drawable3D::Drawable3D(float width, float height, float length, Color color)
{
    this->_radius = 0.0;
    this->_height = height;
    this->_width = width;
    this->_color = color;
    this->_compoType = indie::ecs::component::compoType::DRAWABLE3D;
    this->_drawableType = indie::ecs::component::drawableType::CUBE;
}

indie::ecs::component::Drawable3D::~Drawable3D()
{
}

indie::ecs::component::compoType indie::ecs::component::Drawable3D::getType() const
{
    return (this->_compoType);
}

indie::ecs::component::drawableType indie::ecs::component::Drawable3D::getDrawType()
{
    return (this->_drawableType);
}

Color indie::ecs::component::Drawable3D::getColor()
{
    return (this->_color);
}

float indie::ecs::component::Drawable3D::getRadius()
{
    return (this->_radius);
}

float indie::ecs::component::Drawable3D::getHeight()
{
    return (this->_height);
}

float indie::ecs::component::Drawable3D::getWidth()
{
    return (this->_width);
}

float indie::ecs::component::Drawable3D::getLength()
{
    return (this->_length);
}