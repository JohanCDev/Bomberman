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
    this->_i = 0;
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
    this->_i++;
    std::cout << _i << std::endl;
    if (this->_i == 120)
        for (auto &entity : this->_entities) {
            if (entity->hasCompoType(indie::ecs::component::SOUND) == true) {
                auto soundCompo = entity->getComponent<indie::ecs::component::Sound>(indie::ecs::component::SOUND);
                soundCompo->setPlay(true);
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