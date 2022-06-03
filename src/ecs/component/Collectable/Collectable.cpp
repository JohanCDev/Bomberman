/*
** EPITECH PROJECT, 2022
** Collectable
** File description:
** Collectable
*/

#include "Collectable.hpp"

indie::ecs::component::Collectable::Collectable()
{
    this->_type = indie::ecs::component::bonusType::UNKNOWNBONUS;
}

indie::ecs::component::Collectable::Collectable(indie::ecs::component::bonusType type)
{
    this->_type = type;
}

indie::ecs::component::Collectable::~Collectable()
{
}

indie::ecs::component::bonusType indie::ecs::component::Collectable::getBonusType() const
{
    return (this->_type);
}

indie::ecs::component::compoType indie::ecs::component::Collectable::getType() const
{
    return (indie::ecs::component::compoType::COLLECTABLE);
}