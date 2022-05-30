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
            ecs::Transform *transformCompo = entity->getComponent<ecs::Transform>(ecs::compoType::TRANSFORM);
            transformCompo->setX(transformCompo->getX() + transformCompo->getSpeedX());
            transformCompo->setY(transformCompo->getY() + transformCompo->getSpeedY());
        }
    }
}

indie::ecs::DrawSystem::DrawSystem()
{
}

indie::ecs::DrawSystem::~DrawSystem()
{
}

void indie::ecs::DrawSystem::update(std::vector<std::unique_ptr<ecs::Entity>> &entities)
{
    for (auto &entity : entities) {
        auto drawableCompo = entity->getComponent<indie::ecs::Drawable2D>(indie::ecs::compoType::DRAWABLE2D);
        auto transformCompo = entity->getComponent<indie::ecs::Transform>(indie::ecs::compoType::TRANSFORM);
        if (drawableCompo != nullptr && transformCompo != nullptr) {
            switch (drawableCompo->getDrawType()) {
                case ecs::drawableType::CIRCLE:
                    indie::Raylib::drawCircle(transformCompo->getX(), transformCompo->getY(),
                        drawableCompo->getRadius(), drawableCompo->getColor());
                case ecs::drawableType::TEXT:
                    indie::Raylib::drawText(drawableCompo->getText(), transformCompo->getX(), transformCompo->getY(),
                        drawableCompo->getFontSize(), drawableCompo->getColor());
                case ecs::drawableType::RECTANGLE:
                    indie::Raylib::drawRectangle(transformCompo->getX(), transformCompo->getY(),
                        drawableCompo->getWidth(), drawableCompo->getHeight(), drawableCompo->getColor());
                case ecs::drawableType::UNKNOWN: continue;
            }
        }
    }
}
