/**
 * @file Drawable2D.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Drawable2D component source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Drawable2D.hpp"
#include "../IComponent.hpp"

indie::ecs::component::Drawable2D::Drawable2D()
{
    this->_radius = 0.0;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = WHITE;
    this->_compoType = indie::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = indie::ecs::component::drawableType::UNKNOWNDRAWABLE;
}

indie::ecs::component::Drawable2D::Drawable2D(float radius, Color color)
{
    this->_radius = radius;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = color;
    this->_compoType = indie::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = indie::ecs::component::drawableType::CIRCLE;
}

indie::ecs::component::Drawable2D::Drawable2D(std::string texturePath, float height, float width, Color color)
{
    this->_radius = 0.0;
    this->_height = height;
    this->_width = width;
    this->_color = color;
    this->_texturePath = texturePath;
    if (!texturePath.empty())
        this->_texture = indie::raylib::Texture2D::load(texturePath.c_str());
    this->_compoType = indie::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = indie::ecs::component::drawableType::RECTANGLE;
}

indie::ecs::component::Drawable2D::Drawable2D(std::string text, float fontSize, Color color)
{
    this->_radius = 0.0;
    this->_height = 0.0;
    this->_width = 0.0;
    this->_color = color;
    this->_text = text;
    this->_fontSize = fontSize;
    this->_compoType = indie::ecs::component::compoType::DRAWABLE2D;
    this->_drawableType = indie::ecs::component::drawableType::TEXT;
}

std::string indie::ecs::component::Drawable2D::getText()
{
    return (this->_text);
}

float indie::ecs::component::Drawable2D::getFontSize()
{
    return (this->_fontSize);
}

indie::ecs::component::Drawable2D::~Drawable2D()
{
}

indie::ecs::component::compoType indie::ecs::component::Drawable2D::getType() const
{
    return (this->_compoType);
}

indie::ecs::component::drawableType indie::ecs::component::Drawable2D::getDrawType()
{
    return (this->_drawableType);
}

Color indie::ecs::component::Drawable2D::getColor()
{
    return (this->_color);
}

float indie::ecs::component::Drawable2D::getRadius()
{
    return (this->_radius);
}

float indie::ecs::component::Drawable2D::getHeight()
{
    return (this->_height);
}

float indie::ecs::component::Drawable2D::getWidth()
{
    return (this->_width);
}

std::string indie::ecs::component::Drawable2D::getTexturePath() const
{
    return (this->_texturePath);
}

void indie::ecs::component::Drawable2D::setTexturePath(std::string texturePath)
{
    this->_texturePath = texturePath;
}

Texture2D indie::ecs::component::Drawable2D::getTexture() const
{
    return (this->_texture);
}

void indie::ecs::component::Drawable2D::setTexture(std::string texturePath)
{
    indie::raylib::Texture2D::unload(this->_texture);
    this->_texturePath = texturePath;
    this->_texture = indie::raylib::Texture2D::load(texturePath.c_str());
}

void indie::ecs::component::Drawable2D::setText(std::string text)
{
    this->_text = text;
}

void indie::ecs::component::Drawable2D::setFontSize(float fontSize)
{
    this->_fontSize = fontSize;
}

void indie::ecs::component::Drawable2D::setRadius(float radius)
{
    this->_radius = radius;
}

void indie::ecs::component::Drawable2D::setHeight(float height)
{
    this->_height = height;
}

void indie::ecs::component::Drawable2D::setWidth(float width)
{
    this->_width = width;
}