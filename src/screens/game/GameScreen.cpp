/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** GameScreen
*/

#include "GameScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::GameScreen::GameScreen()
    : _camera({0.0, 10.0, 10.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 45.0, CAMERA_PERSPECTIVE)
{
}

void indie::menu::GameScreen::draw()
{
    indie::raylib::Camera3D camera = getCamera();
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

    for (auto &system : this->_systems) {
        if (system->getSystemType() == indie::ecs::system::SystemType::DRAWABLE3DSYSTEM) {
            camera.beginMode();
            system->update(this->_entities);
            camera.endMode();
        } else {
            system->update(this->_entities);
        }
    }
    indie::raylib::Window::endDrawing();
}

void indie::menu::GameScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::GameScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::GameScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

indie::raylib::Camera3D indie::menu::GameScreen::getCamera() const
{
    return (this->_camera);
}

void indie::menu::GameScreen::handleEvent(indie::Event &event)
{
    indie::ecs::component::Transform *transformCompo = nullptr;

    if (event.controller[0].code == indie::Event::X_BUTTON) {
        for (auto &entity : _entities) {
            if (entity->getEntityType() == indie::ecs::entity::PLAYER1) {
                transformCompo =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
            }
        }
        if (transformCompo != nullptr) {
            std::unique_ptr<indie::ecs::entity::Entity> entity =
                std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::BOMB);
            //entity->addComponent<indie::ecs::component::Collide>();
            entity->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.25), RED);
            entity->addComponent<indie::ecs::component::Transform>(static_cast<float>(transformCompo->getX()),
                static_cast<float>(transformCompo->getY()), static_cast<float>(0.0), static_cast<float>(0.0));
            addEntity(std::move(entity));
        }
    }
}