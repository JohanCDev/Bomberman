/**
 * @file Transform.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Transform component source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Transform.hpp"
#include "../IComponent.hpp"

indie::ecs::component::Transform::Transform()
{
    this->_posX = 0.0;
    this->_posY = 0.0;
    this->_posZ = 0.0;
    this->_speedX = 0.0;
    this->_speedY = 0.0;
}

indie::ecs::component::Transform::Transform(float posX, float posY, float speedX, float speedY)
{
    this->_posX = posX;
    this->_posY = posY;
    this->_posZ = 0.0;
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

void indie::ecs::component::Transform::setSpeedY(float speed)
{
    this->_speedY = speed;
}

void indie::ecs::component::Transform::setSpeedX(float speed)
{
    this->_speedX = speed;
}

void indie::ecs::component::Transform::setZ(float posZ)
{
    this->_posZ = posZ;
}

float indie::ecs::component::Transform::getZ() const
{
    return (this->_posZ);
}