/*
** EPITECH PROJECT, 2022
** Explodable
** File description:
** Explodable
*/

#include "Explodable.hpp"

indie::ecs::system::Explodable::Explodable()
{
}

indie::ecs::system::Explodable::~Explodable()
{
}

void indie::ecs::system::Explodable::destroyBoxes(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities,
    indie::ecs::component::Explodable *explodableCompo, indie::ecs::component::Transform *bombTransformCompo)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::DESTROYABLE)
            && entity->hasCompoType(indie::ecs::component::compoType::ALIVE) == true) {
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
            if ((transformCompo->getX() <= bombTransformCompo->getX() + explodableCompo->getRange())
                && (transformCompo->getY() <= bombTransformCompo->getY() + explodableCompo->getRange())) {
                entity->getComponent<indie::ecs::component::Alive>(indie::ecs::component::compoType::ALIVE)
                    ->setAlive(false);
            } else if (transformCompo->getX() <= bombTransformCompo->getX() - explodableCompo->getRange()
                && transformCompo->getY() <= bombTransformCompo->getY() - explodableCompo->getRange()) {
                entity->getComponent<indie::ecs::component::Alive>(indie::ecs::component::compoType::ALIVE)
                    ->setAlive(false);
            }
        }
    }
}

void indie::ecs::system::Explodable::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    int count = 0;

    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::EXPLODABLE) == true) {
            auto explodableCompo =
                entity->getComponent<ecs::component::Explodable>(ecs::component::compoType::EXPLODABLE);
            if (explodableCompo->getDropped() == true) {
                if (explodableCompo->getExploded() == true) {
                    explodableCompo->setExploded(false);
                    explodableCompo->setDropped(false);
                    destroyBoxes(entities, explodableCompo,
                        entity->getComponent<ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM));
                } else {
                    auto t_now = std::chrono::system_clock::now();
                    std::chrono::seconds elapsed =
                        std::chrono::duration_cast<std::chrono::seconds>(t_now - explodableCompo->getTStart());
                    if (explodableCompo->getSeconds() <= elapsed) {
                        explodableCompo->setExploded(true);
                        entities.erase(entities.begin() + count);
                    }
                }
            }
        }
        count++;
    }
}

indie::ecs::system::SystemType indie::ecs::system::Explodable::getSystemType() const
{
    return (indie::ecs::system::SystemType::EXPLODABLESYSTEM);
}