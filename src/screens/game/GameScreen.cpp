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
    : _camera({0.0, 10.0, 7.0}, {0.0, -1.5, 0.0}, {0.0, 1.0, 0.0}, 50.0, CAMERA_PERSPECTIVE), _player1_blue(false),
      _player2_red(false), _player3_green(false), _player4_yellow(false)
{
}

void indie::menu::GameScreen::init()
{
    std::unique_ptr<indie::ecs::entity::Entity> entity = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystem = std::make_unique<indie::ecs::system::Draw2DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> draw3DSystem = std::make_unique<indie::ecs::system::Draw3DSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> movementSystem =
        std::make_unique<indie::ecs::system::MovementSystem>();
    std::unique_ptr<indie::ecs::system::ISystem> soundSystem = std::make_unique<indie::ecs::system::Sound>();
    std::unique_ptr<indie::ecs::system::ISystem> collideSystem = std::make_unique<indie::ecs::system::Collide>();
    std::unique_ptr<indie::ecs::entity::Entity> entityX = std::make_unique<indie::ecs::entity::Entity>();
    std::unique_ptr<indie::ecs::system::Explodable> explodeSystem = std::make_unique<indie::ecs::system::Explodable>();

    entityX->addComponent<indie::ecs::component::Transform>(
        static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0), static_cast<float>(0.0));
    entityX->addComponent<indie::ecs::component::Drawable3D>(
        "", static_cast<float>(10.5), static_cast<float>(0.05), static_cast<float>(10), LIGHTGRAY);
    entityX->getComponent<indie::ecs::component::Transform>(indie::ecs::component::compoType::TRANSFORM)->setZ(-0.25);
    this->initEntity();
    this->addEntity(std::move(entityX));
    this->addSystem(std::move(draw2DSystem));
    this->addSystem(std::move(draw3DSystem));
    this->addSystem(std::move(movementSystem));
    this->addSystem(std::move(soundSystem));
    this->addSystem(std::move(collideSystem));
    this->addSystem(std::move(explodeSystem));
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
    for (auto &entity : _entities) {
        if (entity->hasCompoType(indie::ecs::component::COLLIDE) == true) {
            entity->getComponent<indie::ecs::component::Collide>(indie::ecs::component::compoType::COLLIDE)
                ->setCollide(false);
        }
    }
}

void indie::menu::GameScreen::update()
{
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
    player::Player player1(BLUEPLAYERCOLOR, 0, {0, 0});
    player::Player player2(REDPLAYERCOLOR, 1, {0, 0});
    player::Player player3(YELLOWPLAYERCOLOR, 2, {0, 0});
    player::Player player4(GREENPLAYERCOLOR, 3, {0, 0});
    vec2f uiSize = vec2f({150.f, 200.f});
    vec2f topLeftPos = vec2f({40.f, 40.f});
    vec2f topRightPos = vec2f({1512.f - 225.f, 40.f});
    vec2f bottomLeftPos = vec2f({40.f, 982.f - 175.f});
    vec2f bottomRightPos = vec2f({1512.f - 225.f, 982.f - 175.f});

    if (_player1_blue == true)
        this->_infoPlayers.push_back(
            std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(player1, topLeftPos, uiSize));
    if (_player2_red == true)
        this->_infoPlayers.push_back(
            std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(player2, topRightPos, uiSize));
    if (_player3_green == true)
        this->_infoPlayers.push_back(
            std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(player3, bottomLeftPos, uiSize));
    if (_player4_yellow == true)
        this->_infoPlayers.push_back(
            std::make_unique<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>(player4, bottomRightPos, uiSize));
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

int indie::menu::GameScreen::handleEvent(indie::Event &event)
{
    handleMultipleController(event, 0, indie::ecs::entity::entityType::PLAYER_1);
    handleMultipleController(event, 1, indie::ecs::entity::entityType::PLAYER_2);
    handleMultipleController(event, 2, indie::ecs::entity::entityType::PLAYER_3);
    handleMultipleController(event, 3, indie::ecs::entity::entityType::PLAYER_4);
    if (event.controller[0].code == indie::Event::ControllerCode::OPTION_BUTTON || event.key.r_shift)
        return 4;
    return 0;
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
                entityA->addComponent<indie::ecs::component::Destroyable>();
                entityA->addComponent<indie::ecs::component::Drawable3D>(
                    "src/boite.png", static_cast<float>(0.5), static_cast<float>(0.5), static_cast<float>(0.5), WHITE);
                addEntity(std::move(entityA));
            }
            if (map[i][j] == '1') {
                if (_player1_blue == true) {
                    std::unique_ptr<indie::ecs::entity::Entity> entityP1 =
                        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_1);
                    entityP1->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                        static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                    entityP1->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.2), BLUE);
                    entityP1->addComponent<indie::ecs::component::Collide>();
                    addEntity(std::move(entityP1));
                }
            }
            if (map[i][j] == '2') {
                if (_player2_red == true) {
                    std::unique_ptr<indie::ecs::entity::Entity> entityP2 =
                        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_2);
                    entityP2->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                        static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                    entityP2->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.2), RED);
                    entityP2->addComponent<indie::ecs::component::Collide>();
                    addEntity(std::move(entityP2));
                }
            }
            if (map[i][j] == '3') {
                if (_player3_green == true) {
                    std::unique_ptr<indie::ecs::entity::Entity> entityP3 =
                        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_3);
                    entityP3->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                        static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                    entityP3->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.2), GREEN);
                    entityP3->addComponent<indie::ecs::component::Collide>();
                    addEntity(std::move(entityP3));
                }
            }
            if (map[i][j] == '4') {
                if (_player4_yellow == true) {
                    std::unique_ptr<indie::ecs::entity::Entity> entityP4 =
                        std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::PLAYER_4);
                    entityP4->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                        static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                    entityP4->addComponent<indie::ecs::component::Drawable3D>(static_cast<float>(0.2), YELLOW);
                    entityP4->addComponent<indie::ecs::component::Collide>();
                    addEntity(std::move(entityP4));
                }
            }
            if (map[i][j] == 'B') {
                std::unique_ptr<indie::ecs::entity::Entity> entityB = std::make_unique<indie::ecs::entity::Entity>();
                entityB->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityB->addComponent<indie::ecs::component::Drawable3D>(
                    "", static_cast<float>(0.25), static_cast<float>(0.25), static_cast<float>(0.25), RED);
                entityB->addComponent<indie::ecs::component::Collectable>();
                addEntity(std::move(entityB));
                std::unique_ptr<indie::ecs::entity::Entity> entityB2 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::BOXES);
                entityB2->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityB2->addComponent<indie::ecs::component::Collide>();
                entityB2->addComponent<indie::ecs::component::Destroyable>();
                entityB2->addComponent<indie::ecs::component::Drawable3D>(
                    "src/boite.png", static_cast<float>(0.5), static_cast<float>(0.5), static_cast<float>(0.5), WHITE);
                addEntity(std::move(entityB2));
            }
            if (map[i][j] == 'T') {
                std::unique_ptr<indie::ecs::entity::Entity> entityT = std::make_unique<indie::ecs::entity::Entity>();
                entityT->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityT->addComponent<indie::ecs::component::Drawable3D>(
                    "", static_cast<float>(0.25), static_cast<float>(0.25), static_cast<float>(0.25), MAGENTA);
                entityT->addComponent<indie::ecs::component::Collectable>();
                addEntity(std::move(entityT));
                std::unique_ptr<indie::ecs::entity::Entity> entityT2 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::BOXES);
                entityT2->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityT2->addComponent<indie::ecs::component::Collide>();
                entityT2->addComponent<indie::ecs::component::Destroyable>();
                entityT2->addComponent<indie::ecs::component::Drawable3D>(
                    "src/boite.png", static_cast<float>(0.5), static_cast<float>(0.5), static_cast<float>(0.5), WHITE);
                addEntity(std::move(entityT2));
            }
            if (map[i][j] == 'S') {
                std::unique_ptr<indie::ecs::entity::Entity> entityS = std::make_unique<indie::ecs::entity::Entity>();
                entityS->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityS->addComponent<indie::ecs::component::Drawable3D>(
                    "", static_cast<float>(0.25), static_cast<float>(0.25), static_cast<float>(0.25), YELLOW);
                entityS->addComponent<indie::ecs::component::Collectable>();
                addEntity(std::move(entityS));
                std::unique_ptr<indie::ecs::entity::Entity> entityS2 =
                    std::make_unique<indie::ecs::entity::Entity>(indie::ecs::entity::BOXES);
                entityS2->addComponent<indie::ecs::component::Transform>(static_cast<float>(posX),
                    static_cast<float>(posY), static_cast<float>(0.0), static_cast<float>(0.0));
                entityS2->addComponent<indie::ecs::component::Collide>();
                entityS2->addComponent<indie::ecs::component::Destroyable>();
                entityS2->addComponent<indie::ecs::component::Drawable3D>(
                    "src/boite.png", static_cast<float>(0.5), static_cast<float>(0.5), static_cast<float>(0.5), WHITE);
                addEntity(std::move(entityS2));
            }
            posX += 0.5;
        }
        posY -= 0.5;
        posX = -5;
    }
}
