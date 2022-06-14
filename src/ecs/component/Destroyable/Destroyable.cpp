/**
 * @file Destroyable.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Destroyable component source file
 * @version 0.1
 * @date 2022-06-03
 *
 * @copyright Copyright (c) 2022
 *
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