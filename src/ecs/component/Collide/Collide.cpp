/*
** EPITECH PROJECT, 2022
** Collide
** File description:
** Collide
*/

#include "Collide.hpp"

indie::ecs::component::Collide::Collide()
{
    _collide = false;
}

indie::ecs::component::Collide::~Collide()
{
}

indie::ecs::component::compoType indie::ecs::component::Collide::getType() const
{
    return (indie::ecs::component::compoType::COLLIDE);
}

bool indie::ecs::component::Collide::checkCollision(indie::ecs::component::Collide *otherEntityCollide)
{
    return (true);
}

void indie::ecs::component::Collide::setCollide(bool collide)
{
    this->_collide = collide;
}

bool indie::ecs::component::Collide::getCollide() const
{
    return (this->_collide);
}