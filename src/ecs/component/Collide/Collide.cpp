/*
** EPITECH PROJECT, 2022
** Collide
** File description:
** Collide
*/

#include "Collide.hpp"

indie::ecs::component::Collide::Collide()
{
}

indie::ecs::component::Collide::~Collide()
{
}

indie::ecs::component::compoType indie::ecs::component::Collide::getType() const
{
    return (indie::ecs::component::compoType::COLLIDE);
}

bool indie::ecs::component::Collide::getXCollide() const
{
    return (this->_xCollide);
}

bool indie::ecs::component::Collide::getYCollide() const
{
    return (this->_yCollide);
}

void indie::ecs::component::Collide::setXCollide(bool collide)
{
    this->_xCollide = collide;
}

void indie::ecs::component::Collide::setYCollide(bool collide)
{
    this->_yCollide = collide;
}

bool checkCollision(indie::ecs::component::Collide *otherEntityCollide);