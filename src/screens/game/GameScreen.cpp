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
    std::unique_ptr<indie::ecs::entity::Entity> entity3 = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::entity::Entity> entity4 = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::entity::Entity> entity5 = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystem = std::make_unique<indie::ecs::system::Draw2DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> draw3DSystem = std::make_unique<indie::ecs::system::Draw3DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> movementSystem =
        std::make_unique<indie::ecs::system::MovementSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> soundSystem = std::make_unique<indie::ecs::system::Sound>();
    std::unique_ptr<indie::ecs::system::ISystem> collideSystem = std::make_unique<indie::ecs::system::Collide>();

    entity3->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(500.0), static_cast<float>(500.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entity3->addComponent<indie::ecs::component::Drawable2D>(
        "src/boite.png", static_cast<float>(100.0), static_cast<float>(250.0), WHITE);
    entity4->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(1.0), static_cast<float>(1.0), static_cast<float>(-0.02), static_cast<float>(0.0));
    entity4->addComponent<indie::ecs::component::Drawable3D>(
        "src/boite.png", static_cast<float>(1.0), static_cast<float>(1.0), static_cast<float>(1.0), WHITE);
    entity4->addComponent<indie::ecs::component::Collide>();
    entity5->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(-2.0), static_cast<float>(1.0), static_cast<float>(0.02), static_cast<float>(0.0));
    entity5->addComponent<indie::ecs::component::Drawable3D>(
        "src/boite.png", static_cast<float>(1.0), static_cast<float>(1.0), static_cast<float>(1.0), BLUE);
    entity5->addComponent<indie::ecs::component::Collide>();
    // entity4->addComponent<indie::ecs::component::Sound>("src/maybe-next-time.wav", false);
    addEntity(std::move(entity3));
    addEntity(std::move(entity4));
    addEntity(std::move(entity5));
    addSystem(std::move(draw2DSystem));
    addSystem(std::move(draw3DSystem));
    addSystem(std::move(movementSystem));
    addSystem(std::move(soundSystem));
    addSystem(std::move(collideSystem));
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
    if (event.controller[0].code == indie::Event::ControllerCode::OPTION_BUTTON)
        return 5;
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