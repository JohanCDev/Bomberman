/**
 * @file Draw3D.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Draw3D system source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Draw3D.hpp"

indie::ecs::system::SystemType indie::ecs::system::Draw3DSystem::getSystemType() const
{
    return (indie::ecs::system::SystemType::DRAWABLE3DSYSTEM);
}

void indie::ecs::system::Draw3DSystem::drawSphere(auto drawableCompo, auto transformCompo)
{
    Vector3 pos = {0.0, 0.0, 0.0};

    pos = {transformCompo->getX(), transformCompo->getZ(), transformCompo->getY()};
    indie::raylib::Sphere::draw(pos, drawableCompo->getRadius(), drawableCompo->getColor());
    indie::raylib::Sphere::drawWires(pos, drawableCompo->getRadius(), 50, 5.0, BLACK);
}

void indie::ecs::system::Draw3DSystem::drawCube(auto drawableCompo, auto transformCompo)
{
    Vector3 pos = {0.0, 0.0, 0.0};

    pos = {transformCompo->getX(), transformCompo->getZ(), transformCompo->getY()};
    Vector3 size = {drawableCompo->getWidth(), drawableCompo->getHeight(), drawableCompo->getLength()};
    if (drawableCompo->getTexturePath() == "") {
        indie::raylib::Cube::draw(pos, size, drawableCompo->getColor());
        indie::raylib::Cube::drawWires(pos, size, BLACK);
    } else {
        indie::raylib::Cube::drawTexture(drawableCompo->getTexture(), pos, drawableCompo->getWidth(),
            drawableCompo->getHeight(), drawableCompo->getLength(), drawableCompo->getColor());
    }
}

void indie::ecs::system::Draw3DSystem::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    // indie::raylib::Draw::drawGrid(21, 0.5);
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::ALIVE)
            && entity->getComponent<indie::ecs::component::Alive>(indie::ecs::component::ALIVE)->getAlive() == false) {
            continue;
        }
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