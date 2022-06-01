/*
** EPITECH PROJECT, 2022
** IndieStudio_Commun
** File description:
** System
*/

#include "System.hpp"

void indie::ecs::MovementSystem::update(std::vector<std::unique_ptr<ecs::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->getAlive() == true && entity->hasCompoType(ecs::compoType::TRANSFORM)) {
            indie::ecs::Transform *transformCompo = entity->getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
            transformCompo->setX(transformCompo->getX() + transformCompo->getSpeedX());
            transformCompo->setY(transformCompo->getY() + transformCompo->getSpeedY());
        }
    }
}

indie::ecs::Draw2DSystem::Draw2DSystem()
{
}

indie::ecs::Draw2DSystem::~Draw2DSystem()
{
}

void indie::ecs::Draw2DSystem::drawText(auto drawableCompo, auto transformCompo)
{
    indie::raylib::Draw text(
        transformCompo->getX(), transformCompo->getY(), drawableCompo->getFontSize(), drawableCompo->getColor());
    text.drawText(drawableCompo->getText());
}

void indie::ecs::Draw2DSystem::drawRectangle(auto drawableCompo, auto transformCompo)
{
    indie::raylib::Rectangle rect(
        transformCompo->getX(), transformCompo->getY(), drawableCompo->getWidth(), drawableCompo->getHeight());
    rect.draw(drawableCompo->getColor());
}

indie::ecs::SystemType indie::ecs::MovementSystem::getSystemType() const
{
    return (indie::ecs::SystemType::MOVEMENTSYSTEM);
}

indie::ecs::SystemType indie::ecs::Draw2DSystem::getSystemType() const
{
    return (indie::ecs::SystemType::DRAWABLE2DSYSTEM);
}

indie::ecs::SystemType indie::ecs::Draw3DSystem::getSystemType() const
{
    return (indie::ecs::SystemType::DRAWABLE3DSYSTEM);
}

void indie::ecs::Draw2DSystem::update(std::vector<std::unique_ptr<ecs::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::compoType::DRAWABLE2D)) {
            auto drawableCompo = entity->getComponent<indie::ecs::Drawable2D>(indie::ecs::compoType::DRAWABLE2D);
            auto transformCompo = entity->getComponent<indie::ecs::Transform>(indie::ecs::compoType::TRANSFORM);
            if (drawableCompo != nullptr && transformCompo != nullptr) {
                switch (drawableCompo->getDrawType()) {
                    case ecs::drawableType::CIRCLE:
                        indie::raylib::Circle::draw(transformCompo->getX(), transformCompo->getY(),
                            drawableCompo->getRadius(), drawableCompo->getColor());
                    case ecs::drawableType::TEXT: drawText(drawableCompo, transformCompo);
                    case ecs::drawableType::RECTANGLE: drawRectangle(drawableCompo, transformCompo);
                    default: continue;
                }
            }
        }
    }
}

indie::ecs::Draw3DSystem::Draw3DSystem()
{
}

indie::ecs::Draw3DSystem::~Draw3DSystem()
{
}

void indie::ecs::Draw3DSystem::drawSphere(auto drawableCompo, auto transformCompo)
{
    Vector3 pos = {0.0, 0.0, 0.0};

    pos = {transformCompo->getX(), transformCompo->getY(), 0.0};
    indie::raylib::Sphere sphere(pos, drawableCompo->getRadius(), drawableCompo->getColor());
    sphere.draw();
}

void indie::ecs::Draw3DSystem::drawCube(auto drawableCompo, auto transformCompo)
{
    Vector3 pos = {0.0, 0.0, 0.0};

    pos = {transformCompo->getX(), transformCompo->getY(), 0.0};
    indie::raylib::Cube cube(
        pos.x, pos.y, pos.z, drawableCompo->getWidth(), drawableCompo->getHeight(), drawableCompo->getLength());
    cube.draw();
}

void indie::ecs::Draw3DSystem::update(std::vector<std::unique_ptr<ecs::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::compoType::DRAWABLE3D)) {
            auto drawableCompo = entity->getComponent<indie::ecs::Drawable3D>(indie::ecs::compoType::DRAWABLE3D);
            auto transformCompo = entity->getComponent<indie::ecs::Transform>(indie::ecs::compoType::TRANSFORM);
            switch (drawableCompo->getDrawType()) {
                case ecs::drawableType::SPHERE: drawSphere(drawableCompo, transformCompo);
                case ecs::drawableType::CUBE: drawCube(drawableCompo, transformCompo);
                default: continue;
            }
        }
    }
}