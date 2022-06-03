/*
** EPITECH PROJECT, 2022
** Collide
** File description:
** Collide
*/

#include "Collide.hpp"

indie::ecs::system::Collide::Collide()
{
}

indie::ecs::system::Collide::~Collide()
{
}

indie::ecs::system::SystemType indie::ecs::system::Collide::getSystemType() const
{
    return (indie::ecs::system::SystemType::COLLIDESYSTEM);
}

void indie::ecs::system::Collide::checkSphereCollision(auto collide, auto transform, auto drawable,
    indie::ecs::component::Transform *otherEntityTransform, indie::ecs::component::Collide *otherEntityCollide,
    indie::ecs::component::Drawable3D *otherEntityDrawable)
{
    Vector3 min = {transform->getX() - drawable->getWidth() / static_cast<float>(2.0),
        transform->getY() - drawable->getHeight() / static_cast<float>(2.0),
        -(drawable->getLength() / static_cast<float>(2.0))};
    Vector3 max = {transform->getX() + drawable->getWidth() / static_cast<float>(2.0),
        transform->getY() + drawable->getHeight() / static_cast<float>(2.0),
        drawable->getLength() / static_cast<float>(2.0)};
    indie::raylib::BoundingBox box1(min, max);
    Vector3 pos = {otherEntityTransform->getX(), otherEntityTransform->getY(), 0.0};
    if (indie::raylib::BoundingBox::checkCollisionBoxSphere(box1.getBoundingBox(), pos, otherEntityDrawable->getRadius()) == true) {
        collide->setCollide(true);
        otherEntityCollide->setCollide(true);
    }
}

void indie::ecs::system::Collide::checkCubeCollision(auto drawable, auto collide,
    indie::ecs::component::Transform *transform, auto otherEntityCollide, auto otherEntityDrawable,
    indie::ecs::component::Transform *otherTransform)
{
    Vector3 min = {transform->getX() - drawable->getWidth() / static_cast<float>(2.0),
        transform->getY() - drawable->getHeight() / static_cast<float>(2.0),
        -(drawable->getLength() / static_cast<float>(2.0))};
    Vector3 max = {transform->getX() + drawable->getWidth() / static_cast<float>(2.0),
        transform->getY() + drawable->getHeight() / static_cast<float>(2.0),
        drawable->getLength() / static_cast<float>(2.0)};
    indie::raylib::BoundingBox box1(min, max);
    Vector3 min2 = {otherTransform->getX() - otherEntityDrawable->getWidth() / static_cast<float>(2.0),
        otherTransform->getY() - otherEntityDrawable->getHeight() / static_cast<float>(2.0),
        -(otherEntityDrawable->getLength() / static_cast<float>(2.0))};
    Vector3 max2 = {otherTransform->getX() + otherEntityDrawable->getWidth() / static_cast<float>(2.0),
        otherTransform->getY() + otherEntityDrawable->getHeight() / static_cast<float>(2.0),
        otherEntityDrawable->getLength() / static_cast<float>(2.0)};
    indie::raylib::BoundingBox box2(min2, max2);
    if (indie::raylib::BoundingBox::checkCollisionBoxes(box1.getBoundingBox(), box2.getBoundingBox()) == true) {
        collide->setCollide(true);
    }
}

void indie::ecs::system::Collide::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::COLLIDE)) {
            indie::ecs::component::Collide *collide =
                entity->getComponent<ecs::component::Collide>(ecs::component::compoType::COLLIDE);
            for (auto &otherEntity : entities) {
                if (otherEntity != entity && otherEntity->hasCompoType(indie::ecs::component::compoType::DRAWABLE3D)) {
                    auto otherEntityCollide =
                        otherEntity->getComponent<ecs::component::Collide>(ecs::component::compoType::COLLIDE);
                    auto otherEntityDrawable =
                        otherEntity->getComponent<ecs::component::Drawable3D>(ecs::component::compoType::DRAWABLE3D);
                    if (otherEntityDrawable->getDrawType() == indie::ecs::component::drawableType::CUBE) {
                        checkCubeCollision(
                            entity->getComponent<ecs::component::Drawable3D>(ecs::component::compoType::DRAWABLE3D),
                            collide,
                            entity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM),
                            otherEntityCollide, otherEntityDrawable,
                            otherEntity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM));
                    }
                    if (otherEntityDrawable->getDrawType() == indie::ecs::component::drawableType::SPHERE) {
                        checkSphereCollision(collide,
                            entity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM),
                            entity->getComponent<ecs::component::Drawable3D>(ecs::component::compoType::DRAWABLE3D),
                            otherEntity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM),
                            otherEntity->getComponent<ecs::component::Collide>(ecs::component::compoType::COLLIDE),
                            otherEntityDrawable);
                    }
                }
            }
        }
    }
}