/**
 * @file SetSoundScreen.cpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen to change the volume of the sounds of the game
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "SetSoundScreen.hpp"
#include "../../raylib/Raylib.hpp"
#include "../../tools/Tools.hpp"

indie::menu::SetSoundScreen::SetSoundScreen(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> *sounds)
    : _cursorPosition(SOUND_50), _lastSeenCursorPos(5)
{
    _sounds = sounds;
}

void indie::menu::SetSoundScreen::init()
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
        tools::Tools::getPercentage(38.f, true), tools::Tools::getPercentage(74.f, false), 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("assets/menu/hand.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(6.f, true), WHITE);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
    quit->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(41.5f, true), tools::Tools::getPercentage(88.f, false), 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>("Press O to quit !", tools::Tools::getPercentage(4.f, false), WHITE);
    addEntity(std::move(quit));

    std::unique_ptr<ecs::entity::Entity> sound_0 = std::make_unique<ecs::entity::Entity>();
    sound_0->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(50.f, true), tools::Tools::getPercentage(4.f, false), 0.0f, 0.0f);
    sound_0->addComponent<ecs::component::Drawable2D>("assets/menu/0%.png", tools::Tools::getPercentage(20.f, false),
        tools::Tools::getPercentage(25.f, false), WHITE);
    addEntity(std::move(sound_0));

    std::unique_ptr<ecs::entity::Entity> not_valid0 = std::make_unique<ecs::entity::Entity>();
    not_valid0->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(11.f, false), 0.0f, 0.0f);
    not_valid0->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png",
        tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
    addEntity(std::move(not_valid0));

    std::unique_ptr<ecs::entity::Entity> sound_25 = std::make_unique<ecs::entity::Entity>();
    sound_25->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(50.f, true), tools::Tools::getPercentage(19.f, false), 0.0f, 0.0f);
    sound_25->addComponent<ecs::component::Drawable2D>("assets/menu/25%.png", tools::Tools::getPercentage(20.f, false),
        tools::Tools::getPercentage(25.f, false), WHITE);
    addEntity(std::move(sound_25));

    std::unique_ptr<ecs::entity::Entity> not_valid25 = std::make_unique<ecs::entity::Entity>();
    not_valid25->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(26.f, false), 0.0f, 0.0f);
    not_valid25->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png",
        tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
    addEntity(std::move(not_valid25));

    std::unique_ptr<ecs::entity::Entity> sound_50 = std::make_unique<ecs::entity::Entity>();
    sound_50->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(50.f, true), tools::Tools::getPercentage(34.f, false), 0.0f, 0.0f);
    sound_50->addComponent<ecs::component::Drawable2D>("assets/menu/50%.png", tools::Tools::getPercentage(20.f, false),
        tools::Tools::getPercentage(25.f, false), WHITE);
    addEntity(std::move(sound_50));

    std::unique_ptr<ecs::entity::Entity> not_valid50 = std::make_unique<ecs::entity::Entity>();
    not_valid50->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(41.f, false), 0.0f, 0.0f);
    not_valid50->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png",
        tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
    addEntity(std::move(not_valid50));

    std::unique_ptr<ecs::entity::Entity> sound_75 = std::make_unique<ecs::entity::Entity>();
    sound_75->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(50.f, true), tools::Tools::getPercentage(49.f, false), 0.0f, 0.0f);
    sound_75->addComponent<ecs::component::Drawable2D>("assets/menu/75%.png", tools::Tools::getPercentage(20.f, false),
        tools::Tools::getPercentage(25.f, false), WHITE);
    addEntity(std::move(sound_75));

    std::unique_ptr<ecs::entity::Entity> not_valid75 = std::make_unique<ecs::entity::Entity>();
    not_valid75->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(56.f, false), 0.0f, 0.0f);
    not_valid75->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png",
        tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
    addEntity(std::move(not_valid75));

    std::unique_ptr<ecs::entity::Entity> sound_100 = std::make_unique<ecs::entity::Entity>();
    sound_100->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(50.f, true), tools::Tools::getPercentage(64.f, false), 0.0f, 0.0f);
    sound_100->addComponent<ecs::component::Drawable2D>("assets/menu/100%.png",
        tools::Tools::getPercentage(20.f, false), tools::Tools::getPercentage(25.f, false), WHITE);
    addEntity(std::move(sound_100));

    std::unique_ptr<ecs::entity::Entity> not_valid100 = std::make_unique<ecs::entity::Entity>();
    not_valid100->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(71.f, false), 0.0f, 0.0f);
    not_valid100->addComponent<ecs::component::Drawable2D>("assets/menu/not_valid.png",
        tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
    addEntity(std::move(not_valid100));

    std::unique_ptr<ecs::entity::Entity> valid100 = std::make_unique<ecs::entity::Entity>();
    valid100->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(71.f, false), 0.0f, 0.0f);
    valid100->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png",
        tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
    addEntity(std::move(valid100));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemOption =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemOption));
    this->_cursorPosition = SOUND_100;
    this->_positionsCursor[SOUND_0] = tools::Tools::getPercentage(13.f, false);
    this->_positionsCursor[SOUND_25] = tools::Tools::getPercentage(29.f, false);
    this->_positionsCursor[SOUND_50] = tools::Tools::getPercentage(44.f, false);
    this->_positionsCursor[SOUND_75] = tools::Tools::getPercentage(59.f, false);
    this->_positionsCursor[SOUND_100] = tools::Tools::getPercentage(74.f, false);
}

void indie::menu::SetSoundScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::SetSoundScreen::handleEvent(indie::Event &event)
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
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == SOUND_0) {
        setSounds(0.0f);
        if (_entities.size() == 15)
            _entities.erase(_entities.begin() + 14);
        std::unique_ptr<ecs::entity::Entity> valid0 = std::make_unique<ecs::entity::Entity>();
        valid0->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(11.f, false), 0.0f, 0.0f);
        valid0->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png",
            tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
        addEntity(std::move(valid0));
        _lastSeenCursorPos = 1;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == SOUND_25) {
        setSounds(0.25f);
        if (_entities.size() == 15)
            _entities.erase(_entities.begin() + 14);
        std::unique_ptr<ecs::entity::Entity> valid25 = std::make_unique<ecs::entity::Entity>();
        valid25->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(26.f, false), 0.0f, 0.0f);
        valid25->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png",
            tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
        addEntity(std::move(valid25));
        _lastSeenCursorPos = 2;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == SOUND_50) {
        setSounds(0.5f);
        if (_entities.size() == 15)
            _entities.erase(_entities.begin() + 14);
        std::unique_ptr<ecs::entity::Entity> valid50 = std::make_unique<ecs::entity::Entity>();
        valid50->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(41.f, false), 0.0f, 0.0f);
        valid50->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png",
            tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
        addEntity(std::move(valid50));
        _lastSeenCursorPos = 3;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == SOUND_75) {
        setSounds(0.75f);
        if (_entities.size() == 15)
            _entities.erase(_entities.begin() + 14);
        std::unique_ptr<ecs::entity::Entity> valid75 = std::make_unique<ecs::entity::Entity>();
        valid75->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(56.f, false), 0.0f, 0.0f);
        valid75->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png",
            tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
        addEntity(std::move(valid75));
        _lastSeenCursorPos = 4;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && _cursorPosition == SOUND_100) {
        setSounds(1.0f);
        if (_entities.size() == 15)
            _entities.erase(_entities.begin() + 14);
        std::unique_ptr<ecs::entity::Entity> valid100 = std::make_unique<ecs::entity::Entity>();
        valid100->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(44.f, true), tools::Tools::getPercentage(71.f, false), 0.0f, 0.0f);
        valid100->addComponent<ecs::component::Drawable2D>("assets/menu/valid.png",
            tools::Tools::getPercentage(10.f, false), tools::Tools::getPercentage(10.f, false), WHITE);
        addEntity(std::move(valid100));
        _lastSeenCursorPos = 5;
    }
    if (event.controller[0].code == indie::Event::ControllerCode::O_BUTTON)
        return 4;
    return 0;
}

void indie::menu::SetSoundScreen::setSounds(float volume)
{
    std::vector<std::unique_ptr<indie::ecs::entity::Entity>>::iterator _it_sounds = _sounds->begin();

    while (_it_sounds != _sounds->end()) {
        _it_sounds->get()->getComponent<ecs::component::Sound>(ecs::component::compoType::SOUND)->setVolume(volume);
        ++_it_sounds;
    }
}

void indie::menu::SetSoundScreen::update()
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
    ecs::component::Drawable2D *sound0DrawableCompo =
        this->_entities[4]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *sound0TransCompo =
        this->_entities[4]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *notvalid0DrawableCompo =
        this->_entities[5]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *notvalid0TransCompo =
        this->_entities[5]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *sound25DrawableCompo =
        this->_entities[6]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *sound25TransCompo =
        this->_entities[6]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *notvalid25DrawableCompo =
        this->_entities[7]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *notvalid25TransCompo =
        this->_entities[7]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *sound50DrawableCompo =
        this->_entities[8]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *sound50TransCompo =
        this->_entities[8]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *notvalid50DrawableCompo =
        this->_entities[9]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *notvalid50TransCompo =
        this->_entities[9]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *sound75DrawableCompo =
        this->_entities[10]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *sound75TransCompo =
        this->_entities[10]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *notvalid75DrawableCompo =
        this->_entities[11]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *notvalid75TransCompo =
        this->_entities[11]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *sound100DrawableCompo =
        this->_entities[12]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *sound100TransCompo =
        this->_entities[12]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *notvalid100DrawableCompo =
        this->_entities[13]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *notvalid100TransCompo =
        this->_entities[13]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);

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
    quitTransCompo->setX(tools::Tools::getPercentage(41.5f, true));
    quitTransCompo->setY(tools::Tools::getPercentage(88.f, false));
    quitDrawableCompo->setHeight(tools::Tools::getPercentage(4.f, false));
    sound0TransCompo->setX(tools::Tools::getPercentage(50.f, true));
    sound0TransCompo->setY(tools::Tools::getPercentage(4.f, false));
    sound0DrawableCompo->setHeight(tools::Tools::getPercentage(20.f, false));
    sound0DrawableCompo->setWidth(tools::Tools::getPercentage(25.f, false));
    notvalid0TransCompo->setX(tools::Tools::getPercentage(44.f, true));
    notvalid0TransCompo->setY(tools::Tools::getPercentage(11.f, false));
    notvalid0DrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    notvalid0DrawableCompo->setWidth(tools::Tools::getPercentage(10.f, false));
    sound25TransCompo->setX(tools::Tools::getPercentage(50.f, true));
    sound25TransCompo->setY(tools::Tools::getPercentage(19.f, false));
    sound25DrawableCompo->setHeight(tools::Tools::getPercentage(20.f, false));
    sound25DrawableCompo->setWidth(tools::Tools::getPercentage(25.f, false));
    notvalid25TransCompo->setX(tools::Tools::getPercentage(44.f, true));
    notvalid25TransCompo->setY(tools::Tools::getPercentage(26.f, false));
    notvalid25DrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    notvalid25DrawableCompo->setWidth(tools::Tools::getPercentage(10.f, false));
    sound50TransCompo->setX(tools::Tools::getPercentage(50.f, true));
    sound50TransCompo->setY(tools::Tools::getPercentage(34.f, false));
    sound50DrawableCompo->setHeight(tools::Tools::getPercentage(20.f, false));
    sound50DrawableCompo->setWidth(tools::Tools::getPercentage(25.f, false));
    notvalid50TransCompo->setX(tools::Tools::getPercentage(44.f, true));
    notvalid50TransCompo->setY(tools::Tools::getPercentage(41.f, false));
    notvalid50DrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    notvalid50DrawableCompo->setWidth(tools::Tools::getPercentage(10.f, false));
    sound75TransCompo->setX(tools::Tools::getPercentage(50.f, true));
    sound75TransCompo->setY(tools::Tools::getPercentage(49.f, false));
    sound75DrawableCompo->setHeight(tools::Tools::getPercentage(20.f, false));
    sound75DrawableCompo->setWidth(tools::Tools::getPercentage(25.f, false));
    notvalid75TransCompo->setX(tools::Tools::getPercentage(44.f, true));
    notvalid75TransCompo->setY(tools::Tools::getPercentage(56.f, false));
    notvalid75DrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    notvalid75DrawableCompo->setWidth(tools::Tools::getPercentage(10.f, false));
    sound100TransCompo->setX(tools::Tools::getPercentage(50.f, true));
    sound100TransCompo->setY(tools::Tools::getPercentage(64.f, false));
    sound100DrawableCompo->setHeight(tools::Tools::getPercentage(20.f, false));
    sound100DrawableCompo->setWidth(tools::Tools::getPercentage(25.f, false));
    notvalid100TransCompo->setX(tools::Tools::getPercentage(44.f, true));
    notvalid100TransCompo->setY(tools::Tools::getPercentage(71.f, false));
    notvalid100DrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    notvalid100DrawableCompo->setWidth(tools::Tools::getPercentage(10.f, false));
    ecs::component::Drawable2D *validDrawableCompo =
        this->_entities[14]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *validTransCompo =
        this->_entities[14]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    validTransCompo->setX(tools::Tools::getPercentage(44.f, true));
    validTransCompo->setY(tools::Tools::getPercentage(11.f + ((_lastSeenCursorPos - 1) * 15), false));
    validDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    validDrawableCompo->setWidth(tools::Tools::getPercentage(10.f, false));
    this->_positionsCursor[SOUND_0] = tools::Tools::getPercentage(13.f, false);
    this->_positionsCursor[SOUND_25] = tools::Tools::getPercentage(29.f, false);
    this->_positionsCursor[SOUND_50] = tools::Tools::getPercentage(44.f, false);
    this->_positionsCursor[SOUND_75] = tools::Tools::getPercentage(59.f, false);
    this->_positionsCursor[SOUND_100] = tools::Tools::getPercentage(74.f, false);
}

void indie::menu::SetSoundScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::SetSoundScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

int indie::menu::SetSoundScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == SOUND_0) {
            _cursorPosition = SOUND_25;
            return this->_positionsCursor[SOUND_25];
        }
        if (_cursorPosition == SOUND_25) {
            _cursorPosition = SOUND_50;
            return this->_positionsCursor[SOUND_50];
        }
        if (_cursorPosition == SOUND_50) {
            _cursorPosition = SOUND_75;
            return this->_positionsCursor[SOUND_75];
        }
        if (_cursorPosition == SOUND_75) {
            _cursorPosition = SOUND_100;
            return this->_positionsCursor[SOUND_100];
        }
        if (_cursorPosition == SOUND_100) {
            return this->_positionsCursor[SOUND_100];
        }
    } else if (!direction) {
        if (_cursorPosition == SOUND_0) {
            return this->_positionsCursor[SOUND_0];
        }
        if (_cursorPosition == SOUND_25) {
            _cursorPosition = SOUND_0;
            return this->_positionsCursor[SOUND_0];
        }
        if (_cursorPosition == SOUND_50) {
            _cursorPosition = SOUND_25;
            return this->_positionsCursor[SOUND_25];
        }
        if (_cursorPosition == SOUND_75) {
            _cursorPosition = SOUND_50;
            return this->_positionsCursor[SOUND_50];
        }
        if (_cursorPosition == SOUND_100) {
            _cursorPosition = SOUND_75;
            return this->_positionsCursor[SOUND_75];
        }
    }
    return 0;
}
