/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** GameScreen
*/

#include "GameScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::GameScreen::GameScreen()
    : _camera({0.0, 10.0, 7.0}, {0.0, -1.5, 0.0}, {0.0, 1.0, 0.0}, 50.0, CAMERA_PERSPECTIVE)
{
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
    for (auto &entity : _entities) {
        if (entity->hasCompoType(indie::ecs::component::COLLIDE) == true) {
            entity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::compoType::COLLIDE)
                ->setCollide(false);
        }
    }
}

void indie::menu::GameScreen::update(float delta)
{
    (void)delta;
}

void indie::menu::GameScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::GameScreen::removeEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    int count = 0;

    for (auto &ent : this->_entities) {
        if (ent == entity) {
            this->_entities.erase(this->_entities.begin() + count);
        }
        count++;
    }
}

void indie::menu::GameScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

indie::raylib::Camera3D indie::menu::GameScreen::getCamera() const
{
    return (this->_camera);
}

void indie::menu::GameScreen::handleMultipleController(indie::Event &event, int index, indie::ecs::entity::entityType type)
{
    indie::ecs::component::Transform *transformCompo = nullptr;

    if (event.controller[index].leftJoystick == indie::Event::DOWN) {
        for (auto &entity : this->_entities) {
            if (entity->getEntityType() == type) {
                auto transform =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
                transform->setSpeedY(0.02);
                transform->setSpeedX(0);
            }
        }
    }

    if (event.controller[index].leftJoystick == indie::Event::UP) {
        for (auto &entity : this->_entities) {
            if (entity->getEntityType() == type) {
                auto transform =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
                transform->setSpeedX(0);
                transform->setSpeedY(-0.02);
            }
        }
    }

    if (event.controller[index].leftJoystick == indie::Event::LEFT) {
        for (auto &entity : this->_entities) {
            if (entity->getEntityType() == type) {
                auto transform =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
                transform->setSpeedX(-0.02);
                transform->setSpeedY(0);
            }
        }
    }

    if (event.controller[index].leftJoystick == indie::Event::RIGHT) {
        for (auto &entity : this->_entities) {
            if (entity->getEntityType() == type) {
                auto transform =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
                transform->setSpeedX(0.02);
                transform->setSpeedY(0);
            }
        }
    }

    if (event.controller[index].code == indie::Event::X_BUTTON) {
        for (auto &entity : _entities) {
            if (entity->getEntityType() == indie::ecs::entity::PLAYER_1) {
                transformCompo =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
            }
        }
        if (transformCompo != nullptr) {
            std::unique_ptr<indie::ecs::entity::Entity> entity =
                std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::BOMB);
            entity->addComponent<indie::ecs::component::Explodable>(static_cast<float>(2.0), 2);
            entity->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.25), RED);
            entity->addComponent<indie::ecs::component::Transform>(static_cast<float>(transformCompo->getX()),
                static_cast<float>(transformCompo->getY()), static_cast<float>(0.0), static_cast<float>(0.0));
            addEntity(std::move(entity));
        }
    }
}

void indie::menu::GameScreen::handleEvent(indie::Event &event)
{
    handleMultipleController(event, 0, indie::ecs::entity::entityType::PLAYER_1);
    handleMultipleController(event, 1, indie::ecs::entity::entityType::PLAYER_2);
    handleMultipleController(event, 2, indie::ecs::entity::entityType::PLAYER_3);
    handleMultipleController(event, 3, indie::ecs::entity::entityType::PLAYER_4);
}

void indie::menu::GameScreen::initMap(std::vector<std::vector<char>> map)
{
    float posX = -5.0;
    float posY = 5.0;

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (map[i][j] == '#') {
                std::unique_ptr<indie::ecs::entity::Entity> entityX =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::WALL);
                entityX->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityX->addComponent<indie::ecs::component::Drawable3D>(
                    "src/wall.png", static_cast<float>(0.5), static_cast<float>(0.5), static_cast<float>(0.5), WHITE);
                entityX->addComponent<indie::ecs::component::Collide>();
                addEntity(std::move(entityX));
            }
            if (map[i][j] == '.') {
                std::unique_ptr<indie::ecs::entity::Entity> entityA =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::BOXES);
                entityA->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityA->addComponent<indie::ecs::component::Collide>();
                entityA->addComponent<indie::ecs::component::Drawable3D>(
                    "src/boite.png", static_cast<float>(0.5), static_cast<float>(0.5), static_cast<float>(0.5), WHITE);
                addEntity(std::move(entityA));
            }
            if (map[i][j] == '1') {
                std::unique_ptr<indie::ecs::entity::Entity> entityP1 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_1);
                entityP1->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityP1->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.2), BLUE);
                entityP1->addComponent<indie::ecs::component::Collide>();
                addEntity(std::move(entityP1));
            }
            if (map[i][j] == '2') {
                std::unique_ptr<indie::ecs::entity::Entity> entityP2 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_2);
                entityP2->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityP2->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.2), RED);
                entityP2->addComponent<indie::ecs::component::Collide>();
                addEntity(std::move(entityP2));
            }
            if (map[i][j] == '3') {
                std::unique_ptr<indie::ecs::entity::Entity> entityP3 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_3);
                entityP3->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityP3->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.2), YELLOW);
                entityP3->addComponent<indie::ecs::component::Collide>();
                addEntity(std::move(entityP3));
            }
            if (map[i][j] == '4') {
                std::unique_ptr<indie::ecs::entity::Entity> entityP4 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_4);
                entityP4->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityP4->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.2), GREEN);
                entityP4->addComponent<indie::ecs::component::Collide>();
                addEntity(std::move(entityP4));
            }
            if (map[i][j] == 'B') {
                std::unique_ptr<indie::ecs::entity::Entity> entityB = std::make_unique<indie::ecs::entity::Entity>();
                entityB->addComponent<indie::ecs::component::Transform>(
                    static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityB->addComponent<indie::ecs::component::Drawable3D>(
                    "", static_cast<float>(0.25), static_cast<float>(0.25), static_cast<float>(0.25), RED);
                addEntity(std::move(entityB));
            }
            if (map[i][j] == 'T') {
                std::unique_ptr<indie::ecs::entity::Entity> entityT = std::make_unique<indie::ecs::entity::Entity>();
                entityT->addComponent<indie::ecs::component::Transform>(
                    static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityT->addComponent<indie::ecs::component::Drawable3D>(
                    "", static_cast<float>(0.25), static_cast<float>(0.25), static_cast<float>(0.25), MAGENTA);
                addEntity(std::move(entityT));
            }
            if (map[i][j] == 'S') {
                std::unique_ptr<indie::ecs::entity::Entity> entityS = std::make_unique<indie::ecs::entity::Entity>();
                entityS->addComponent<indie::ecs::component::Transform>(
                    static_cast<float>(posX), static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityS->addComponent<indie::ecs::component::Drawable3D>(
                    "", static_cast<float>(0.25), static_cast<float>(0.25), static_cast<float>(0.25), YELLOW);
                addEntity(std::move(entityS));
            }
            posX += 0.5;
        }
        posY -= 0.5;
        posX = -5;
    }
}