/*
** EPITECH PROJECT, 2022
** Entity
** File description:
** Entity
*/

#include "Entity.hpp"

indie::ecs::Entity::Entity()
{
}

indie::ecs::Entity::~Entity()
{
}

/*template<typename T, typename... Args>
void indie::ecs::Entity::addComponent(Args... args)
{
    
}*/

void indie::ecs::Entity::getPosition()
{
    std::unique_ptr<indie::ecs::IComponent> component = std::move(this->_componentMap["N3ecs8PositionE"]);
    std::cout << "pos: " << component->getX() << " " << component->getY() << std::endl;
}

void indie::ecs::Entity::getMovement()
{
    std::unique_ptr<indie::ecs::IComponent> component = std::move(this->_componentMap["N3ecs8MovementE"]);
    std::cout << "pos: " << component->getX() << " " << component->getY() << std::endl;
}

void indie::ecs::Entity::getCircleRadius()
{
    std::unique_ptr<indie::ecs::IComponent> component = std::move(this->_componentMap["N3ecs6CircleE"]);
    std::cout << "circle radius: " << component->getX() << std::endl;
}