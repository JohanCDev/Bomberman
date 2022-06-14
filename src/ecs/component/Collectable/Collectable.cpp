/**
 * @file Collectable.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Collectable component source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
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