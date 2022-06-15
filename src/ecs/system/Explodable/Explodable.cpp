/**
 * @file Explodable.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Explodable system source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Explodable.hpp"

indie::ecs::system::Explodable::Explodable()
{
}

indie::ecs::system::Explodable::~Explodable()
{
}

void indie::ecs::system::Explodable::destroyBoxes(std::vector<int> &compoToRemove,
    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities,
    indie::ecs::component::Explodable *explodableCompo, indie::ecs::component::Transform *bombTransformCompo)
{
    int count = 0;

    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::DESTROYABLE) == true) {
            auto drawableCompo =
                entity->getComponent<indie::ecs::component::Drawable3D>(indie::ecs::component::compoType::DRAWABLE3D);
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
            if ((transformCompo->getX() <= bombTransformCompo->getX()
                    && transformCompo->getX() >= bombTransformCompo->getX() - explodableCompo->getRange())
                && (transformCompo->getY() >= bombTransformCompo->getY() - 0.25
                    && transformCompo->getY() <= bombTransformCompo->getY() + 0.25)) {
                compoToRemove.push_back(count);
            }
            if ((transformCompo->getX() >= bombTransformCompo->getX()
                    && transformCompo->getX() <= bombTransformCompo->getX() + explodableCompo->getRange())
                && (transformCompo->getY() >= bombTransformCompo->getY() - 0.25
                    && transformCompo->getY() <= bombTransformCompo->getY() + 0.25)) {
                compoToRemove.push_back(count);
            }
            if ((transformCompo->getY() >= bombTransformCompo->getY()
                    && transformCompo->getY() <= bombTransformCompo->getY() + explodableCompo->getRange())
                && (transformCompo->getX() >= bombTransformCompo->getX() - 0.25
                    && transformCompo->getX() <= bombTransformCompo->getX() + 0.25)) {
                compoToRemove.push_back(count);
            }
            if ((transformCompo->getY() <= bombTransformCompo->getY()
                    && transformCompo->getY() >= bombTransformCompo->getY() - explodableCompo->getRange())
                && (transformCompo->getX() >= bombTransformCompo->getX() - 0.25
                    && transformCompo->getX() <= bombTransformCompo->getX() + 0.25)) {
                compoToRemove.push_back(count);
            }
        }
        count++;
    }
}

void indie::ecs::system::Explodable::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    int count = 0;
    std::vector<int> compoToRemove;

    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::EXPLODABLE) == true) {
            auto explodableCompo =
                entity->getComponent<ecs::component::Explodable>(ecs::component::compoType::EXPLODABLE);
            if (explodableCompo->getDropped() == true) {
                if (explodableCompo->getExplode() == true) {
                    explodableCompo->setExploded(true);
                    destroyBoxes(compoToRemove, entities, explodableCompo,
                        entity->getComponent<ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM));
                } else {
                    auto t_now = std::chrono::system_clock::now();
                    std::chrono::seconds elapsed =
                        std::chrono::duration_cast<std::chrono::seconds>(t_now - explodableCompo->getTStart());
                    if (explodableCompo->getSeconds() <= elapsed) {
                        explodableCompo->setExplode(true);
                    }
                }
            }
        }
        count++;
    }
    size_t i = 0;
    for (auto &index : compoToRemove) {
        auto type = entities.at(index - i)->getEntityType();
        if (type == indie::ecs::entity::PLAYER_1 || type == indie::ecs::entity::PLAYER_2
            || type == indie::ecs::entity::PLAYER_3 || type == indie::ecs::entity::PLAYER_4) {
            entities.at(index - i)
                ->getComponent<indie::ecs::component::Alive>(indie::ecs::component::ALIVE)
                ->setAlive(false);
        } else {
            entities.erase(entities.begin() + index - i);
            i++;
        }
    }
}

indie::ecs::system::SystemType indie::ecs::system::Explodable::getSystemType() const
{
    return (indie::ecs::system::SystemType::EXPLODABLESYSTEM);
}