/*
** EPITECH PROJECT, 2022
** Destroyable
** File description:
** Destroyable
*/

#include "Destroyable.hpp"

indie::ecs::component::Destroyable::Destroyable()
{
}

indie::ecs::component::Destroyable::~Destroyable()
{
}

indie::ecs::component::compoType indie::ecs::component::Destroyable::getType() const
{
    return (indie::ecs::component::compoType::DESTROYABLE);
}