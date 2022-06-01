/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** GameScreen
*/

#include "GameScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::GameScreen::GameScreen()
    : _camera((Vector3){0.0, 10.0, 10.0}, (Vector3){0.0, 0.0, 0.0}, (Vector3){0.0, 1.0, 0.0}, 45.0, CAMERA_PERSPECTIVE)
{
}

void indie::menu::GameScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

    for (auto &system : this->_systems) {
        if (system->getSystemType() == indie::ecs::system::SystemType::DRAWABLE3DSYSTEM) {
            getCamera().beginMode();
            system->update(this->_entities);
            getCamera().endMode();
        } else {
            system->update(this->_entities);
        }
    }

    indie::raylib::Window::endDrawing();
}

void indie::menu::GameScreen::handleEvent(indie::Event &event)
{
    (void)event;
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