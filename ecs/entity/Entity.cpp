/*
** EPITECH PROJECT, 2022
** Entity
** File description:
** Entity
*/

#include "Entity.hpp"

ecs::Entity::Entity()
{
}

ecs::Entity::~Entity()
{
}

/*template<typename T, typename... Args>
void ecs::Entity::addComponent(Args... args)
{
    
}*/

void ecs::Entity::getPosition()
{
    ecs::IComponent pos = this->_componentMap["N3ecs8PositionE"];
    std::cout << "pos: " << pos.x << " " << pos.y << std::endl;
}

void ecs::Entity::getMovement()
{
    ecs::IComponent movement = this->_componentMap["N3ecs8MovementE"];
    std::cout << "movement: " << movement.x << " " << movement.y << std::endl;
}