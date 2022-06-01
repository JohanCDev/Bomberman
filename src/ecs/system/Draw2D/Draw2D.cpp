/*
** EPITECH PROJECT, 2022
** Draw2D
** File description:
** Draw2D
*/

#include "Draw2D.hpp"

void indie::ecs::system::Draw2DSystem::drawText(auto drawableCompo, auto transformCompo)
{
    indie::raylib::Draw text(
        transformCompo->getX(), transformCompo->getY(), drawableCompo->getFontSize(), drawableCompo->getColor());
    text.drawText(drawableCompo->getText());
}

void indie::ecs::system::Draw2DSystem::drawRectangle(auto drawableCompo, auto transformCompo)
{
    indie::raylib::Rectangle rect(
        transformCompo->getX(), transformCompo->getY(), drawableCompo->getWidth(), drawableCompo->getHeight());
    rect.draw(drawableCompo->getColor());
}

indie::ecs::system::SystemType indie::ecs::system::Draw2DSystem::getSystemType() const
{
    return (indie::ecs::system::SystemType::DRAWABLE2DSYSTEM);
}

void indie::ecs::system::Draw2DSystem::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(indie::ecs::component::compoType::ALIVE)
            && entity->getComponent<indie::ecs::component::Alive>(indie::ecs::component::compoType::ALIVE)->getAlive()
                == false) {
            continue;
        }
        if (entity->hasCompoType(indie::ecs::component::compoType::DRAWABLE2D)) {
            auto drawableCompo =
                entity->getComponent<indie::ecs::component::Drawable2D>(indie::ecs::component::compoType::DRAWABLE2D);
            auto transformCompo =
                entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
            if (drawableCompo != nullptr && transformCompo != nullptr) {
                switch (drawableCompo->getDrawType()) {
                    case indie::ecs::component::drawableType::CIRCLE:
                        indie::raylib::Circle::draw(transformCompo->getX(), transformCompo->getY(),
                            drawableCompo->getRadius(), drawableCompo->getColor());
                    case indie::ecs::component::drawableType::TEXT: drawText(drawableCompo, transformCompo);
                    case indie::ecs::component::drawableType::RECTANGLE: drawRectangle(drawableCompo, transformCompo);
                    default: continue;
                }
            }
        }
    }
}