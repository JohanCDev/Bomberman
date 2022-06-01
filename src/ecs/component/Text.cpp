/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** Wall
*/

#include "Component.hpp"

indie::ecs::Text::Text()
{
}

indie::ecs::Text::Text(std::string text, float textSize, Color color)
{
    this->_textSize = textSize;
    this->_color = color;
    this->_text = text;
}

indie::ecs::Text::~Text()
{
}

indie::ecs::compoType indie::ecs::Text::getType()
{
    return (ecs::compoType::TEXT);
}

void ecs::Text::draw(ecs::Transform transformCompo)
{
    indie::raylib::Draw draw(transformCompo.getX(), transformCompo.getY(), this->_textSize, this->_color);

    draw.drawText(this->_text);
}

bool ecs::Text::isDrawable(ecs::drawableType drawType)
{
    if (this->_drawType == drawType) {
        return (true);
    } else {
        return (false);
    }
}
