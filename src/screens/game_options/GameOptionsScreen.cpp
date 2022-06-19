/**
 * @file SetSoundScreen.cpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen for the options of the game
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "GameOptionsScreen.hpp"
#include "../../raylib/Raylib.hpp"
#include "../../tools/Tools.hpp"

indie::menu::GameOptionsScreen::GameOptionsScreen() : _cursorPosition(RESUME)
{
}

void indie::menu::GameOptionsScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> background =
        std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    background->addComponent<ecs::component::Transform>(0.0f, 0.0f, 0.0f, 0.0f);
    background->addComponent<ecs::component::Drawable2D>("assets/menu/bg.png",
        tools::Tools::getPercentage(100.f, false), tools::Tools::getPercentage(100.f, true), WHITE);
    addEntity(std::move(background));

    std::unique_ptr<ecs::entity::Entity> frame = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    frame->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(20.f, true), tools::Tools::getPercentage(2.5f, false), 0.0f, 0.0f);
    frame->addComponent<ecs::component::Drawable2D>("assets/menu/frame.png", tools::Tools::getPercentage(95.f, false),
        tools::Tools::getPercentage(60.f, true), WHITE);
    addEntity(std::move(frame));

    std::unique_ptr<ecs::entity::Entity> cursor = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    cursor->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(33.f, true), tools::Tools::getPercentage(9.f, false), 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>("assets/menu/hand.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(6.f, true), WHITE);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> resume = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    resume->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(6.f, false), 0.0f, 0.0f);
    resume->addComponent<ecs::component::Drawable2D>("assets/menu/resume.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(resume));

    std::unique_ptr<ecs::entity::Entity> menu = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    menu->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(18.5f, false), 0.0f, 0.0f);
    menu->addComponent<ecs::component::Drawable2D>("assets/menu/menu.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(menu));

    std::unique_ptr<ecs::entity::Entity> save = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    save->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(31.f, false), 0.0f, 0.0f);
    save->addComponent<ecs::component::Drawable2D>("assets/menu/save.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(save));

    std::unique_ptr<ecs::entity::Entity> music = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    music->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(43.5f, false), 0.0f, 0.0f);
    music->addComponent<ecs::component::Drawable2D>("assets/menu/music.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(music));

    std::unique_ptr<ecs::entity::Entity> sound = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    sound->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(56.f, false), 0.0f, 0.0f);
    sound->addComponent<ecs::component::Drawable2D>("assets/menu/sound.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(sound));

    std::unique_ptr<ecs::entity::Entity> fps = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    fps->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(68.5f, false), 0.0f, 0.0f);
    fps->addComponent<ecs::component::Drawable2D>("assets/menu/fps.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(fps));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    quit->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(81.f, false), 0.0f, 0.0f);
    quit->addComponent<ecs::component::Drawable2D>("assets/menu/quit.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(quit));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemGameOptions =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemGameOptions));
    this->_positionsCursor[RESUME] = tools::Tools::getPercentage(9.f, false);
    this->_positionsCursor[MENU] = tools::Tools::getPercentage(21.f, false);
    this->_positionsCursor[SAVE] = tools::Tools::getPercentage(33.5f, false);
    this->_positionsCursor[MUSIC] = tools::Tools::getPercentage(46.f, false);
    this->_positionsCursor[SOUND] = tools::Tools::getPercentage(58.5f, false);
    this->_positionsCursor[FPS] = tools::Tools::getPercentage(71.f, false);
    this->_positionsCursor[EXIT] = tools::Tools::getPercentage(83.5f, false);
}

void indie::menu::GameOptionsScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::GameOptionsScreen::handleEvent(indie::Event &event)
{
    if (event.controller[0].code == indie::Event::ControllerCode::DOWN_BUTTON || event.key.down) {
        indie::ecs::component::Transform *transformCompo =
            _entities.at(2)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(tools::Tools::getPercentage(33.f, true), checkCursorPosition(true), 0.0f, 0.0f);
    }
    if (event.controller[0].code == indie::Event::ControllerCode::UP_BUTTON || event.key.up) {
        ecs::component::Transform *transformCompo =
            _entities.at(2)->getComponent<ecs::component::Transform>(ecs::component::compoType::TRANSFORM);
        transformCompo->update(tools::Tools::getPercentage(33.f, true), checkCursorPosition(false), 0.0f, 0.0f);
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == MENU) {
        if (_entities.size() == 11)
            _entities.erase(_entities.begin() + 10);
        return 1;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == RESUME) {
        if (_entities.size() == 11)
            _entities.erase(_entities.begin() + 10);
        return 2;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == SAVE) {
        std::unique_ptr<ecs::entity::Entity> save = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
        save->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(60.f, true), tools::Tools::getPercentage(34.f, false), 0.0f, 0.0f);
        save->addComponent<ecs::component::Drawable2D>("Game saved !", tools::Tools::getPercentage(5.f, false), WHITE);
        addEntity(std::move(save));
        return 11;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == MUSIC) {
        if (_entities.size() == 11)
            _entities.erase(_entities.begin() + 10);
        return 6;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == SOUND) {
        if (_entities.size() == 11)
            _entities.erase(_entities.begin() + 10);
        return 7;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == FPS) {
        if (_entities.size() == 11)
            _entities.erase(_entities.begin() + 10);
        return 8;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == EXIT)
        return 10;
    return 0;
}

void indie::menu::GameOptionsScreen::update()
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
    ecs::component::Drawable2D *resumeDrawableCompo =
        this->_entities[3]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *resumeTransCompo =
        this->_entities[3]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *menuDrawableCompo =
        this->_entities[4]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *menuTransCompo =
        this->_entities[4]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *saveDrawableCompo =
        this->_entities[5]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *saveTransCompo =
        this->_entities[5]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *musicDrawableCompo =
        this->_entities[6]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *musicTransCompo =
        this->_entities[6]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *soundDrawableCompo =
        this->_entities[7]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *soundTransCompo =
        this->_entities[7]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *fpsDrawableCompo =
        this->_entities[8]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *fpsTransCompo =
        this->_entities[8]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);
    ecs::component::Drawable2D *quitDrawableCompo =
        this->_entities[9]->getComponent<ecs::component::Drawable2D>(ecs::component::DRAWABLE2D);
    ecs::component::Transform *quitTransCompo =
        this->_entities[9]->getComponent<ecs::component::Transform>(ecs::component::TRANSFORM);

    bgDrawableCompo->setHeight(tools::Tools::getPercentage(100.f, false));
    bgDrawableCompo->setWidth(tools::Tools::getPercentage(100.f, true));
    frameTransCompo->setX(tools::Tools::getPercentage(20.f, true));
    frameTransCompo->setY(tools::Tools::getPercentage(2.5f, false));
    frameDrawableCompo->setHeight(tools::Tools::getPercentage(95.f, false));
    frameDrawableCompo->setWidth(tools::Tools::getPercentage(60.f, true));
    cursTransCompo->setX(tools::Tools::getPercentage(33.f, true));
    cursTransCompo->setY(this->_positionsCursor[this->_cursorPosition]);
    cursDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    cursDrawableCompo->setWidth(tools::Tools::getPercentage(6.f, true));
    resumeTransCompo->setX(tools::Tools::getPercentage(40.f, true));
    resumeTransCompo->setY(tools::Tools::getPercentage(6.f, false));
    resumeDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    resumeDrawableCompo->setWidth(tools::Tools::getPercentage(18.f, true));
    menuTransCompo->setX(tools::Tools::getPercentage(40.f, true));
    menuTransCompo->setY(tools::Tools::getPercentage(18.5f, false));
    menuDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    menuDrawableCompo->setWidth(tools::Tools::getPercentage(18.f, true));
    saveTransCompo->setX(tools::Tools::getPercentage(40.f, true));
    saveTransCompo->setY(tools::Tools::getPercentage(31.f, false));
    saveDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    saveDrawableCompo->setWidth(tools::Tools::getPercentage(18.f, true));
    musicTransCompo->setX(tools::Tools::getPercentage(40.f, true));
    musicTransCompo->setY(tools::Tools::getPercentage(43.5f, false));
    musicDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    musicDrawableCompo->setWidth(tools::Tools::getPercentage(18.f, true));
    soundTransCompo->setX(tools::Tools::getPercentage(40.f, true));
    soundTransCompo->setY(tools::Tools::getPercentage(56.f, false));
    soundDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    soundDrawableCompo->setWidth(tools::Tools::getPercentage(18.f, true));
    fpsTransCompo->setX(tools::Tools::getPercentage(40.f, true));
    fpsTransCompo->setY(tools::Tools::getPercentage(68.5f, false));
    fpsDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    fpsDrawableCompo->setWidth(tools::Tools::getPercentage(18.f, true));
    quitTransCompo->setX(tools::Tools::getPercentage(40.f, true));
    quitTransCompo->setY(tools::Tools::getPercentage(81.f, false));
    quitDrawableCompo->setHeight(tools::Tools::getPercentage(10.f, false));
    quitDrawableCompo->setWidth(tools::Tools::getPercentage(18.f, true));
    this->_positionsCursor[RESUME] = tools::Tools::getPercentage(9.f, false);
    this->_positionsCursor[MENU] = tools::Tools::getPercentage(21.f, false);
    this->_positionsCursor[SAVE] = tools::Tools::getPercentage(33.5f, false);
    this->_positionsCursor[MUSIC] = tools::Tools::getPercentage(46.f, false);
    this->_positionsCursor[SOUND] = tools::Tools::getPercentage(58.5f, false);
    this->_positionsCursor[FPS] = tools::Tools::getPercentage(71.f, false);
    this->_positionsCursor[EXIT] = tools::Tools::getPercentage(83.5f, false);
}

void indie::menu::GameOptionsScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::GameOptionsScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

int indie::menu::GameOptionsScreen::checkCursorPosition(bool direction)
{
    if (direction) {
        if (_cursorPosition == RESUME) {
            _cursorPosition = MENU;
            return this->_positionsCursor[MENU];
        }
        if (_cursorPosition == MENU) {
            _cursorPosition = SAVE;
            return this->_positionsCursor[SAVE];
        }
        if (_cursorPosition == SAVE) {
            _cursorPosition = MUSIC;
            return this->_positionsCursor[MUSIC];
        }
        if (_cursorPosition == MUSIC) {
            _cursorPosition = SOUND;
            return this->_positionsCursor[SOUND];
        }
        if (_cursorPosition == SOUND) {
            _cursorPosition = FPS;
            return this->_positionsCursor[FPS];
        }
        if (_cursorPosition == FPS) {
            _cursorPosition = EXIT;
            return this->_positionsCursor[EXIT];
        }
        if (_cursorPosition == EXIT)
            return this->_positionsCursor[EXIT];
    } else if (!direction) {
        if (_cursorPosition == RESUME)
            return this->_positionsCursor[RESUME];
        if (_cursorPosition == MENU) {
            _cursorPosition = RESUME;
            return this->_positionsCursor[RESUME];
        }
        if (_cursorPosition == SAVE) {
            _cursorPosition = MENU;
            return this->_positionsCursor[MENU];
        }
        if (_cursorPosition == MUSIC) {
            _cursorPosition = SAVE;
            return this->_positionsCursor[SAVE];
        }
        if (_cursorPosition == SOUND) {
            _cursorPosition = MUSIC;
            return this->_positionsCursor[MUSIC];
        }
        if (_cursorPosition == FPS) {
            _cursorPosition = SOUND;
            return this->_positionsCursor[SOUND];
        }
        if (_cursorPosition == EXIT) {
            _cursorPosition = FPS;
            return this->_positionsCursor[FPS];
        }
    }
    return 0;
}
