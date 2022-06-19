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
    Vector3 rotationAxis = {0.0f, 0.0f, 0.0f};
    vec3f scaleVec;
    vec3f rotationVec;

    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::MODEL)
            || entity->hasCompoType(ecs::component::compoType::ANIMATED)) {
            ecs::component::compoType type = entity->hasCompoType(ecs::component::compoType::MODEL)
                ? ecs::component::compoType::MODEL
                : ecs::component::compoType::ANIMATED;
            if (entity->hasCompoType(indie::ecs::component::ALIVE)
                && entity->getComponent<indie::ecs::component::Alive>(indie::ecs::component::ALIVE)->getAlive()
                    == false) {
                continue;
            }
            indie::ecs::component::Object *objectCompo = entity->getComponent<ecs::component::Object>(type);
            indie::ecs::component::Transform *transformCompo =
                entity->getComponent<ecs::component::Transform>(indie::ecs::component::TRANSFORM);
            pos.x = transformCompo->getX();
            pos.z = transformCompo->getY();
            scaleVec = objectCompo->getScale();
            scale.x = scaleVec.x;
            scale.y = scaleVec.y;
            scale.z = scaleVec.z;
            rotationVec = objectCompo->getRotationVec();
            rotationAxis.x = rotationVec.x;
            rotationAxis.y = rotationVec.y;
            rotationAxis.z = rotationVec.z;
            indie::raylib::Model::drawEx(
                objectCompo->getModel(), pos, rotationAxis, objectCompo->getOrientation(), scale, WHITE);
        }
    }
}

indie::ecs::system::SystemType indie::ecs::system::ObjectSystem::getSystemType() const
{
    return (indie::ecs::system::SystemType::OBJECTSYSTEM);
}