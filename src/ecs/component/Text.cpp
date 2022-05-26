/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** Wall
*/

#include "Component.hpp"

ecs::Text::Text()
{
}

ecs::Text::Text(std::string text, float textSize, Color color)
{
    this->_textSize = textSize;
    this->_color = color;
    this->_text = text;
    this->_drawType = ecs::drawableType::D2;
}

ecs::Text::~Text()
{
}

ecs::compoType ecs::Text::getType()
{
    return (ecs::compoType::TEXT);
}

void ecs::Text::draw(ecs::Transform transformCompo)
{
    Raylib raylib;
    raylib.drawText(this->_text, transformCompo.getX(), transformCompo.getY(), this->_textSize, this->_color);
}

bool ecs::Text::isDrawable(ecs::drawableType drawType)
{
    if (this->_drawType == drawType) {
        return (true);
    } else {
        return (false);
    }
}