/*
** EPITECH PROJECT, 2022
** Draw3D
** File description:
** Draw3D
*/

#include "Draw3D.hpp"

indie::ecs::system::SystemType indie::ecs::system::Draw3DSystem::getSystemType() const
{
    return (indie::ecs::system::SystemType::DRAWABLE3DSYSTEM);
}

void indie::ecs::system::Draw3DSystem::drawSphere(auto drawableCompo, auto transformCompo)
{
    Vector3 pos = {0.0, 0.0, 0.0};

    pos = {transformCompo->getX(), transformCompo->getY(), 0.0};
    indie::raylib::Sphere sphere(pos, drawableCompo->getRadius(), drawableCompo->getColor());
    sphere.draw();
}

void indie::ecs::system::Draw3DSystem::drawCube(auto drawableCompo, auto transformCompo)
{
    Vector3 pos = {0.0, 0.0, 0.0};

    pos = {transformCompo->getX(), transformCompo->getY(), 0.0};
    indie::raylib::Cube cube(
        pos.x, pos.y, pos.z, drawableCompo->getWidth(), drawableCompo->getHeight(), drawableCompo->getLength());
    cube.draw();
}

void indie::ecs::system::Draw3DSystem::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::DRAWABLE3D)) {
            auto drawableCompo =
                entity->getComponent<indie::ecs::component::Drawable3D>(indie::ecs::component::compoType::DRAWABLE3D);
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
            switch (drawableCompo->getDrawType()) {
                case indie::ecs::component::drawableType::SPHERE: drawSphere(drawableCompo, transformCompo);
                case indie::ecs::component::drawableType::CUBE: drawCube(drawableCompo, transformCompo);
                default: continue;
            }
        }
    }
}