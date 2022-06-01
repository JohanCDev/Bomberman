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
                    case ecs::drawableType::TEXT:
                        indie::raylib::Draw::drawText(drawableCompo->getText(), transformCompo->getX(),
                            transformCompo->getY(), drawableCompo->getFontSize(), drawableCompo->getColor());
                    case ecs::drawableType::RECTANGLE:
                        indie::Raylib::drawRectangle(transformCompo->getX(), transformCompo->getY(),
                            drawableCompo->getWidth(), drawableCompo->getHeight(), drawableCompo->getColor());
                    case ecs::drawableType::UNKNOWN: continue;
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

void indie::ecs::Draw3DSystem::update(std::vector<std::unique_ptr<ecs::Entity>> &entities)
{
    Vector3 pos = {0.0, 0.0, 0.0};

    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::compoType::DRAWABLE3D)) {
            auto drawableCompo = entity->getComponent<indie::ecs::Drawable3D>(indie::ecs::compoType::DRAWABLE3D);
            auto transformCompo = entity->getComponent<indie::ecs::Transform>(indie::ecs::compoType::TRANSFORM);
            switch (drawableCompo->getDrawType()) {
                case ecs::drawableType::SPHERE:
                    pos = {transformCompo->getX(), transformCompo->getY(), 0.0};
                    indie::Raylib::drawSphere(pos, drawableCompo->getRadius(), drawableCompo->getColor());
                case ecs::drawableType::CUBE:
                    pos = {transformCompo->getX(), transformCompo->getY(), 0.0};
                    indie::Raylib::drawRectangle3D(
                        pos, drawableCompo->getWidth(), drawableCompo->getHeight(), 2.0, drawableCompo->getColor());
            }
        }
    }
}