/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** Transform
*/

#include "Component.hpp"

indie::ecs::Transform::Transform()
{
    this->_posX = 0;
    this->_posY = 0;
    this->_speedX = 0;
    this->_speedY = 0;
}

indie::ecs::Transform::Transform(float posX, float posY, float speedX, float speedY)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_speedX = speedX;
    this->_speedY = speedY;
}

indie::ecs::Transform::~Transform()
{
}

indie::ecs::compoType indie::ecs::Transform::getType(void)
{
    return (ecs::compoType::TRANSFORM);
}

void indie::ecs::Transform::printProperties()
{
    std::cout << this->_posX << " " << this->_posY << " " << this->_speedX << " " << this->_speedY << std::endl;
}

void indie::ecs::Transform::update(float posX, float posY, float speedX, float speedY)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_speedX = speedX;
    this->_speedY = speedY;
}

float indie::ecs::Transform::getX() const
{
    return (this->_posX);
}

float indie::ecs::Transform::getY() const
{
    return (this->_posY);
}

void indie::ecs::Transform::setX(float posX)
{
    this->_posX = posX;
}

void indie::ecs::Transform::setY(float posY)
{
    this->_posY = posY;
}

float indie::ecs::Transform::getSpeedX() const
{
    return (this->_speedX);
}

float indie::ecs::Transform::getSpeedY() const
{
    return (this->_speedY);
}