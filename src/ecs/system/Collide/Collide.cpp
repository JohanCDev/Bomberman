/*
** EPITECH PROJECT, 2022
** Collide
** File description:
** Collide
*/

#include "Collide.hpp"

indie::ecs::system::Collide::Collide()
{
}

indie::ecs::system::Collide::~Collide()
{
}

indie::ecs::system::SystemType indie::ecs::system::Collide::getSystemType() const
{
    return (indie::ecs::system::SystemType::COLLIDESYSTEM);
}

void indie::ecs::system::Collide::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::COLLIDE)) {
            indie::ecs::component::Collide *collide =
                entity->getComponent<ecs::component::Collide>(ecs::component::compoType::COLLIDE);
            for (auto &otherEntity : entities) {
                if (otherEntity != entity) {
                    indie::ecs::component::Collide *otherEntityCollide =
                        otherEntity->getComponent<ecs::component::Collide>(ecs::component::compoType::COLLIDE);
                    collide->checkCollision(otherEntityCollide);
                }
            }
        }
    }
}