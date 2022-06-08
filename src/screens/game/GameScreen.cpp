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