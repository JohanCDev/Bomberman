/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** MenuScreen.cpp
*/

#include "MenuScreen.hpp"
#include "../../raylib/Raylib.hpp"
#include "../../tools/Tools.hpp"

indie::menu::MenuScreen::MenuScreen() : _cursorPosition(NEW_GAME)
{
}

void indie::menu::MenuScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> background = std::make_unique<ecs::entity::Entity>();
    background->addComponent<ecs::component::Transform>(0.0f, 0.0f, 0.0f, 0.0f);
    background->addComponent<ecs::component::Drawable2D>("assets/menu/bg.png",
        tools::Tools::getPercentage(100.f, false), tools::Tools::getPercentage(100.f, true), WHITE);
    addEntity(std::move(background));

    std::unique_ptr<ecs::entity::Entity> frame = std::make_unique<ecs::entity::Entity>();
    frame->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(20.f, true), tools::Tools::getPercentage(10.f, false), 0.0f, 0.0f);
    frame->addComponent<ecs::component::Drawable2D>("assets/menu/frame.png", tools::Tools::getPercentage(80.f, false),
        tools::Tools::getPercentage(60.f, true), WHITE);
    addEntity(std::move(frame));

    std::unique_ptr<ecs::entity::Entity> left_character = std::make_unique<ecs::entity::Entity>();
    left_character->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(5.f, true), tools::Tools::getPercentage(20.f, false), 0.0f, 0.0f);
    left_character->addComponent<ecs::component::Drawable2D>("assets/menu/character_right.png",
        tools::Tools::getPercentage(60.f, false), tools::Tools::getPercentage(30.f, true), WHITE);
    addEntity(std::move(left_character));

    std::unique_ptr<ecs::entity::Entity> right_character = std::make_unique<ecs::entity::Entity>();
    right_character->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(65.f, true), tools::Tools::getPercentage(20.f, false), 0.0f, 0.0f);
    right_character->addComponent<ecs::component::Drawable2D>("assets/menu/character_left.png",
        tools::Tools::getPercentage(60.f, false), tools::Tools::getPercentage(30.f, true), WHITE);
    addEntity(std::move(right_character));

    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(33.f, true), tools::Tools::getPercentage(27.f, false), 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>(
        "assets/menu/hand.png", tools::Tools::getPercentage(6.f, false), tools::Tools::getPercentage(6.f, true), WHITE);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> new_game = std::make_unique<ecs::entity::Entity>();
    new_game->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(25.f, false), 0.0f, 0.0f);
    new_game->addComponent<ecs::component::Drawable2D>("assets/menu/new_game.png",
        tools::Tools::getPercentage(11.f, false), tools::Tools::getPercentage(19.f, true), WHITE);
    addEntity(std::move(new_game));

    std::unique_ptr<ecs::entity::Entity> load_game = std::make_unique<ecs::entity::Entity>();
    load_game->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(45.f, false), 0.0f, 0.0f);
    load_game->addComponent<ecs::component::Drawable2D>("assets/menu/load.png",
        tools::Tools::getPercentage(11.f, false), tools::Tools::getPercentage(19.f, true), WHITE);
    addEntity(std::move(load_game));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
    quit->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(65.f, false), 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>("assets/menu/quit.png", tools::Tools::getPercentage(11.f, false),
        tools::Tools::getPercentage(19.f, true), WHITE);
    addEntity(std::move(quit));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemMenu =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemMenu));

    this->_positionsCursor[NEW_GAME] = tools::Tools::getPercentage(27.f, false);
    this->_positionsCursor[LOAD_GAME] = tools::Tools::getPercentage(47.f, false);
    this->_positionsCursor[EXIT] = tools::Tools::getPercentage(67.f, false);
}

void indie::menu::MenuScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::MenuScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::DOWN || event.key.down) {
        ecs::component::Transform *transformCompo =
            _entities.at(4)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(tools::Tools::getPercentage(33.f, true), checkCursorPosition(true), 0.0f, 0.0f);
    }
    if (event.controller[0].leftJoystick == indie::Event::JoystickDirection::UP || event.key.up) {
        ecs::component::Transform *transformCompo =
            _entities.at(4)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(tools::Tools::getPercentage(33.f, true), checkCursorPosition(false), 0.0f, 0.0f);
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == NEW_GAME)
        return 3;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == EXIT)
        return 10;
    if (_cursorPosition == NEW_GAME) {
        ecs::component::Drawable2D *drawableCompo1 =
            _entities.at(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        drawableCompo1->setHeight(tools::Tools::getPercentage(13.f, false));
        drawableCompo1->setWidth(tools::Tools::getPercentage(21.f, true));
        ecs::component::Drawable2D *drawableCompo2 =
            _entities.at(6)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        drawableCompo2->setHeight(tools::Tools::getPercentage(11.f, false));
        drawableCompo2->setWidth(tools::Tools::getPercentage(19.f, true));
    }
    if (_cursorPosition == LOAD_GAME) {
        ecs::component::Drawable2D *drawableCompo1 =
            _entities.at(5)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        drawableCompo1->setHeight(tools::Tools::getPercentage(11.f, false));
        drawableCompo1->setWidth(tools::Tools::getPercentage(19.f, true));
        ecs::component::Drawable2D *drawableCompo2 =
            _entities.at(6)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        drawableCompo2->setHeight(tools::Tools::getPercentage(13.f, false));
        drawableCompo2->setWidth(tools::Tools::getPercentage(21.f, true));
        ecs::component::Drawable2D *drawableCompo3 =
            _entities.at(7)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        drawableCompo3->setHeight(tools::Tools::getPercentage(11.f, false));
        drawableCompo3->setWidth(tools::Tools::getPercentage(19.f, true));
    }
    if (_cursorPosition == EXIT) {
        ecs::component::Drawable2D *drawableCompo2 =
            _entities.at(6)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        drawableCompo2->setHeight(tools::Tools::getPercentage(11.f, false));
        drawableCompo2->setWidth(tools::Tools::getPercentage(19.f, true));
        ecs::component::Drawable2D *drawableCompo3 =
            _entities.at(7)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
        drawableCompo3->setHeight(tools::Tools::getPercentage(13.f, false));
        drawableCompo3->setWidth(tools::Tools::getPercentage(21.f, true));
        return 0;
    }
    return 0;
}

void indie::menu::MenuScreen::update()
{
}

void indie::menu::MenuScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

int indie::menu::MenuScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == NEW_GAME) {
            _cursorPosition = LOAD_GAME;
            return this->_positionsCursor[LOAD_GAME];
        }
        if (_cursorPosition == LOAD_GAME) {
            _cursorPosition = EXIT;
            return this->_positionsCursor[EXIT];
        }
        if (_cursorPosition == EXIT)
            return this->_positionsCursor[EXIT];
    } else if (!direction) {
        if (_cursorPosition == NEW_GAME)
            return this->_positionsCursor[NEW_GAME];
        if (_cursorPosition == LOAD_GAME) {
            _cursorPosition = NEW_GAME;
            return this->_positionsCursor[NEW_GAME];
        }
        if (_cursorPosition == EXIT) {
            _cursorPosition = LOAD_GAME;
            return this->_positionsCursor[LOAD_GAME];
        }
    }
    return 0;
}

void indie::menu::MenuScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}
