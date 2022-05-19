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
    std::unique_ptr<ecs::IComponent> component = std::move(this->_componentMap["N3ecs8PositionE"]);
    std::cout << "pos: " << component->getX() << " " << component->getY() << std::endl;
}

void ecs::Entity::getMovement()
{
    std::unique_ptr<ecs::IComponent> component = std::move(this->_componentMap["N3ecs8MovementE"]);
    std::cout << "pos: " << component->getX() << " " << component->getY() << std::endl;
}

void ecs::Entity::getCircleRadius()
{
    std::unique_ptr<ecs::IComponent> component = std::move(this->_componentMap["N3ecs6CircleE"]);
    std::cout << "circle radius: " << component->getX() << std::endl;
}