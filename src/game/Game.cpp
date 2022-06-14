/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Game
*/

#include "Game.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <memory>
#include "../ecs/system/Collide/Collide.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"
#include "../ecs/system/Draw3D/Draw3D.hpp"
#include "../ecs/system/Explodable/Explodable.hpp"
#include "../ecs/system/Movement/Movement.hpp"
#include "../ecs/system/Sound/Sound.hpp"
#include "../gameEvents/GameEvents.hpp"
#include "../map/MapGenerator.hpp"
#include "../player/Player.hpp"
#include "../raylib/Raylib.hpp"
#include "../screens/IScreen.hpp"
#include "Colors.hpp"

indie::Game::Game(size_t baseFps)
{
    _fps = baseFps;
    _players.push_back(player::Player(BLUEPLAYERCOLOR, 0, {0, 0}));
    _players.push_back(player::Player(REDPLAYERCOLOR, 1, {0, 0}));
    _players.push_back(player::Player(GREENPLAYERCOLOR, 2, {0, 0}));
    _players.push_back(player::Player(YELLOWPLAYERCOLOR, 3, {0, 0}));
    _actualScreen = Screens::Menu;
    _menu = new indie::menu::MenuScreen;
    _game = new indie::menu::GameScreen(&_players);
    _premenu = new indie::menu::PreMenuScreen(&_players);
    _gameoptions = new indie::menu::GameOptionsScreen;
    _end = new indie::menu::EndScreen;
    _setFps = new indie::menu::SetFpsScreen;
    _setSound = new indie::menu::SetSoundScreen;
    _setMusic = new indie::menu::SetMusicScreen;
}

indie::Game::~Game()
{
    delete _menu;
    delete _game;
    delete _premenu;
    delete _gameoptions;
    delete _end;
    delete _setFps;
    delete _setSound;
    delete _setMusic;
}

void indie::Game::init()
{
    initScenes();
    initSounds();
    _sounds[MENU_SOUND].play();
}

void indie::Game::initSounds()
{
    std::unique_ptr<ecs::entity::Entity> menuSound = std::make_unique<ecs::entity::Entity>();
    menuSound->addComponent<ecs::component::Sound>("assets/sound/sound.wav", true);
    addEntity(std::move(menuSound));

    std::unique_ptr<indie::ecs::system::ISystem> soundSystem = std::make_unique<indie::ecs::system::Sound>();
    addSystem(std::move(soundSystem));

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }
}

void indie::Game::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::Game::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

void indie::Game::initScenes()
{
    _menu->init();
    _game->init();
    _premenu->init();
    _gameoptions->init();
    _end->init();
    _setFps->init();
    _setSound->init();
    _setMusic->init();
}

bool indie::Game::processEvents()
{
    GameEvents gameEvent;

    bool ret = gameEvent.inputUpdate(_event);
    int swap = handleEvent();
    if (swap == 10)
        return false;
    handleScreensSwap(swap);
    return (ret);
}

void indie::Game::update()
{
    if (_premenu->getIsGameReady()) {
        this->_game->getPlayersPlaying(this->_players.at(0).getIsPlaying(), this->_players.at(1).getIsPlaying(),
            this->_players.at(2).getIsPlaying(), this->_players.at(3).getIsPlaying());
        indie::map::MapGenerator map;
        map.createWall();
        this->_game->initMap(map.getMap());
        this->_game->initEntity();
        _premenu->setIsGameReady(false);
    }
    switch (_actualScreen) {
        case Screens::Menu: _menu->update(); break;
        case Screens::Game: _game->update(); break;
        case Screens::PreMenu: _premenu->update(); break;
        case Screens::GameOptions: _gameoptions->update(); break;
        case Screens::End: _end->update(); break;
        case Screens::SetFps: _setFps->update(); break;
        case Screens::SetSound: _setSound->update(); break;
        case Screens::SetMusic: _setMusic->update(); break;
        default: break;
    }
}

void indie::Game::draw()
{
    switch (_actualScreen) {
        case Screens::Menu: _menu->draw(); break;
        case Screens::Game: _game->draw(); break;
        case Screens::PreMenu: _premenu->draw(); break;
        case Screens::GameOptions: _gameoptions->draw(); break;
        case Screens::End: _end->draw(); break;
        case Screens::SetFps: _setFps->draw(); break;
        case Screens::SetSound: _setSound->draw(); break;
        case Screens::SetMusic: _setMusic->draw(); break;
        default: break;
    }
}

int indie::Game::handleEvent()
{
    switch (_actualScreen) {
        case Screens::Menu: return (_menu->handleEvent(_event));
        case Screens::Game: return (_game->handleEvent(_event));
        case Screens::PreMenu: return (_premenu->handleEvent(_event));
        case Screens::GameOptions: return (_gameoptions->handleEvent(_event));
        case Screens::End: return (_end->handleEvent(_event));
        case Screens::SetFps: return (_setFps->handleEvent(_event));
        case Screens::SetSound: return (_setSound->handleEvent(_event));
        case Screens::SetMusic: return (_setMusic->handleEvent(_event));
        default: break;
    }
    return true;
}

void indie::Game::run()
{
    while (!indie::raylib::Window::windowShouldClose()) {
        if (!processEvents())
            break;
        update();
        draw();
    }
    destroy();
}

void indie::Game::destroy()
{
    destroyEntities();
    destroySystems();
    indie::raylib::Window::destroyWindow();
}

void indie::Game::destroyEntities()
{
    _it_entities = _entities.begin();

    while (_it_entities != _entities.end()) {
        _it_entities->reset();
        ++_it_entities;
    }
}

void indie::Game::destroySystems()
{
    _it_systems = _systems.begin();

    while (_it_systems != _systems.end()) {
        _it_systems->reset();
        ++_it_systems;
    }
}

void indie::Game::handleScreensSwap(int ret)
{
    if (ret == 1) {
        reinitGame();
        setActualScreen(Screens::Menu);
    }
    if (ret == 2)
        setActualScreen(Screens::Game);
    if (ret == 3)
        setActualScreen(Screens::PreMenu);
    if (ret == 4)
        setActualScreen(Screens::GameOptions);
    if (ret == 5)
        setActualScreen(Screens::End);
    if (ret == 6)
        setActualScreen(Screens::SetMusic);
    if (ret == 7)
        setActualScreen(Screens::SetSound);
    if (ret == 8)
        setActualScreen(Screens::SetFps);
}

void indie::Game::reinitGame()
{
    _players.clear();
    _players.push_back(player::Player(BLUEPLAYERCOLOR, 0, {0, 0}));
    _players.push_back(player::Player(REDPLAYERCOLOR, 1, {0, 0}));
    _players.push_back(player::Player(GREENPLAYERCOLOR, 2, {0, 0}));
    _players.push_back(player::Player(YELLOWPLAYERCOLOR, 3, {0, 0}));
    delete _game;
    _game = new indie::menu::GameScreen(&_players);
    _game->init();
    delete _premenu;
    _premenu = new indie::menu::PreMenuScreen(&_players);
    _premenu->init();
}

void indie::Game::setActualScreen(Screens newScreen)
{
    _actualScreen = newScreen;
}
