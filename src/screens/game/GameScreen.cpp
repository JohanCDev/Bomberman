/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** GameScreen
*/

#include "GameScreen.hpp"
#include "../../player/Player.hpp"
#include "../../raylib/Raylib.hpp"
#include "Colors.hpp"
#include "uiPlayerDisplay/UIPlayerDisplay.hpp"

indie::menu::GameScreen::GameScreen()
    : _camera({0.0, 10.0, 10.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 45.0, CAMERA_PERSPECTIVE)
{
    player::Player player1(BLUEPLAYERCOLOR, 0, {0, 0});
    player::Player player2(REDPLAYERCOLOR, 1, {0, 0});
    player::Player player3(YELLOWPLAYERCOLOR, 2, {0, 0});
    player::Player player4(GREENPLAYERCOLOR, 3, {0, 0});

    this->_infoPlayers.push_back(std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(
        player1, (vec2f){25.f, 25.f}, (vec2f){200.0, 300.0}));
    this->_infoPlayers.push_back(std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(
        player2, (vec2f){25.f, 982.f - 225.f}, (vec2f){200.0, 300.0}));
    this->_infoPlayers.push_back(std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(
        player3, (vec2f){1512.f - 325.f, 25.f}, (vec2f){200.0, 300.0}));
    this->_infoPlayers.push_back(std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(
        player4, (vec2f){1512.f - 325.f, 982.f - 225.f}, (vec2f){200.0, 300.0}));
    for (auto &uiDisplay : this->_infoPlayers) {
        uiDisplay->create();
    }
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
    for (auto &uiDisplay : this->_infoPlayers) {
        if (uiDisplay->getPlayer().getIsAlive())
            uiDisplay->draw();
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