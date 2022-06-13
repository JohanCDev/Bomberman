/**
 * @file Alive.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Alive component source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Alive.hpp"

indie::ecs::component::Alive::Alive()
{
    this->_alive = false;
}

indie::ecs::component::Alive::Alive(bool alive)
{
    this->_alive = alive;
}

indie::ecs::component::Alive::~Alive()
{
}

void indie::ecs::component::Alive::setAlive(bool alive)
{
    this->_alive = alive;
}

bool indie::ecs::component::Alive::getAlive() const
{
    return (this->_alive);
}

indie::ecs::component::compoType indie::ecs::component::Alive::getType() const
{
    return (indie::ecs::component::compoType::ALIVE);
}