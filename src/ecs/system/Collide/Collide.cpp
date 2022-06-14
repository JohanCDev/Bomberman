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

void indie::ecs::system::Collide::checkSphereCollision(std::unique_ptr<indie::ecs::entity::Entity> &entity,
    std::unique_ptr<indie::ecs::entity::Entity> &otherEntity, std::vector<int> &compoToRemove, int &count)
{
    auto transform = entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
    auto drawable = entity->getComponent<indie::ecs::component::Drawable3D>(indie::ecs::component::DRAWABLE3D);
    auto collide = entity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::COLLIDE);
    auto otherEntityTransform =
        otherEntity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
    auto otherEntityDrawable =
        otherEntity->getComponent<indie::ecs::component::Drawable3D>(indie::ecs::component::DRAWABLE3D);
    auto otherEntityCollide = entity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::COLLIDE);

    Vector3 min = {transform->getX() - drawable->getWidth() / static_cast<float>(2.0),
        transform->getY() - drawable->getHeight() / static_cast<float>(2.0),
        -(drawable->getLength() / static_cast<float>(2.0))};
    Vector3 max = {transform->getX() + drawable->getWidth() / static_cast<float>(2.0),
        transform->getY() + drawable->getHeight() / static_cast<float>(2.0),
        drawable->getLength() / static_cast<float>(2.0)};
    indie::raylib::BoundingBox box1(min, max);
    Vector3 pos = {otherEntityTransform->getX(), otherEntityTransform->getY(), 0.0};
    if (indie::raylib::BoundingBox::checkCollisionBoxSphere(
            box1.getBoundingBox(), pos, otherEntityDrawable->getRadius())
        == true) {
        if (entity->hasCompoType(indie::ecs::component::COLLECTABLE) == true) {
            otherEntity->getComponent<indie::ecs::component::Inventory>(indie::ecs::component::INVENTORY)
                ->setBonus(entity->getComponent<indie::ecs::component::Collectable>(indie::ecs::component::COLLECTABLE)
                               ->getBonusType());
            compoToRemove.push_back(count);
        } else {
            collide->setCollide(true);
            otherEntityCollide->setCollide(true);
            if (otherEntityTransform->getSpeedX() > 0.0)
                otherEntityTransform->setX(otherEntityTransform->getX() - otherEntityTransform->getSpeedX());
            if (otherEntityTransform->getSpeedX() < 0.0)
                otherEntityTransform->setX(otherEntityTransform->getX() - otherEntityTransform->getSpeedX());
            if (otherEntityTransform->getSpeedY() > 0.0)
                otherEntityTransform->setY(otherEntityTransform->getY() - otherEntityTransform->getSpeedY());
            if (otherEntityTransform->getSpeedY() < 0.0)
                otherEntityTransform->setY(otherEntityTransform->getY() - otherEntityTransform->getSpeedY());
        }
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
        otherEntityCollide->setCollide(true);
        if (otherTransform->getSpeedX() > 0.0)
            otherTransform->setX(otherTransform->getX() - 0.02);
        if (otherTransform->getSpeedX() < 0.0)
            otherTransform->setX(otherTransform->getX() + 0.02);
        if (otherTransform->getSpeedY() > 0.0)
            otherTransform->setY(otherTransform->getY() - 0.02);
        if (otherTransform->getSpeedY() < 0.0)
            otherTransform->setY(otherTransform->getY() + 0.02);
    }
}

void indie::ecs::system::Collide::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    int count = 0;
    std::vector<int> compoToRemove;

    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::COLLIDE) == true) {
            indie::ecs::component::Collide *collide =
                entity->getComponent<ecs::component::Collide>(ecs::component::compoType::COLLIDE);
            auto drawableCompo =
                entity->getComponent<ecs::component::Drawable3D>(ecs::component::compoType::DRAWABLE3D);
            auto transformCompo = entity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            for (auto &otherEntity : entities) {
                if (otherEntity != entity && otherEntity->hasCompoType(indie::ecs::component::compoType::DRAWABLE3D)
                    && otherEntity->hasCompoType(indie::ecs::component::compoType::COLLIDE)) {
                    auto otherEntityCollide =
                        otherEntity->getComponent<ecs::component::Collide>(ecs::component::compoType::COLLIDE);
                    auto otherEntityDrawable =
                        otherEntity->getComponent<ecs::component::Drawable3D>(ecs::component::compoType::DRAWABLE3D);
                    if (otherEntityDrawable->getDrawType() == indie::ecs::component::drawableType::CUBE
                        && drawableCompo->getDrawType() == indie::ecs::component::drawableType::CUBE) {
                        checkCubeCollision(drawableCompo, collide, transformCompo, otherEntityCollide,
                            otherEntityDrawable,
                            otherEntity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM));
                    }
                    if (otherEntityDrawable->getDrawType() == indie::ecs::component::drawableType::SPHERE
                        && drawableCompo->getDrawType() == indie::ecs::component::drawableType::CUBE) {
                        checkSphereCollision(entity, otherEntity, compoToRemove, count);
                    }
                    if (drawableCompo->getDrawType() == indie::ecs::component::drawableType::SPHERE
                        && otherEntityDrawable->getDrawType() == indie::ecs::component::drawableType::CUBE) {
                        checkSphereCollision(entity, otherEntity, compoToRemove, count);
                    }
                }
            }
        }
        count++;
    }

    size_t i = 0;
    for (auto &index : compoToRemove) {
        entities.erase(entities.begin() + index - i);
        i++;
    }
}