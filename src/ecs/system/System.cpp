/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** System
*/

#include "System.hpp"

void ecs::MovementSystem::update(std::vector<std::unique_ptr<ecs::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->getAlive() == true && entity->hasCompoType(ecs::compoType::TRANSFORM)) {
            ecs::Transform *transformCompo = entity->getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
            transformCompo->setX(transformCompo->getX() + transformCompo->getSpeedX());
            transformCompo->setY(transformCompo->getY() + transformCompo->getSpeedY());
        }
    }
}
