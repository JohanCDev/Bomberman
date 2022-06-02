/*
** EPITECH PROJECT, 2022
** Movement
** File description:
** Movement
*/

#include "Movement.hpp"

void indie::ecs::MovementSystem::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->getAlive() == true && entity->hasCompoType(ecs::compoType::TRANSFORM)) {
            indie::ecs::Transform *transformCompo = entity->getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
            transformCompo->setX(transformCompo->getX() + transformCompo->getSpeedX());
            transformCompo->setY(transformCompo->getY() + transformCompo->getSpeedY());
        }
    }
}

indie::ecs::SystemType indie::ecs::MovementSystem::getSystemType() const
{
    return (indie::ecs::SystemType::MOVEMENTSYSTEM);
}