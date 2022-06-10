/*
** EPITECH PROJECT, 2020
** Bomberman
** File description:
** GameOptionsScreen.cpp
*/

#include "GameOptionsScreen.hpp"
#include "../../raylib/Raylib.hpp"
#include "../../tools/Tools.hpp"

indie::menu::GameOptionsScreen::GameOptionsScreen() : _cursorPosition(RESUME)
{
}

void indie::menu::GameOptionsScreen::init()
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
        tools::Tools::getPercentage(33.f, true), tools::Tools::getPercentage(9.f, false), 0.0f, 0.0f);
    cursor->addComponent<ecs::component::Drawable2D>(
        "assets/menu/hand.png", tools::Tools::getPercentage(6.f, false), tools::Tools::getPercentage(6.f, true), WHITE);
    addEntity(std::move(cursor));

    std::unique_ptr<ecs::entity::Entity> resume = std::make_unique<ecs::entity::Entity>();
    resume->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(6.f, false), 0.0f, 0.0f);
    resume->addComponent<ecs::component::Drawable2D>("assets/menu/resume.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(resume));

    std::unique_ptr<ecs::entity::Entity> menu = std::make_unique<ecs::entity::Entity>();
    menu->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(18.5f, false), 0.0f, 0.0f);
    menu->addComponent<ecs::component::Drawable2D>("assets/menu/menu.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(menu));

    std::unique_ptr<ecs::entity::Entity> save = std::make_unique<ecs::entity::Entity>();
    save->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(31.f, false), 0.0f, 0.0f);
    save->addComponent<ecs::component::Drawable2D>("assets/menu/save.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(save));

    std::unique_ptr<ecs::entity::Entity> music = std::make_unique<ecs::entity::Entity>();
    music->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(43.5f, false), 0.0f, 0.0f);
    music->addComponent<ecs::component::Drawable2D>("assets/menu/music.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(music));

    std::unique_ptr<ecs::entity::Entity> sound = std::make_unique<ecs::entity::Entity>();
    sound->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(56.f, false), 0.0f, 0.0f);
    sound->addComponent<ecs::component::Drawable2D>("assets/menu/sound.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(sound));

    std::unique_ptr<ecs::entity::Entity> fps = std::make_unique<ecs::entity::Entity>();
    fps->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(40.f, true), tools::Tools::getPercentage(68.5f, false), 0.0f, 0.0f);
    fps->addComponent<ecs::component::Drawable2D>("assets/menu/fps.png", tools::Tools::getPercentage(10.f, false),
        tools::Tools::getPercentage(18.f, true), WHITE);
    addEntity(std::move(fps));

    std::unique_ptr<ecs::entity::Entity> quit = std::make_unique<ecs::entity::Entity>();
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
        && _cursorPosition == MENU)
        return 1;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == RESUME)
        return 2;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == MUSIC)
        return 6;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == SOUND)
        return 7;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == FPS)
        return 8;
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON || event.key.enter)
        && _cursorPosition == EXIT)
        return 10;
    if (_cursorPosition == RESUME) {
        setSize(3, 12.f, 20.f);
        setSize(4, 10.f, 18.f);
    }
    if (_cursorPosition == MENU) {
        setSize(3, 10.f, 18.f);
        setSize(4, 12.f, 20.f);
        setSize(5, 10.f, 18.f);
    }
    if (_cursorPosition == SAVE) {
        setSize(4, 10.f, 18.f);
        setSize(5, 12.f, 20.f);
        setSize(6, 10.f, 18.f);
    }
    if (_cursorPosition == MUSIC) {
        setSize(5, 10.f, 18.f);
        setSize(6, 12.f, 20.f);
        setSize(7, 10.f, 18.f);
    }
    if (_cursorPosition == SOUND) {
        setSize(6, 10.f, 18.f);
        setSize(7, 12.f, 20.f);
        setSize(8, 10.f, 18.f);
    }
    if (_cursorPosition == FPS) {
        setSize(7, 10.f, 18.f);
        setSize(8, 12.f, 20.f);
        setSize(9, 10.f, 18.f);
    }
    if (_cursorPosition == EXIT) {
        setSize(8, 10.f, 18.f);
        setSize(9, 12.f, 20.f);
    }
    return 0;
}

void indie::menu::GameOptionsScreen::setSize(int where, float height, float width)
{
    ecs::component::Drawable2D *drawableCompo =
        _entities.at(where)->getComponent<ecs::component::Drawable2D>(ecs::component::compoType::DRAWABLE2D);
    drawableCompo->setHeight(tools::Tools::getPercentage(height, false));
    drawableCompo->setWidth(tools::Tools::getPercentage(width, true));
}

void indie::menu::GameOptionsScreen::update()
{
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
