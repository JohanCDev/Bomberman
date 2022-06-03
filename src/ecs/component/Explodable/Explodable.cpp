/*
** EPITECH PROJECT, 2022
** Explodable
** File description:
** Explodable
*/

#include "Explodable.hpp"

indie::ecs::component::Explodable::Explodable()
{
    this->_range = 0.0;
    this->_explosionTime = 2;
    this->_dropped = false;
}

indie::ecs::component::Explodable::Explodable(float range, int explosionTime)
{
    this->_range = range;
    this->_explosionTime = explosionTime;
    this->_dropped = false;
}

indie::ecs::component::Explodable::~Explodable()
{
}

indie::ecs::component::compoType indie::ecs::component::Explodable::getType() const
{
    return (indie::ecs::component::compoType::EXPLODABLE);
}

void indie::ecs::component::Explodable::setRange(float range)
{
    this->_range = range;
}

void indie::ecs::component::Explodable::setExplosionTime(int explosionTime)
{
    this->_explosionTime = explosionTime;
}

void indie::ecs::component::Explodable::setDropped(bool dropped)
{
    this->_dropped = dropped;
}

void indie::ecs::component::Explodable::setExploded(bool exploded)
{
    this->_exploded = exploded;
}

float indie::ecs::component::Explodable::getRange() const
{
    return (this->_range);
}

int indie::ecs::component::Explodable::getExplosionTime() const
{
    return (this->_explosionTime);
}

bool indie::ecs::component::Explodable::getDropped() const
{
    return (this->_dropped);
}

bool indie::ecs::component::Explodable::getExploded() const
{
    return (true);
}