/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** Wall
*/

#include "Component.hpp"

ecs::Circle::Circle()
{
}

ecs::Circle::Circle(std::string texture, float radius, Color color)
{
    this->_radius = radius;
    this->_color = color;
    this->_texture_path = texture;
    this->_texture = LoadTexture(this->_texture_path.c_str());
    this->_drawType = ecs::drawableType::D2;
}

ecs::Circle::~Circle()
{
}

ecs::compoType ecs::Circle::getType()
{
    return (ecs::compoType::CIRCLE);
}

void ecs::Circle::draw(ecs::Transform transformCompo)
{
    indie::raylib::Circle circle({transformCompo.getX(), transformCompo.getY()}, this->_radius, this->_color);
    // indie::raylib::Circle::draw(transformCompo.getX(), transformCompo.getY(), this->_radius, this->_color);
    if (this->_texture_path == "") {
        circle.draw();
    }
}

bool ecs::Circle::isDrawable(ecs::drawableType drawType)
{
    if (this->_drawType == drawType) {
        return (true);
    } else {
        return (false);
    }
}
