/**
 * @file Drawable3D.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Drawable3D component source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Drawable3D.hpp"
#include "../IComponent.hpp"

indie::ecs::component::Drawable3D::Drawable3D()
{
    this->_radius = 0.0;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = WHITE;
    this->_texturePath = "";
    this->_compoType = indie::ecs::component::compoType::DRAWABLE3D;
    this->_drawableType = indie::ecs::component::drawableType::UNKNOWNDRAWABLE;
}

indie::ecs::component::Drawable3D::Drawable3D(float radius, Color color)
{
    this->_radius = radius;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = color;
    this->_texturePath = "";
    this->_compoType = indie::ecs::component::compoType::DRAWABLE3D;
    this->_drawableType = indie::ecs::component::drawableType::SPHERE;
}

indie::ecs::component::Drawable3D::Drawable3D(
    std::string texturePath, float width, float height, float length, Color color)
{
    this->_radius = 0.0;
    this->_height = height;
    this->_width = width;
    this->_length = length;
    this->_color = color;
    this->_texturePath = texturePath;
    this->_texture = indie::raylib::Texture2D::load(texturePath.c_str());
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

std::string indie::ecs::component::Drawable3D::getTexturePath() const
{
    return (this->_texturePath);
}

void indie::ecs::component::Drawable3D::setTexturePath(std::string texturePath)
{
    this->_texturePath = texturePath;
}

Texture2D indie::ecs::component::Drawable3D::getTexture() const
{
    return (this->_texture);
}

void indie::ecs::component::Drawable3D::setTexture(std::string texturePath)
{
    indie::raylib::Texture2D::unload(this->_texture);
    this->_texturePath = texturePath;
    this->_texture = indie::raylib::Texture2D::load(texturePath.c_str());
}