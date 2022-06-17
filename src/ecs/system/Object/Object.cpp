/**
 * @file Object.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Object.hpp"

void indie::ecs::system::ObjectSystem::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    Vector3 pos = {0.0, 0.0, 0.0};

    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::MODEL)) {
            indie::ecs::component::Object *objectCompo =
                entity->getComponent<ecs::component::Object>(ecs::component::compoType::MODEL);
            indie::ecs::component::Transform *transformCompo =
                entity->getComponent<ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            pos.x = transformCompo->getX();
            pos.z = transformCompo->getY();
            indie::raylib::Model::drawEx(objectCompo->getModel(), pos, {0.0f, 1.0f, 0.0f},
                static_cast<float>(indie::ecs::component::Object::NORTH), {1.0f, 1.0f, 1.0f}, WHITE);
        }
    }
}

indie::ecs::system::SystemType indie::ecs::system::ObjectSystem::getSystemType() const
{
    return (indie::ecs::system::SystemType::OBJECTSYSTEM);
}