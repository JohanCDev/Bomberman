/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** Wall
*/

#include "Component.hpp"

ecs::Rectangle::Rectangle()
{
}

ecs::Rectangle::Rectangle(std::string texture, float height, float width, Color color)
{
    this->_height = height;
    this->_width = width;
    this->_color = color;
    this->_texture_path = texture;
    this->_texture = LoadTexture(this->_texture_path.c_str());
    this->_drawType = ecs::drawableType::D2;
}

ecs::Rectangle::~Rectangle()
{
}

ecs::compoType ecs::Rectangle::getType()
{
    return (ecs::compoType::RECTANGLE);
}

void ecs::Rectangle::draw(ecs::Transform transformCompo)
{
    indie::raylib::Rectangle rectangle(transformCompo.getX(), transformCompo.getY(), this->_width, this->_height);

    if (this->_texture_path == "") {
        rectangle.draw();
    }
}

bool ecs::Rectangle::isDrawable(ecs::drawableType drawType)
{
    if (this->_drawType == drawType) {
        return (true);
    } else {
        return (false);
    }
}
