/*
** EPITECH PROJECT, 2022
** Entity
** File description:
** Entity
*/

#include "Entity.hpp"

indie::ecs::entity::Entity::Entity()
{
}

indie::ecs::entity::Entity::Entity(indie::ecs::entity::entityType type)
{
    this->_type = type;
}

indie::ecs::entity::Entity::~Entity()
{
}

indie::ecs::entity::entityType indie::ecs::entity::Entity::getEntityType() const
{
    return (this->_type);
}