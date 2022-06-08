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

void indie::ecs::system::Explodable::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::EXPLODABLE) == true) {
            auto explodableCompo =
                entity->getComponent<ecs::component::Explodable>(ecs::component::compoType::EXPLODABLE);
            if (explodableCompo->getDropped() == true) {
                if (explodableCompo->getExploded() == true) {
                    explodableCompo->setExploded(false);
                    explodableCompo->setDropped(false);
                    // destroy entity with destroyable component in range
                } else {
                    auto t_now = std::chrono::system_clock::now();
                    std::chrono::seconds elapsed =
                        std::chrono::duration_cast<std::chrono::seconds>(t_now - explodableCompo->getTStart());
                    if (explodableCompo->getSeconds() <= elapsed) {
                        explodableCompo->setExploded(true);
                    }
                }
            }
        }
    }
}

indie::ecs::system::SystemType indie::ecs::system::Explodable::getSystemType() const
{
    return (indie::ecs::system::SystemType::EXPLODABLESYSTEM);
}