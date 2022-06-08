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
    indie::raylib::Window::clearBackground(SKYBLUE);
    

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

void indie::menu::GameScreen::initMap(std::vector<std::vector<char>> map)
{
    float posX = -5.0;
    float posY = 5.0;

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (map[i][j] == '#') {
                std::unique_ptr<indie::ecs::entity::Entity> entityX = std::make_unique<indie::ecs::entity::Entity>();
                entityX->addComponent<indie::ecs::component::Transform>(
                    static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityX->addComponent<indie::ecs::component::Drawable3D>(
                    "src/wall.png", static_cast<float>(0.5), static_cast<float>(0.5), static_cast<float>(0.5), WHITE);
                addEntity(std::move(entityX));
            }
            if (map[i][j] == '.') {
                std::unique_ptr<indie::ecs::entity::Entity> entityA = std::make_unique<indie::ecs::entity::Entity>();
                entityA->addComponent<indie::ecs::component::Transform>(
                    static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityA->addComponent<indie::ecs::component::Drawable3D>(
                    "src/boite.png", static_cast<float>(0.5), static_cast<float>(0.5), static_cast<float>(0.5), WHITE);
                addEntity(std::move(entityA));
            }
            if (map[i][j] == '1') {
                std::unique_ptr<indie::ecs::entity::Entity> entityP1 = std::make_unique<indie::ecs::entity::Entity>();
                entityP1->addComponent<indie::ecs::component::Transform>(
                    static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityP1->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.25), RED);
                addEntity(std::move(entityP1));
            }
            if (map[i][j] == '2') {
                std::unique_ptr<indie::ecs::entity::Entity> entityP2 = std::make_unique<indie::ecs::entity::Entity>();
                entityP2->addComponent<indie::ecs::component::Transform>(
                    static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityP2->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.25), BLUE);
                addEntity(std::move(entityP2));
            }
            if (map[i][j] == '3') {
                std::unique_ptr<indie::ecs::entity::Entity> entityP3 = std::make_unique<indie::ecs::entity::Entity>();
                entityP3->addComponent<indie::ecs::component::Transform>(
                    static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityP3->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.25), GREEN);
                addEntity(std::move(entityP3));
            }
            if (map[i][j] == '4') {
                std::unique_ptr<indie::ecs::entity::Entity> entityP4 = std::make_unique<indie::ecs::entity::Entity>();
                entityP4->addComponent<indie::ecs::component::Transform>(
                    static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityP4->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.25), YELLOW);
                addEntity(std::move(entityP4));
            }
            posX += 0.5;
        }
        posY -= 0.5;
        posX = -5;
    }
}