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
    return (indie::ecs::compoType::DRAWABLE2D);
}