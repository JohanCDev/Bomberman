/**
 * @file SetFpsScreen.cpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen to change FPS of the game
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "SetFpsScreen.hpp"
#include "../../raylib/Raylib.hpp"
#include "../../tools/Tools.hpp"

indie::menu::SetFpsScreen::SetFpsScreen() : _cursorPosition(FPS_30), _lastSeenCursorPos(2)
{
}

void indie::menu::SetFpsScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> background = std::make_unique<ecs::entity::Entity>();
    background->addComponent<ecs::component::Transform>(0.0f, 0.0f, 0.0f, 0.0f);
    background->addComponent<ecs::component::Drawable2D>("assets/menu/bg.png",
        tools::Tools::getPercentage(100.f, false), tools::Tools::getPercentage(100.f, true), WHITE);
    addEntity(std::move(background));

    std::unique_ptr<ecs::entity::Entity> frame = std::make_unique<ecs::entity::Entity>();
    frame->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(20.f, true), tools::Tools::getPercentage(2.5f, false), 0.0f, 0.0f);
    frame->addComponent<ecs::component::Drawable2D>("assets/menu/frame.png", tools::Tools::getPercentage(95.f, false),
        tools::Tools::getPercentage(60.f, true), WHITE);
    addEntity(std::move(frame));

    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>();
    cursor->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(36.f, true), tools::Tools::getPercentage(29.f, false), 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("assets/menu/hand.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(6.f, true), WHITE);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
    quit->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(43.5f, true), tools::Tools::getPercentage(80.f, false), 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>("Press O to quit !", tools::Tools::getPercentage(4.f, false), WHITE);
    addEntity(std::move(quit));

    std::unique_ptr<ecs::entity::Entity> fps30 = std::make_unique<ecs::entity::Entity>();
    fps30->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(50.f, true), tools::Tools::getPercentage(19.5f, false), 0.0f, 0.0f);
    fps30->addComponent<ecs::component::Drawable2D>("assets/menu/30fps.png", tools::Tools::getPercentage(20.f, false),
        tools::Tools::getPercentage(25.f, false), WHITE);
    addEntity(std::move(fps30));

    std::unique_ptr<ecs::entity::Entity> not_valid30 = std::make_unique<ecs::entity::Entity>();
    not_valid30->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(26.f, false), 0.0f, 0.0f);
    not_valid30->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png",
        tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
    addEntity(std::move(not_valid30));

    std::unique_ptr<ecs::entity::Entity> fps60 = std::make_unique<ecs::entity::Entity>();
    fps60->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(50.f, true), tools::Tools::getPercentage(45.f, false), 0.0f, 0.0f);
    fps60->addComponent<ecs::component::Drawable2D>("assets/menu/60fps.png", tools::Tools::getPercentage(20.f, false),
        tools::Tools::getPercentage(25.f, false), WHITE);
    addEntity(std::move(fps60));

    std::unique_ptr<ecs::entity::Entity> not_valid60 = std::make_unique<ecs::entity::Entity>();
    not_valid60->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(51.f, false), 0.0f, 0.0f);
    not_valid60->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png",
        tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
    addEntity(std::move(not_valid60));

    std::unique_ptr<ecs::entity::Entity> valid60 = std::make_unique<ecs::entity::Entity>();
    valid60->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(51.f, false), 0.0f, 0.0f);
    valid60->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(10.f, false), WHITE);
    addEntity(std::move(valid60));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemOption =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemOption));
    this->_cursorPosition = FPS_60;

    this->_positionsCursor[FPS_30] = tools::Tools::getPercentage(29.f, false);
    this->_positionsCursor[FPS_60] = tools::Tools::getPercentage(54.f, false);
}

void indie::menu::SetFpsScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::SetFpsScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].code == indie::Event::ControllerCode::DOWN_BUTTON || event.key.down) {
        indie::ecs::component::Transform *transformCompo =
            _entities.at(2)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(tools::Tools::getPercentage(38.f, true), checkCursorPosition(true), 0.0f, 0.0f);
    }
    if (event.controller[0].code == indie::Event::ControllerCode::UP_BUTTON || event.key.up) {
        ecs::component::Transform *transformCompo =
            _entities.at(2)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(tools::Tools::getPercentage(38.f, true), checkCursorPosition(false), 0.0f, 0.0f);
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == FPS_30) {
        indie::raylib::Window::setTargetFPS(30);
        if (_entities.size() == 9)
            _entities.erase(_entities.begin() + 8);
        std::unique_ptr<ecs::entity::Entity> valid30 = std::make_unique<ecs::entity::Entity>();
        valid30->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(26.f, false), 0.0f, 0.0f);
        valid30->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png",
            tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
        addEntity(std::move(valid30));
        _lastSeenCursorPos = 1;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == FPS_60) {
        indie::raylib::Window::setTargetFPS(60);
        if (_entities.size() == 9)
            _entities.erase(_entities.begin() + 8);
        std::unique_ptr<ecs::entity::Entity> valid60 = std::make_unique<ecs::entity::Entity>();
        valid60->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(51.f, false), 0.0f, 0.0f);
        valid60->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png",
            tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
        addEntity(std::move(valid60));
        _lastSeenCursorPos = 2;
    }
    if (event.controller[0].code == indie::Event::ControllerCode::O_BUTTON)
        return 4;
    return 0;
}

void indie::menu::SetFpsScreen::update()
{
    ecs::component::Drawable2D *bgDrawableCompo =
        this->_entities[0]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Drawable2D *frameDrawableCompo =
        this->_entities[1]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *frameTransCompo =
        this->_entities[1]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *cursDrawableCompo =
        this->_entities[2]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *cursTransCompo =
        this->_entities[2]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *quitDrawableCompo =
        this->_entities[3]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *quitTransCompo =
        this->_entities[3]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *fps30DrawableCompo =
        this->_entities[4]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *fps30TransCompo =
        this->_entities[4]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *notvalid30DrawableCompo =
        this->_entities[5]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *notvalid30TransCompo =
        this->_entities[5]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *fps60DrawableCompo =
        this->_entities[6]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *fps60TransCompo =
        this->_entities[6]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *notvalid60DrawableCompo =
        this->_entities[7]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *notvalid60TransCompo =
        this->_entities[7]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);

    bgDrawableCompo->setHeight(tools::Tools::getPercentage(100.f, false));
    bgDrawableCompo->setWidth(tools::Tools::getPercentage(100.f, true));
    frameTransCompo->setX(tools::Tools::getPercentage(20.f, true));
    frameTransCompo->setY(tools::Tools::getPercentage(2.5f, false));
    frameDrawableCompo->setHeight(tools::Tools::getPercentage(95.f, false));
    frameDrawableCompo->setWidth(tools::Tools::getPercentage(60.f, true));
    cursTransCompo->setX(tools::Tools::getPercentage(38.f, true));
    cursTransCompo->setY(this->_positionsCursor[this->_cursorPosition]);
    cursDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    cursDrawableCompo->setWidth(tools::Tools::getPercentage(6.f, true));
    quitTransCompo->setX(tools::Tools::getPercentage(43.5f, true));
    quitTransCompo->setY(tools::Tools::getPercentage(80.f, false));
    quitDrawableCompo->setHeight(tools::Tools::getPercentage(4.f, false));
    fps30TransCompo->setX(tools::Tools::getPercentage(50.f, true));
    fps30TransCompo->setY(tools::Tools::getPercentage(19.5f, false));
    fps30DrawableCompo->setHeight(tools::Tools::getPercentage(20.f, false));
    fps30DrawableCompo->setWidth(tools::Tools::getPercentage(25.f, false));
    notvalid30TransCompo->setX(tools::Tools::getPercentage(44.f, true));
    notvalid30TransCompo->setY(tools::Tools::getPercentage(26.f, false));
    notvalid30DrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    notvalid30DrawableCompo->setWidth(tools::Tools::getPercentage(10.f, false));
    fps60TransCompo->setX(tools::Tools::getPercentage(50.f, true));
    fps60TransCompo->setY(tools::Tools::getPercentage(45.5f, false));
    fps60DrawableCompo->setHeight(tools::Tools::getPercentage(20.f, false));
    fps60DrawableCompo->setWidth(tools::Tools::getPercentage(25.f, false));
    notvalid60TransCompo->setX(tools::Tools::getPercentage(44.f, true));
    notvalid60TransCompo->setY(tools::Tools::getPercentage(51.f, false));
    notvalid60DrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    notvalid60DrawableCompo->setWidth(tools::Tools::getPercentage(10.f, false));

    ecs::component::Drawable2D *validDrawableCompo =
        this->_entities[8]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *validTransCompo =
        this->_entities[8]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    validTransCompo->setX(tools::Tools::getPercentage(44.f, true));
    validTransCompo->setY(tools::Tools::getPercentage(26.f + ((_lastSeenCursorPos - 1) * 25), false));
    validDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    validDrawableCompo->setWidth(tools::Tools::getPercentage(10.f, false));

    this->_positionsCursor[FPS_30] = tools::Tools::getPercentage(29.f, false);
    this->_positionsCursor[FPS_60] = tools::Tools::getPercentage(54.f, false);
}

void indie::menu::SetFpsScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::SetFpsScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

int indie::menu::SetFpsScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == FPS_30) {
            _cursorPosition = FPS_60;
            return this->_positionsCursor[FPS_60];
        }
        if (_cursorPosition == FPS_60) {
            return this->_positionsCursor[FPS_60];
        }
    } else if (!direction) {
        if (_cursorPosition == FPS_30)
            return this->_positionsCursor[FPS_30];
        if (_cursorPosition == FPS_60) {
            _cursorPosition = FPS_30;
            return this->_positionsCursor[FPS_30];
        }
    }
    return 0;
}
