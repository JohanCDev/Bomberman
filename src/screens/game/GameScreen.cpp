/**
 * @file GameScreen.cpp
 * @author Victor & Henri(victor.harri-chal@epitech.eu & henri.chauvet@epitech.eu)
 * @brief The screen for the game
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "GameScreen.hpp"
#include "../../player/Player.hpp"
#include "../../raylib/Raylib.hpp"
#include "../../tools/Tools.hpp"
#include "../ecs/system/Sound/Sound.hpp"
#include "Colors.hpp"
#include "uiPlayerDisplay/UIPlayerDisplay.hpp"

#include <vector>

indie::menu::GameScreen::GameScreen(std::vector<player::Player> *players,
    std::vector<std::unique_ptr<indie::ecs::entity::Entity>> *soundEntities,
    std::vector<std::unique_ptr<indie::ecs::system::ISystem>> *soundSystems)
    : _camera({0.0, 60.0, 18.0}, {0.0, -1.5, 0.0}, {0.0, 1.0, 0.0}, 40.0, CAMERA_PERSPECTIVE), _player1_blue(false),
      _player2_red(false), _player3_green(false), _player4_yellow(false), _is_game_finished(false),
      _end_screen_display(true)
{
    _players = players;
    _soundEntities = soundEntities;
    _soundSystems = soundSystems;
}

void indie::menu::GameScreen::init()
{
    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystem = std::make_unique<indie::ecs::system::Draw2DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> draw3DSystem = std::make_unique<indie::ecs::system::Draw3DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> movementSystem =
        std::make_unique<indie::ecs::system::MovementSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> soundSystem = std::make_unique<indie::ecs::system::Sound>();
    std::unique_ptr<indie::ecs::system::ISystem> collideSystem = std::make_unique<indie::ecs::system::Collide>();
    std::unique_ptr<indie::ecs::system::Explodable> explodeSystem = std::make_unique<indie::ecs::system::Explodable>();
    std::unique_ptr<indie::ecs::system::ObjectSystem> objectSystem =
        std::make_unique<indie::ecs::system::ObjectSystem>();
    std::unique_ptr<indie::ecs::entity::Entity> entityX =
        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);

    entityX->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entityX->addComponent<indie::ecs::component::Drawable3D>(
        "", static_cast<float>(40.5), static_cast<float>(0.05), static_cast<float>(40), LIGHTGRAY);
    entityX->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM)->setZ(-1.0);
    _playerAssets[0] = std::string("./assets/blue.png");
    _playerAssets[1] = std::string("./assets/red.png");
    _playerAssets[2] = std::string("./assets/green.png");
    _playerAssets[3] = std::string("./assets/yellow.png");
    this->addEntity(std::move(entityX));
    this->addSystem(std::move(draw2DSystem));
    this->addSystem(std::move(draw3DSystem));
    this->addSystem(std::move(movementSystem));
    this->addSystem(std::move(soundSystem));
    this->addSystem(std::move(collideSystem));
    this->addSystem(std::move(explodeSystem));
    this->addSystem(std::move(objectSystem));
}

void indie::menu::GameScreen::draw()
{
    indie::raylib::Camera3D camera = getCamera();
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(SKYBLUE);

    for (auto &system : this->_systems) {
        if ((system->getSystemType() == indie::ecs::system::SystemType::DRAWABLE3DSYSTEM
                || system->getSystemType() == indie::ecs::system::SystemType::OBJECTSYSTEM)
            && !_is_game_finished) {
            camera.beginMode();
            system->update(this->_entities);
            camera.endMode();
        } else {
            system->update(this->_entities);
        }
    }
    for (auto &uiDisplay : _infoPlayers)
        if (uiDisplay->getPlayer().getIsAlive() && !_is_game_finished)
            uiDisplay->draw();
    indie::raylib::Window::endDrawing();
    size_t index = 0;
    std::vector<size_t> entityToRemove;
    for (auto &entity : _entities) {
        if (entity->hasCompoType(indie::ecs::component::EXPLODABLE)) {
            auto explodeCompo =
                entity->getComponent<indie::ecs::component::Explodable>(indie::ecs::component::EXPLODABLE);
            if (explodeCompo->getExploded() == true) {
                this->_players->at(explodeCompo->getPlayer())
                    .setBombStock(this->_players->at(explodeCompo->getPlayer()).getBombStock() + 1);
                entityToRemove.push_back(index);
            }
        }
        indie::ecs::entity::entityType type = entity->getEntityType();
        if (type == indie::ecs::entity::entityType::PLAYER_1 || type == indie::ecs::entity::entityType::PLAYER_2
            || type == indie::ecs::entity::entityType::PLAYER_3 || type == indie::ecs::entity::entityType::PLAYER_4) {
            entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM)->setSpeedX(0.0f);
            entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::TRANSFORM)->setSpeedY(0.0f);
            if (entity->hasCompoType(indie::ecs::component::INVENTORY)) {
                auto inventory =
                    entity->getComponent<indie::ecs::component::Inventory>(indie::ecs::component::INVENTORY);
                if (inventory->getFireUp() == true) {
                    this->_players->at(type).setBombRadius(this->_players->at(type).getBombRadius() + 1);
                    inventory->setFireUp(false);
                } else if (inventory->getSpeedUp() == true) {
                    this->_players->at(type).setSpeed(this->_players->at(type).getSpeed() + 3);
                    inventory->setSpeedUp(false);
                } else if (inventory->getBombUp() == true) {
                    this->_players->at(type).setBombStock(this->_players->at(type).getBombStock() + 1);
                    this->_players->at(type).setMaxBombStock(this->_players->at(type).getMaxBombStock() + 1);
                    inventory->setBombUp(false);
                }
            }
            if (entity->hasCompoType(indie::ecs::component::ALIVE)) {
                bool alive =
                    entity->getComponent<indie::ecs::component::Alive>(indie::ecs::component::ALIVE)->getAlive();
                if (alive == false) {
                    this->_players->at(type).setIsAlive(false);
                }
            }
        }
        if (entity->hasCompoType(indie::ecs::component::COLLIDE) == true) {
            entity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::compoType::COLLIDE)
                ->setCollide(false);
        }
        index++;
    }
    size_t count = 0;
    for (auto &i : entityToRemove) {
        this->_entities.erase(this->_entities.begin() + i - count);
        count++;
    }
}

void indie::menu::GameScreen::update()
{
    for (auto &uiDisplay : _infoPlayers)
        uiDisplay->update();
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

void indie::menu::GameScreen::getPlayersPlaying(
    bool is_p1_playing, bool is_p2_playing, bool is_p3_playing, bool is_p4_playing)
{
    _player1_blue = is_p1_playing;
    _player2_red = is_p2_playing;
    _player3_green = is_p3_playing;
    _player4_yellow = is_p4_playing;
}

void indie::menu::GameScreen::initEntity()
{
    vec2f uiSize = vec2f({tools::Tools::getPercentage(15.f, false), tools::Tools::getPercentage(15.f, true)});
    vec2f topLeftPos = vec2f({tools::Tools::getPercentage(3.f, true), tools::Tools::getPercentage(11.f, false)});
    vec2f topRightPos = vec2f({tools::Tools::getPercentage(84.f, true), tools::Tools::getPercentage(11.f, false)});
    vec2f bottomLeftPos = vec2f({tools::Tools::getPercentage(3.f, true), tools::Tools::getPercentage(82.f, false)});
    vec2f bottomRightPos = vec2f({tools::Tools::getPercentage(84.f, true), tools::Tools::getPercentage(82.f, false)});

    if (_player1_blue) {
        this->_infoPlayers.push_back(std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(
            &_players->at(0), topLeftPos, uiSize));
    }
    if (_player2_red) {
        this->_infoPlayers.push_back(std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(
            &_players->at(1), topRightPos, uiSize));
    }
    if (_player3_green) {
        this->_infoPlayers.push_back(std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(
            &_players->at(2), bottomLeftPos, uiSize));
    }
    if (_player4_yellow) {
        this->_infoPlayers.push_back(std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(
            &_players->at(3), bottomRightPos, uiSize));
    }
    for (auto &uiDisplay : this->_infoPlayers) {
        uiDisplay->create();
    }
}

void indie::menu::GameScreen::handleMultipleController(
    indie::Event &event, int index, indie::ecs::entity::entityType type)
{
    indie::ecs::component::Transform *transformCompo = nullptr;

    if (event.controller[index].leftJoystick == indie::Event::DOWN) {
        for (auto &entity : this->_entities) {
            if (entity->getEntityType() == type) {
                auto objectCompo = entity->getComponent<indie::ecs::component::Object>(indie::ecs::component::ANIMATED);
                auto transform =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
                float speed = static_cast<float>(this->_players->at(index).getSpeed());
                transform->setSpeedY(speed / 50.0f);
                transform->setSpeedX(0);
                objectCompo->setOrientation(indie::ecs::component::Object::SOUTH);
                objectCompo->setAnimationsCounter(objectCompo->getAnimationsCounter() + 5);
                raylib::Model::updateModelAnimation(
                    objectCompo->getModel(), objectCompo->getAnimations()[0], objectCompo->getAnimationsCounter());
                if (objectCompo->getAnimationsCounter() >= objectCompo->getAnimations()[0].frameCount)
                    objectCompo->setAnimationsCounter(0);
            }
        }
    }
    if (event.controller[index].leftJoystick == indie::Event::UP) {
        for (auto &entity : this->_entities) {
            if (entity->getEntityType() == type) {
                auto objectCompo = entity->getComponent<indie::ecs::component::Object>(indie::ecs::component::ANIMATED);
                auto transform =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
                float speed = static_cast<float>(this->_players->at(index).getSpeed());
                transform->setSpeedX(0);
                transform->setSpeedY((speed / 50.0f) * -1.0f);
                objectCompo->setOrientation(indie::ecs::component::Object::NORTH);
                objectCompo->setAnimationsCounter(objectCompo->getAnimationsCounter() + 5);
                raylib::Model::updateModelAnimation(
                    objectCompo->getModel(), objectCompo->getAnimations()[0], objectCompo->getAnimationsCounter());
                if (objectCompo->getAnimationsCounter() >= objectCompo->getAnimations()[0].frameCount)
                    objectCompo->setAnimationsCounter(0);
            }
        }
    }
    if (event.controller[index].leftJoystick == indie::Event::LEFT) {
        for (auto &entity : this->_entities) {
            if (entity->getEntityType() == type) {
                auto objectCompo = entity->getComponent<indie::ecs::component::Object>(indie::ecs::component::ANIMATED);
                auto transform =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
                float speed = static_cast<float>(this->_players->at(index).getSpeed());
                transform->setSpeedX((speed / 50.0f) * -1.0f);
                transform->setSpeedY(0);
                objectCompo->setOrientation(indie::ecs::component::Object::WEST);
                objectCompo->setAnimationsCounter(objectCompo->getAnimationsCounter() + 5);
                raylib::Model::updateModelAnimation(
                    objectCompo->getModel(), objectCompo->getAnimations()[0], objectCompo->getAnimationsCounter());
                if (objectCompo->getAnimationsCounter() >= objectCompo->getAnimations()[0].frameCount)
                    objectCompo->setAnimationsCounter(0);
            }
        }
    }
    if (event.controller[index].leftJoystick == indie::Event::RIGHT) {
        for (auto &entity : this->_entities) {
            if (entity->getEntityType() == type) {
                auto objectCompo = entity->getComponent<indie::ecs::component::Object>(indie::ecs::component::ANIMATED);
                auto transform =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
                float speed = static_cast<float>(this->_players->at(index).getSpeed());
                if (transform != nullptr) {
                    transform->setSpeedX(speed / 50.0f);
                    transform->setSpeedY(0);
                }
                objectCompo->setOrientation(indie::ecs::component::Object::EAST);
                objectCompo->setAnimationsCounter(objectCompo->getAnimationsCounter() + 5);
                raylib::Model::updateModelAnimation(
                    objectCompo->getModel(), objectCompo->getAnimations()[0], objectCompo->getAnimationsCounter());
                if (objectCompo->getAnimationsCounter() >= objectCompo->getAnimations()[0].frameCount)
                    objectCompo->setAnimationsCounter(0);
            }
        }
    }
    if (event.controller[index].code == indie::Event::X_BUTTON) {
        for (auto &entity : _entities) {
            if (entity->getEntityType() == type) {
                transformCompo =
                    entity->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM);
            }
        }
        if (transformCompo != nullptr && this->_players->at(index).getBombStock() > 0) {
            std::unique_ptr<indie::ecs::entity::Entity> entity =
                std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::BOMB);
            indie::vec3f scaleVec({1.0f, 1.0f, 1.0f});
            indie::vec3f rotationVec({1.0f, 0.0f, 0.0f});

            entity->addComponent<indie::ecs::component::Object>(
                "assets/objects/Bomb/Bomb.png", "assets/objects/Bomb/bomb.obj", scaleVec, rotationVec, -30.0f);
            entity->addComponent<indie::ecs::component::Explodable>(
                static_cast<float>((this->_players->at(index).getBombRadius()) * 2.0f), 2);
            entity->getComponent<indie::ecs::component::Explodable>(indie::ecs::component::EXPLODABLE)
                ->setPlayer(index);
            entity->addComponent<indie::ecs::component::Transform>(static_cast<float>(transformCompo->getX()),
                static_cast<float>(transformCompo->getY()), static_cast<float>(0.0), static_cast<float>(0.0));
            addEntity(std::move(entity));
            this->_players->at(index).setBombStock(this->_players->at(index).getBombStock() - 1);
        }
    }
    // If a bomb is exploded, set the bomb sound.
    if (_entities.back()->hasCompoType(indie::ecs::component::EXPLODABLE) == true) {
        auto bomb =
            _entities.back()->getComponent<indie::ecs::component::Explodable>(indie::ecs::component::EXPLODABLE);
        if (bomb->getExplode() == true) {
            _soundEntities->at(0)->getComponent<ecs::component::Sound>(ecs::component::compoType::SOUND)->setPlay(true);
            for (auto &system : *this->_soundSystems) {
                system->update(*this->_soundEntities);
            }
            _soundEntities->at(0)
                ->getComponent<ecs::component::Sound>(ecs::component::compoType::SOUND)
                ->setPlay(false);
        }
    }
}

int indie::menu::GameScreen::handleEvent(indie::Event &event)
{
    if (!_is_game_finished) {
        if (this->_players->at(0).getIsPlaying() && this->_players->at(0).getIsAlive())
            handleMultipleController(event, 0, indie::ecs::entity::entityType::PLAYER_1);
        if (this->_players->at(1).getIsPlaying() && this->_players->at(1).getIsAlive())
            handleMultipleController(event, 1, indie::ecs::entity::entityType::PLAYER_2);
        if (this->_players->at(2).getIsPlaying() && this->_players->at(2).getIsAlive())
            handleMultipleController(event, 2, indie::ecs::entity::entityType::PLAYER_3);
        if (this->_players->at(3).getIsPlaying() && this->_players->at(3).getIsAlive())
            handleMultipleController(event, 3, indie::ecs::entity::entityType::PLAYER_4);
        if (event.controller[0].code == indie::Event::ControllerCode::OPTION_BUTTON || event.key.r_shift)
            return 4;
        if (countAlivePlayers() == 1)
            _is_game_finished = true;
    } else {
        if (_end_screen_display) {
            endScreenDisplay();
            _end_screen_display = false;
        }
        if (event.controller[0].code == indie::Event::ControllerCode::T_BUTTON || event.key.r_shift)
            return 1;
    }
    return 0;
}

void indie::menu::GameScreen::initMap(std::vector<std::vector<char>> map)
{
    float posX = -20.0;
    float posY = 20.0;
    indie::vec3f scalePlayerVec({1.0f, 1.0f, 1.0f});
    indie::vec3f rotationPlayerVec({0.f, 1.f, 0.f});

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (map[i][j] == '#') {
                std::unique_ptr<indie::ecs::entity::Entity> entityX =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::WALL);
                entityX->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityX->addComponent<indie::ecs::component::Drawable3D>(
                    "src/wall.png", static_cast<float>(2.0), static_cast<float>(2.0), static_cast<float>(2.0), WHITE);
                entityX->addComponent<indie::ecs::component::Collide>();
                addEntity(std::move(entityX));
            }
            if (map[i][j] == '.') {
                std::unique_ptr<indie::ecs::entity::Entity> entityA =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::BOXES);
                entityA->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityA->addComponent<indie::ecs::component::Collide>();
                entityA->addComponent<indie::ecs::component::Destroyable>();
                entityA->addComponent<indie::ecs::component::Drawable3D>(
                    "src/boite.png", static_cast<float>(2.0), static_cast<float>(2.0), static_cast<float>(2.0), WHITE);
                addEntity(std::move(entityA));
            }
            if (map[i][j] == '1') {
                std::unique_ptr<indie::ecs::entity::Entity> entityP1 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::PLAYER_1);

                entityP1->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityP1->addComponent<indie::ecs::component::Object>("./assets/player/textures/blue.png",
                    "./assets/player/player.iqm", "./assets/player/player.iqm", scalePlayerVec, rotationPlayerVec,
                    static_cast<float>(ecs::component::Object::SOUTH));
                entityP1->addComponent<indie::ecs::component::Destroyable>();
                entityP1->addComponent<indie::ecs::component::Inventory>();
                entityP1->addComponent<indie::ecs::component::Collide>();
                entityP1->addComponent<indie::ecs::component::Alive>(true);
                addEntity(std::move(entityP1));
            }
            if (_player2_red) {
                if (map[i][j] == '2') {
                    std::unique_ptr<indie::ecs::entity::Entity> entityP2 =
                        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_2);
                    entityP2->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                        static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                    entityP2->addComponent<indie::ecs::component::Object>("./assets/player/textures/red.png",
                        "./assets/player/player.iqm", "./assets/player/player.iqm", scalePlayerVec, rotationPlayerVec,
                        static_cast<float>(ecs::component::Object::SOUTH));
                    entityP2->addComponent<indie::ecs::component::Destroyable>();
                    entityP2->addComponent<indie::ecs::component::Inventory>();
                    entityP2->addComponent<indie::ecs::component::Collide>();
                    entityP2->addComponent<indie::ecs::component::Alive>(true);
                    addEntity(std::move(entityP2));
                }
            }
            if (_player3_green) {
                if (map[i][j] == '3') {
                    std::unique_ptr<indie::ecs::entity::Entity> entityP3 =
                        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_3);
                    entityP3->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                        static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                    entityP3->addComponent<indie::ecs::component::Object>("./assets/player/textures/green.png",
                        "./assets/player/player.iqm", "./assets/player/player.iqm", scalePlayerVec, rotationPlayerVec,
                        static_cast<float>(ecs::component::Object::NORTH));
                    entityP3->addComponent<indie::ecs::component::Destroyable>();
                    entityP3->addComponent<indie::ecs::component::Inventory>();
                    entityP3->addComponent<indie::ecs::component::Collide>();
                    entityP3->addComponent<indie::ecs::component::Alive>(true);
                    addEntity(std::move(entityP3));
                }
            }
            if (_player4_yellow) {
                if (map[i][j] == '4') {
                    std::unique_ptr<indie::ecs::entity::Entity> entityP4 =
                        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_4);
                    entityP4->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                        static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                    entityP4->addComponent<indie::ecs::component::Object>("./assets/player/textures/yellow.png",
                        "./assets/player/player.iqm", "./assets/player/player.iqm", scalePlayerVec, rotationPlayerVec,
                        static_cast<float>(ecs::component::Object::NORTH));
                    entityP4->addComponent<indie::ecs::component::Destroyable>();
                    entityP4->addComponent<indie::ecs::component::Inventory>();
                    entityP4->addComponent<indie::ecs::component::Collide>();
                    entityP4->addComponent<indie::ecs::component::Alive>(true);
                    addEntity(std::move(entityP4));
                }
            }
            if (map[i][j] == 'B') {
                std::unique_ptr<indie::ecs::entity::Entity> entityB =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
                entityB->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                vec3f scale({1.0f, 1.0f, 1.0f});
                vec3f rotation({0.0f, 1.0f, 0.0f});

                entityB->addComponent<indie::ecs::component::Object>(
                    "assets/objects/Charger/charger.png", "assets/objects/Charger/charger.obj", scale, rotation, 90.0f);
                entityB->addComponent<indie::ecs::component::Collectable>(indie::ecs::component::BOMBUP);
                entityB->addComponent<indie::ecs::component::Collide>();
                addEntity(std::move(entityB));
                std::unique_ptr<indie::ecs::entity::Entity> entityB2 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::BOXES);
                entityB2->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityB2->addComponent<indie::ecs::component::Collide>();
                entityB2->addComponent<indie::ecs::component::Destroyable>();
                entityB2->addComponent<indie::ecs::component::Drawable3D>(
                    "src/boite.png", static_cast<float>(2.0), static_cast<float>(2.0), static_cast<float>(2.0), WHITE);
                addEntity(std::move(entityB2));
            }
            if (map[i][j] == 'S') {
                std::unique_ptr<indie::ecs::entity::Entity> entityS =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
                entityS->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                vec3f scale({1.0f, 1.0f, 1.0f});
                vec3f rotation({0.0f, 1.0f, 0.0f});

                entityS->addComponent<indie::ecs::component::Object>(
                    "assets/objects/Boot/boot.png", "assets/objects/Boot/boot.obj", scale, rotation, 90.0f);
                entityS->addComponent<indie::ecs::component::Collectable>(indie::ecs::component::SPEEDUP);
                entityS->addComponent<indie::ecs::component::Collide>();
                addEntity(std::move(entityS));
                std::unique_ptr<indie::ecs::entity::Entity> entityS2 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::BOXES);
                entityS2->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityS2->addComponent<indie::ecs::component::Collide>();
                entityS2->addComponent<indie::ecs::component::Destroyable>();
                entityS2->addComponent<indie::ecs::component::Drawable3D>(
                    "src/boite.png", static_cast<float>(2.0), static_cast<float>(2.0), static_cast<float>(2.0), WHITE);
                addEntity(std::move(entityS2));
            }
            if (map[i][j] == 'R') {
                std::unique_ptr<indie::ecs::entity::Entity> entityR =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
                entityR->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                vec3f scale({1.0f, 1.0f, 1.0f});
                vec3f rotation({0.0f, 0.0f, 1.0f});

                entityR->addComponent<indie::ecs::component::Object>(
                    "assets/objects/Tnt/tnt.png", "assets/objects/Tnt/tnt.obj", scale, rotation, 90.0f);
                entityR->addComponent<indie::ecs::component::Collectable>(indie::ecs::component::bonusType::FIREUP);
                entityR->addComponent<indie::ecs::component::Collide>();
                addEntity(std::move(entityR));
                std::unique_ptr<indie::ecs::entity::Entity> entityR2 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::BOXES);
                entityR2->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityR2->addComponent<indie::ecs::component::Collide>();
                entityR2->addComponent<indie::ecs::component::Destroyable>();
                entityR2->addComponent<indie::ecs::component::Drawable3D>(
                    "src/boite.png", static_cast<float>(2.0), static_cast<float>(2.0), static_cast<float>(2.0), WHITE);
                addEntity(std::move(entityR2));
            }
            posX += 2.0;
        }
        posY -= 2.0;
        posX = -20;
    }
}

bool indie::menu::GameScreen::compareColor(Color a, Color b)
{
    return (a.a == b.a && a.b == b.b && a.g == b.g && a.r == b.r);
}

void indie::menu::GameScreen::saveMapEntities()
{
    remove("SaveFile.txt");
    std::fstream file;
    file.open("SaveFile.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    bool mapEnd = false;

    for (int i = 0; i < 4; i++) {
        file << "P" << i << " " << i << " " << this->_players->at(i).getIsAlive() << " "
             << this->_players->at(i).getIsPlaying() << " " << this->_players->at(i).getBombRadius() << " "
             << this->_players->at(i).getBombStock() << " " << this->_players->at(i).getMaxBombStock() << " "
             << this->_players->at(i).getSpeed() << std::endl;
    }
    for (int i = 1; !mapEnd; i++) {
        if (_entities.at(i)->getEntityType() == indie::ecs::entity::entityType::WALL) {
            file << "# ";
            ecs::component::Transform *transformCompo =
                _entities.at(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            file << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
            if (transformCompo->getX() == 20 && transformCompo->getY() == -20)
                mapEnd = true;
        }
        if (_entities.at(i)->getEntityType() == indie::ecs::entity::entityType::BOXES) {
            file << ". ";
            ecs::component::Transform *transformCompo =
                _entities.at(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            file << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
        }
        if (_entities.at(i)->getEntityType() == indie::ecs::entity::entityType::PLAYER_1) {
            file << "1 ";
            ecs::component::Transform *transformCompo =
                _entities.at(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            file << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
        }
        if (_entities.at(i)->getEntityType() == indie::ecs::entity::entityType::PLAYER_2) {
            file << "2 ";
            ecs::component::Transform *transformCompo =
                _entities.at(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            file << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
        }
        if (_entities.at(i)->getEntityType() == indie::ecs::entity::entityType::PLAYER_3) {
            file << "3 ";
            ecs::component::Transform *transformCompo =
                _entities.at(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            file << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
        }
        if (_entities.at(i)->getEntityType() == indie::ecs::entity::entityType::PLAYER_4) {
            file << "4 ";
            ecs::component::Transform *transformCompo =
                _entities.at(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            file << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
        }
        if (_entities.at(i)->getEntityType() == indie::ecs::entity::entityType::UNKNOWN) {
            ecs::component::Transform *transformCompo =
                _entities.at(i)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
            ecs::component::Collectable *collectableCompo =
                _entities.at(i)->getComponent<ecs::component::Collectable>(ecs::component::compoType::COLLECTABLE);
            if (collectableCompo->getBonusType() == indie::ecs::component::BOMBUP)
                file << "B " << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
            if (collectableCompo->getBonusType() == indie::ecs::component::SPEEDUP)
                file << "S " << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
            if (collectableCompo->getBonusType() == indie::ecs::component::FIREUP)
                file << "R " << transformCompo->getX() << " " << transformCompo->getY() << std::endl;
        }
    }
    file.close();
}

bool indie::menu::GameScreen::loadSavedMap()
{
    std::ifstream file;
    file.open("SaveFile.txt");
    std::string line;
    if (file.is_open()) {
        this->_players->clear();
        while (file) {
            std::getline(file, line);
            if (line.size() == 0)
                break;
            std::stringstream buffer(line);
            std::vector<std::string> args;
            std::string arg;
            while (std::getline(buffer, arg, ' '))
                args.push_back(arg);
            initRightEntity(args);
        }
    } else
        return false;
    file.close();
    return true;
}

void indie::menu::GameScreen::initRightEntity(std::vector<std::string> args)
{
    indie::vec3f scalePlayerVec({1.0f, 1.0f, 1.0f});
    indie::vec3f rotationPlayerVec({0.f, 1.f, 0.f});

    if (args[0] == "#") {
        std::unique_ptr<indie::ecs::entity::Entity> entityX =
            std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::WALL);
        entityX->addComponent<indie::ecs::component::Transform>(static_cast<float>(std::stof(args[1])),
            static_cast<float>(std::stof(args[2])), static_cast<float>(0.0), static_cast<float>(0.0));
        entityX->addComponent<indie::ecs::component::Drawable3D>(
            "src/wall.png", static_cast<float>(2.0), static_cast<float>(2.0), static_cast<float>(2.0), WHITE);
        entityX->addComponent<indie::ecs::component::Collide>();
        addEntity(std::move(entityX));
    }
    if (args[0] == ".") {
        std::unique_ptr<indie::ecs::entity::Entity> entityA =
            std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::BOXES);
        entityA->addComponent<indie::ecs::component::Transform>(static_cast<float>(std::stof(args[1])),
            static_cast<float>(std::stof(args[2])), static_cast<float>(0.0), static_cast<float>(0.0));
        entityA->addComponent<indie::ecs::component::Collide>();
        entityA->addComponent<indie::ecs::component::Destroyable>();
        entityA->addComponent<indie::ecs::component::Drawable3D>(
            "src/boite.png", static_cast<float>(2.0), static_cast<float>(2.0), static_cast<float>(2.0), WHITE);
        addEntity(std::move(entityA));
    }
    if (args[0] == "1" && this->_players->at(0).getIsAlive() == true) {
        std::unique_ptr<indie::ecs::entity::Entity> entityP1 =
            std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::entityType::PLAYER_1);

        entityP1->addComponent<indie::ecs::component::Transform>(static_cast<float>(std::stof(args[1])),
            static_cast<float>(std::stof(args[2])), static_cast<float>(0.0), static_cast<float>(0.0));
        entityP1->addComponent<indie::ecs::component::Object>("./assets/player/textures/blue.png",
            "./assets/player/player.iqm", "./assets/player/player.iqm", scalePlayerVec, rotationPlayerVec,
            static_cast<float>(ecs::component::Object::SOUTH));
        entityP1->addComponent<indie::ecs::component::Destroyable>();
        entityP1->addComponent<indie::ecs::component::Inventory>();
        entityP1->addComponent<indie::ecs::component::Collide>();
        entityP1->addComponent<indie::ecs::component::Alive>(true);
        addEntity(std::move(entityP1));
        _player1_blue = true;
    }
    if (args[0] == "2" && this->_players->at(1).getIsAlive() == true) {
        std::unique_ptr<indie::ecs::entity::Entity> entityP2 =
            std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_2);
        entityP2->addComponent<indie::ecs::component::Transform>(static_cast<float>(std::stof(args[1])),
            static_cast<float>(std::stof(args[2])), static_cast<float>(0.0), static_cast<float>(0.0));
        entityP2->addComponent<indie::ecs::component::Object>("./assets/player/textures/red.png",
            "./assets/player/player.iqm", "./assets/player/player.iqm", scalePlayerVec, rotationPlayerVec,
            static_cast<float>(ecs::component::Object::SOUTH));
        entityP2->addComponent<indie::ecs::component::Destroyable>();
        entityP2->addComponent<indie::ecs::component::Inventory>();
        entityP2->addComponent<indie::ecs::component::Collide>();
        entityP2->addComponent<indie::ecs::component::Alive>(true);
        addEntity(std::move(entityP2));
        _player2_red = true;
    }
    if (args[0] == "3" && this->_players->at(2).getIsAlive() == true) {
        std::unique_ptr<indie::ecs::entity::Entity> entityP3 =
            std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_3);
        entityP3->addComponent<indie::ecs::component::Transform>(static_cast<float>(std::stof(args[1])),
            static_cast<float>(std::stof(args[2])), static_cast<float>(0.0), static_cast<float>(0.0));
        entityP3->addComponent<indie::ecs::component::Object>("./assets/player/textures/green.png",
            "./assets/player/player.iqm", "./assets/player/player.iqm", scalePlayerVec, rotationPlayerVec,
            static_cast<float>(ecs::component::Object::NORTH));
        entityP3->addComponent<indie::ecs::component::Destroyable>();
        entityP3->addComponent<indie::ecs::component::Inventory>();
        entityP3->addComponent<indie::ecs::component::Collide>();
        entityP3->addComponent<indie::ecs::component::Alive>(true);
        addEntity(std::move(entityP3));
        _player3_green = true;
    }
    if (args[0] == "4" && this->_players->at(3).getIsAlive() == true) {
        std::unique_ptr<indie::ecs::entity::Entity> entityP4 =
            std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_4);
        entityP4->addComponent<indie::ecs::component::Transform>(static_cast<float>(std::stof(args[1])),
            static_cast<float>(std::stof(args[2])), static_cast<float>(0.0), static_cast<float>(0.0));
        entityP4->addComponent<indie::ecs::component::Object>("./assets/player/textures/yellow.png",
            "./assets/player/player.iqm", "./assets/player/player.iqm", scalePlayerVec, rotationPlayerVec,
            static_cast<float>(ecs::component::Object::NORTH));
        entityP4->addComponent<indie::ecs::component::Destroyable>();
        entityP4->addComponent<indie::ecs::component::Inventory>();
        entityP4->addComponent<indie::ecs::component::Collide>();
        entityP4->addComponent<indie::ecs::component::Alive>(true);
        addEntity(std::move(entityP4));
        _player4_yellow = true;
    }
    if (args[0] == "B") {
        std::unique_ptr<indie::ecs::entity::Entity> entityB =
            std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
        entityB->addComponent<indie::ecs::component::Transform>(static_cast<float>(std::stof(args[1])),
            static_cast<float>(std::stof(args[2])), static_cast<float>(0.0), static_cast<float>(0.0));
        vec3f scale({1.0f, 1.0f, 1.0f});
        vec3f rotation({0.0f, 1.0f, 0.0f});

        entityB->addComponent<indie::ecs::component::Object>(
            "assets/objects/Charger/charger.png", "assets/objects/Charger/charger.obj", scale, rotation, 90.0f);
        entityB->addComponent<indie::ecs::component::Collectable>(indie::ecs::component::BOMBUP);
        entityB->addComponent<indie::ecs::component::Collide>();
        addEntity(std::move(entityB));
    }
    if (args[0] == "S") {
        std::unique_ptr<indie::ecs::entity::Entity> entityS =
            std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
        entityS->addComponent<indie::ecs::component::Transform>(static_cast<float>(std::stof(args[1])),
            static_cast<float>(std::stof(args[2])), static_cast<float>(0.0), static_cast<float>(0.0));
        vec3f scale({1.0f, 1.0f, 1.0f});
        vec3f rotation({0.0f, 1.0f, 0.0f});

        entityS->addComponent<indie::ecs::component::Object>(
            "assets/objects/Boot/boot.png", "assets/objects/Boot/boot.obj", scale, rotation, 90.0f);
        entityS->addComponent<indie::ecs::component::Collectable>(indie::ecs::component::SPEEDUP);
        entityS->addComponent<indie::ecs::component::Collide>();
        addEntity(std::move(entityS));
    }
    if (args[0] == "R") {
        std::unique_ptr<indie::ecs::entity::Entity> entityR =
            std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
        entityR->addComponent<indie::ecs::component::Transform>(static_cast<float>(std::stof(args[1])),
            static_cast<float>(std::stof(args[2])), static_cast<float>(0.0), static_cast<float>(0.0));
        vec3f scale({1.0f, 1.0f, 1.0f});
        vec3f rotation({0.0f, 0.0f, 1.0f});

        entityR->addComponent<indie::ecs::component::Object>(
            "assets/objects/Tnt/tnt.png", "assets/objects/Tnt/tnt.obj", scale, rotation, 90.0f);
        entityR->addComponent<indie::ecs::component::Collectable>(indie::ecs::component::bonusType::FIREUP);
        entityR->addComponent<indie::ecs::component::Collide>();
        addEntity(std::move(entityR));
    }
    if (args[0][0] == 'P') {
        Color color;

        switch (args[0][1]) {
            case '0': color = BLUEPLAYERCOLOR; break;
            case '1': color = REDPLAYERCOLOR; break;
            case '2': color = GREENPLAYERCOLOR; break;
            case '3': color = YELLOWPLAYERCOLOR; break;
            default: BLUEPLAYERCOLOR; break;
        }
        _players->push_back(player::Player(color, std::stoi(args[1]), std::stoi(args[2]), std::stoi(args[3]),
            std::stoi(args[4]), std::stoi(args[5]), std::stoi(args[6]), std::stoi(args[7])));
    }
}

int indie::menu::GameScreen::countAlivePlayers()
{
    int count = 0;
    if (_player1_blue) {
        if (this->_players->at(0).getIsAlive())
            count++;
    }
    if (_player2_red) {
        if (this->_players->at(1).getIsAlive())
            count++;
    }
    if (_player3_green) {
        if (this->_players->at(2).getIsAlive())
            count++;
    }
    if (_player4_yellow) {
        if (this->_players->at(3).getIsAlive())
            count++;
    }
    return count;
}

int indie::menu::GameScreen::getWinner()
{
    if (_player1_blue) {
        if (this->_players->at(0).getIsAlive())
            return 0;
    }
    if (_player2_red) {
        if (this->_players->at(1).getIsAlive())
            return 1;
    }
    if (_player3_green) {
        if (this->_players->at(2).getIsAlive())
            return 2;
    }
    if (_player4_yellow) {
        if (this->_players->at(3).getIsAlive())
            return 3;
    }
    return 0;
}

void indie::menu::GameScreen::endScreenDisplay()
{
    std::unique_ptr<ecs::entity::Entity> frame = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    frame->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(20.f, true), tools::Tools::getPercentage(10.f, false), 0.0f, 0.0f);
    frame->addComponent<ecs::component::Drawable2D>("assets/menu/frame.png", tools::Tools::getPercentage(75.f, false),
        tools::Tools::getPercentage(60.f, true), WHITE);
    addEntity(std::move(frame));
    std::unique_ptr<ecs::entity::Entity> winner_is = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    winner_is->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(30.f, true), tools::Tools::getPercentage(20.f, false), 0.0f, 0.0f);
    winner_is->addComponent<ecs::component::Drawable2D>(
        "The Winner is", tools::Tools::getPercentage(10.f, false), YELLOW);
    addEntity(std::move(winner_is));
    std::unique_ptr<ecs::entity::Entity> return_to_menu =
        std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    return_to_menu->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(28.f, true), tools::Tools::getPercentage(70.f, false), 0.0f, 0.0f);
    return_to_menu->addComponent<ecs::component::Drawable2D>(
        "Press Triangle to go back to the menu", tools::Tools::getPercentage(4.f, false), WHITE);
    addEntity(std::move(return_to_menu));
    std::unique_ptr<ecs::entity::Entity> winner = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    winner->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(35.f, false), 0.0f, 0.0f);
    winner->addComponent<ecs::component::Drawable2D>(_playerAssets[getWinner()],
        tools::Tools::getPercentage(30.f, false), tools::Tools::getPercentage(30.f, false), WHITE);
    addEntity(std::move(winner));
}
