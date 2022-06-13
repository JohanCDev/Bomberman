/**
 * @file Entity.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Entity source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
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