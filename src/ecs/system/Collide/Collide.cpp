/**
 * @file Collide.cpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Collide system source file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
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

Vector3 Vector3Add(Vector3 v1, Vector3 v2)
{
    Vector3 result = {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};

    return result;
}

bool indie::ecs::system::Collide::checkCubeCollision(std::unique_ptr<indie::ecs::entity::Entity> &entity,
    std::unique_ptr<indie::ecs::entity::Entity> &otherEntity, indie::ecs::component::Collide *collide,
    indie::ecs::component::Collide *otherEntityCollide)
{
    // auto collide = entity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::COLLIDE);
    auto transform = entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);
    // auto otherEntityCollide =
    // otherEntity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::COLLIDE);
    auto otherTransform = otherEntity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM);

    /*if (entity->hasCompoType(indie::ecs::component::ANIMATED)
        && otherEntity->hasCompoType(indie::ecs::component::ANIMATED)) {
        if (indie::raylib::BoundingBox::checkCollisionBoxes(
                indie::raylib::BoundingBox::getModelBox(
                    entity->getComponent<indie::ecs::component::Object>(indie::ecs::component::MODEL)->getModel()),
                indie::raylib::BoundingBox::getModelBox(
                    otherEntity->getComponent<indie::ecs::component::Object>(indie::ecs::component::MODEL)->getModel()))
            == true) {
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
    }*/
    if (otherEntity->hasCompoType(indie::ecs::component::ANIMATED)
        && entity->hasCompoType(indie::ecs::component::DRAWABLE3D)) {
        auto drawable = entity->getComponent<indie::ecs::component::Drawable3D>(indie::ecs::component::DRAWABLE3D);
        Vector3 min = {transform->getX() - drawable->getWidth() / static_cast<float>(2.0),
            transform->getY() - drawable->getHeight() / static_cast<float>(2.0),
            -(drawable->getLength() / static_cast<float>(2.0))};
        Vector3 max = {transform->getX() + drawable->getWidth() / static_cast<float>(2.0),
            transform->getY() + drawable->getHeight() / static_cast<float>(2.0),
            drawable->getLength() / static_cast<float>(2.0)};
        indie::raylib::BoundingBox box1(min, max);
        BoundingBox box2 = GetModelBoundingBox(
            otherEntity->getComponent<indie::ecs::component::Object>(indie::ecs::component::ANIMATED)->getModel());
        Vector3 min2 = {otherTransform->getX(), otherTransform->getY(), 0.0f};
        Vector3 max2 = {otherTransform->getX(), otherTransform->getY() - 2.0f, 0.0f};
        if (otherEntity->getComponent<indie::ecs::component::Object>(indie::ecs::component::ANIMATED)->getOrientation()
            == static_cast<float>(indie::ecs::component::Object::NORTH)) {
            min2.y = min2.y - 0.5f;
        }
        if (otherEntity->getComponent<indie::ecs::component::Object>(indie::ecs::component::ANIMATED)->getOrientation()
            == static_cast<float>(indie::ecs::component::Object::SOUTH)) {
            max2.y = max2.y + 0.5f;
        }
        box2.min = Vector3Add(box2.min, min2);
        box2.max = Vector3Add(box2.max, max2);
        BoundingBox box3(min2, max2);
        if (indie::raylib::BoundingBox::checkCollisionBoxes(box2, box1.getBoundingBox()) == true) {
            std::cout << "box 1 " << box1.getBoundingBox().min.x << " " << box1.getBoundingBox().min.y << " "
                      << box1.getBoundingBox().min.z << "  " << box1.getBoundingBox().max.x << " "
                      << box1.getBoundingBox().max.y << " " << box1.getBoundingBox().max.z << std::endl;
            std::cout << "box 2 " << box2.min.x << " " << box2.min.y << " " << box2.min.z << "  " << box2.max.x << " "
                      << box2.max.y << " " << box2.max.z << std::endl;
            collide->setCollide(true);
            otherEntityCollide->setCollide(true);
            if (otherTransform->getSpeedX() > 0.0)
                otherTransform->setX(otherTransform->getX() - otherTransform->getSpeedX());
            if (otherTransform->getSpeedX() < 0.0)
                otherTransform->setX(otherTransform->getX() - otherTransform->getSpeedX());
            if (otherTransform->getSpeedY() > 0.0)
                otherTransform->setY(otherTransform->getY() - otherTransform->getSpeedY());
            if (otherTransform->getSpeedY() < 0.0)
                otherTransform->setY(otherTransform->getY() - otherTransform->getSpeedY());
            return (true);
        }
    }
    /*if (entity->hasCompoType(indie::ecs::component::MODEL)
        && otherEntity->hasCompoType(indie::ecs::component::DRAWABLE3D)) {
        auto drawable = otherEntity->getComponent<indie::ecs::component::Drawable3D>(indie::ecs::component::DRAWABLE3D);
        Vector3 min = {transform->getX() - drawable->getWidth() / static_cast<float>(2.0),
            transform->getY() - drawable->getHeight() / static_cast<float>(2.0),
            -(drawable->getLength() / static_cast<float>(2.0))};
        Vector3 max = {transform->getX() + drawable->getWidth() / static_cast<float>(2.0),
            transform->getY() + drawable->getHeight() / static_cast<float>(2.0),
            drawable->getLength() / static_cast<float>(2.0)};
        indie::raylib::BoundingBox box1(min, max);
        if (indie::raylib::BoundingBox::checkCollisionBoxes(
                indie::raylib::BoundingBox::getModelBox(
                    entity->getComponent<indie::ecs::component::Object>(indie::ecs::component::MODEL)->getModel()),
                box1.getBoundingBox())
            == true) {
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
    }*/
    /*Vector3 min = {transform->getX() - drawable->getWidth() / static_cast<float>(2.0),
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
    */
    /*if (indie::raylib::BoundingBox::checkCollisionBoxes(box1.getBoundingBox(), box2.getBoundingBox()) == true) {
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
    }*/
    return (false);
}

void indie::ecs::system::Collide::update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities)
{
    int count = 0;
    std::vector<int> compoToRemove;

    for (auto &entity : entities) {
        if (entity->hasCompoType(ecs::component::compoType::COLLIDE) == true) {
            indie::ecs::component::Collide *collide =
                entity->getComponent<ecs::component::Collide>(ecs::component::compoType::COLLIDE);
            // auto drawableCompo =
            //     entity->getComponent<ecs::component::Drawable3D>(ecs::component::compoType::DRAWABLE3D);
            auto transformCompo = entity->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            for (auto &otherEntity : entities) {
                if (otherEntity != entity && otherEntity->hasCompoType(indie::ecs::component::compoType::COLLIDE)) {
                    // auto otherEntityCollide =
                    //     otherEntity->getComponent<ecs::component::Collide>(ecs::component::compoType::COLLIDE);
                    // auto otherEntityDrawable =
                    //     otherEntity->getComponent<ecs::component::Drawable3D>(ecs::component::compoType::DRAWABLE3D);
                    //  if (otherEntityDrawable->getDrawType() == indie::ecs::component::drawableType::CUBE
                    //    && drawableCompo->getDrawType() == indie::ecs::component::drawableType::CUBE) {
                    if (checkCubeCollision(entity, otherEntity,
                            entity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::COLLIDE),
                            otherEntity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::COLLIDE))
                        == true) {}
                    //}
                    /*if (otherEntityDrawable->getDrawType() == indie::ecs::component::drawableType::SPHERE
                        && drawableCompo->getDrawType() == indie::ecs::component::drawableType::CUBE) {
                        checkSphereCollision(entity, otherEntity, compoToRemove, count);
                    }
                    if (drawableCompo->getDrawType() == indie::ecs::component::drawableType::SPHERE
                        && otherEntityDrawable->getDrawType() == indie::ecs::component::drawableType::CUBE) {
                        checkSphereCollision(entity, otherEntity, compoToRemove, count);
                    }*/
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
