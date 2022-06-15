/**
 * @file Explodable.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Explodable component source file
 * @version 0.1
 * @date 2022-06-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Explodable.hpp"

indie::ecs::component::Explodable::Explodable()
{
    this->_range = 0.0;
    this->_explosionTime = 2;
    this->_dropped = true;
    this->_explode = false;
    this->_exploded = false;
}

indie::ecs::component::Explodable::Explodable(float range, int explosionTime) : _seconds(explosionTime)
{
    this->_range = range;
    this->_explosionTime = explosionTime;
    this->_dropped = true;
    this->_explode = false;
    this->_exploded = false;
    this->_tStart = std::chrono::system_clock::now();
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

void indie::ecs::component::Explodable::setExplode(bool explode)
{
    this->_explode = explode;
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

bool indie::ecs::component::Explodable::getExplode() const
{
    return (this->_explode);
}

bool indie::ecs::component::Explodable::getExploded() const
{
    return (this->_exploded);
}

std::chrono::time_point<std::chrono::system_clock> indie::ecs::component::Explodable::getTStart() const
{
    return (this->_tStart);
}

std::chrono::seconds indie::ecs::component::Explodable::getSeconds() const
{
    return (this->_seconds);
}

int indie::ecs::component::Explodable::getPlayer() const
{
    return (this->_player);
}

void indie::ecs::component::Explodable::setPlayer(int player)
{
    this->_player = player;
}