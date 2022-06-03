/*
** EPITECH PROJECT, 2022
** Movement
** File description:
** Movement
*/

#include "Movement.hpp"

void indie::ecs::system::MovementSystem::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::TRANSFORM)) {
            indie::ecs::component::Transform *transformCompo =
                entity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            if (entity->hasCompoType(indie::ecs::component::compoType::COLLIDE) == true) {
                if (entity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::compoType::COLLIDE)
                        ->getCollide()
                    == false) {
                    transformCompo->setX(transformCompo->getX() + transformCompo->getSpeedX());
                    transformCompo->setY(transformCompo->getY() + transformCompo->getSpeedY());
                }
            }
        }
    }
}

indie::ecs::system::SystemType indie::ecs::system::MovementSystem::getSystemType() const
{
    return (indie::ecs::system::SystemType::MOVEMENTSYSTEM);
}