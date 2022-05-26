/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** Transform
*/

#include "Component.hpp"

ecs::Transform::Transform()
{
    this->_posX = 0;
    this->_posY = 0;
    this->_speedX = 0;
    this->_speedY = 0;
}

ecs::Transform::Transform(float posX, float posY, float posZ, float speedX, float speedY, float speedZ)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_posZ = posZ;
    this->_speedX = speedX;
    this->_speedY = speedY;
    this->_speedZ = speedZ;
    this->_drawType = ecs::drawableType::NONDRAWABLE;
}

ecs::Transform::~Transform()
{
}

ecs::compoType ecs::Transform::getType(void)
{
    return (ecs::compoType::TRANSFORM);
}

void ecs::Transform::printProperties()
{
    std::cout << this->_posX << " " << this->_posY << " " << this->_speedX << " " << this->_speedY << std::endl;
}

void ecs::Transform::update(float posX, float posY, float speedX, float speedY)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_speedX = speedX;
    this->_speedY = speedY;
}

float ecs::Transform::getX() const
{
    return (this->_posX);
}

float ecs::Transform::getY() const
{
    return (this->_posY);
}

float ecs::Transform::getZ() const
{
    return (this->_posZ);
}

void ecs::Transform::setX(float posX)
{
    this->_posX = posX;
}

void ecs::Transform::setY(float posY)
{
    this->_posY = posY;
}

void ecs::Transform::setZ(float posZ)
{
    this->_posZ = posZ;
}

float ecs::Transform::getSpeedX() const
{
    return (this->_speedX);
}

float ecs::Transform::getSpeedY() const
{
    return (this->_speedY);
}

float ecs::Transform::getSpeedZ() const
{
    return (this->_speedZ);
}

bool ecs::Transform::isDrawable(ecs::drawableType drawType)
{
    if (this->_drawType == drawType) {
        return (true);
    } else {
        return (false);
    }
}