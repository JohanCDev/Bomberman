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

void indie::ecs::system::Explodable::destroyBoxes(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities,
    indie::ecs::component::Explodable *explodableCompo, indie::ecs::component::Transform *bombTransformCompo)
{
    Vector3 min = {0, 0, 0};
    Vector3 max = {0, 0, 0};
    Vector3 min2 = {0, 0, 0};
    Vector3 max2 = {0, 0, 0};
    int count = 0;
    std::vector<int> compoToRemove;

    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::DESTROYABLE)
            && entity->hasCompoType(indie::ecs::component::compoType::ALIVE) == true) {
            auto drawableCompo =
                entity->getComponent<indie::ecs::component::Drawable3D>(indie::ecs::component::compoType::DRAWABLE3D);
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
            min.x = transformCompo->getX() - drawableCompo->getWidth() / static_cast<float>(2.0);
            min.y = transformCompo->getY() - drawableCompo->getHeight() / static_cast<float>(2.0);
            min.z = -(drawableCompo->getLength() / static_cast<float>(2.0));
            max.x = transformCompo->getX() + drawableCompo->getWidth() / static_cast<float>(2.0);
            max.y = transformCompo->getY() + drawableCompo->getHeight() / static_cast<float>(2.0);
            max.z = (drawableCompo->getLength() / static_cast<float>(2.0));
            indie::raylib::BoundingBox box1(min, max);
            min2.x = bombTransformCompo->getX() - explodableCompo->getRange() / static_cast<float>(2.0);
            min2.y = bombTransformCompo->getY() - explodableCompo->getRange() / static_cast<float>(2.0);
            min2.z = static_cast<float>(-0.5) / static_cast<float>(2.0);
            max2.x = bombTransformCompo->getX() - explodableCompo->getRange() / static_cast<float>(2.0);
            max2.y = bombTransformCompo->getY() - explodableCompo->getRange() / static_cast<float>(2.0);
            max2.z = static_cast<float>(0.5) / static_cast<float>(2.0);
            indie::raylib::BoundingBox box2(min2, max2);
            if (indie::raylib::BoundingBox::checkCollisionBoxes(box1.getBoundingBox(), box2.getBoundingBox()) == true) {
                compoToRemove.push_back(count);
            }
        }
        count++;
    }
    for (auto &index : compoToRemove) {
        entities.erase(entities.begin() + index);
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
                        compoToRemove.push_back(count);
                    }
                }
            }
        }
        count++;
    }
    for (auto &index : compoToRemove) {
        entities.erase(entities.begin() + index);
    }
}

indie::ecs::system::SystemType indie::ecs::system::Explodable::getSystemType() const
{
    return (indie::ecs::system::SystemType::EXPLODABLESYSTEM);
}