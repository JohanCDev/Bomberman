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
    /*std::unique_ptr<ecs::Entity> entity2 = std::make_unique<ecs::Entity>();
    std::unique_ptr<ecs::Entity> entity3 = std::make_unique<ecs::Entity>();

    entity2->addComponent<ecs::Transform>(static_cast<float>(100.0), static_cast<float>(100.0), static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity2->addComponent<ecs::Text>("INDIE STUDIOOOO GAME BONJOURRRRRR", static_cast<float>(50.0), BLACK);
    entity3->addComponent<ecs::Transform>(static_cast<float>(500.0), static_cast<float>(500.0), static_cast<float>(0.0),
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity3->addComponent<ecs::Rectangle>("", static_cast<float>(100.0), static_cast<float>(250.0), GREEN);
    addEntity(std::move(entity2));
    addEntity(std::move(entity3));*/
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

int indie::menu::GameScreen::handleEvent(indie::Event &event)
{
    (void)event;
    return 0;
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