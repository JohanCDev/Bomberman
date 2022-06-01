/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** Transform
*/

#include "Transform.hpp"
#include "../IComponent.hpp"

indie::ecs::component::Transform::Transform()
{
    this->_posX = 0;
    this->_posY = 0;
    this->_speedX = 0;
    this->_speedY = 0;
}

indie::ecs::component::Transform::Transform(float posX, float posY, float speedX, float speedY)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_speedX = speedX;
    this->_speedY = speedY;
}

indie::ecs::component::Transform::~Transform()
{
}

indie::ecs::component::compoType indie::ecs::component::Transform::getType(void) const
{
    return (indie::ecs::component::compoType::TRANSFORM);
}

void indie::ecs::component::Transform::update(float posX, float posY, float speedX, float speedY)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_speedX = speedX;
    this->_speedY = speedY;
}

float indie::ecs::component::Transform::getX() const
{
    return (this->_posX);
}

float indie::ecs::component::Transform::getY() const
{
    return (this->_posY);
}

void indie::ecs::component::Transform::setX(float posX)
{
    this->_posX = posX;
}

void indie::ecs::component::Transform::setY(float posY)
{
    this->_posY = posY;
}

float indie::ecs::component::Transform::getSpeedX() const
{
    return (this->_speedX);
}

float indie::ecs::component::Transform::getSpeedY() const
{
    return (this->_speedY);
}