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

indie::ecs::component::Collide::Collide(BoundingBox boundingBox) : _boundingBox(boundingBox)
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

bool indie::ecs::component::Collide::checkCollision(indie::ecs::component::Collide *otherEntityCollide)
{
    return (true);
}

BoundingBox indie::ecs::component::Collide::getBoundingBox() const
{
    return (this->_boundingBox);
}

void indie::ecs::component::Collide::setBoundingBox(BoundingBox boundingBox)
{
    this->_boundingBox = boundingBox;
}

void indie::ecs::component::Collide::setCollide(bool collide)
{
    this->_collide = collide;
}

bool indie::ecs::component::Collide::getCollide() const
{
    return (this->_collide);
}