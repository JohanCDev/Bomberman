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
    Vector3 scale = {1.0, 1.0, 1.0};
    vec3f vec;

    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::MODEL)) {
            indie::ecs::component::Object *objectCompo =
                entity->getComponent<ecs::component::Object>(ecs::component::compoType::MODEL);
            indie::ecs::component::Transform *transformCompo =
                entity->getComponent<ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            pos.x = transformCompo->getX();
            pos.z = transformCompo->getY();
            vec = objectCompo->getScale();
            scale.x = vec.x;
            scale.y = vec.y;
            scale.z = vec.z;
            indie::raylib::Model::drawEx(objectCompo->getModel(), pos, {1.0f, 0.0f, 0.0f}, -30.0f, scale, WHITE);
        }
    }
}

indie::ecs::system::SystemType indie::ecs::system::ObjectSystem::getSystemType() const
{
    return (indie::ecs::system::SystemType::OBJECTSYSTEM);
}