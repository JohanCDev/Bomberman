/*
** EPITECH PROJECT, 2022
** Alive
** File description:
** Alive
*/

#include "Alive.hpp"

indie::ecs::component::Alive::Alive()
{
    this->_alive = true;
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

indie::ecs::component::compoType indie::ecs::component::Alive::getType()
{
    return (indie::ecs::component::compoType::ALIVE);
}