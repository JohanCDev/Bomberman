/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Game
*/

#include "Game.hpp"
#include <algorithm>
#include <chrono>
#include <fstream>
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
    _players.push_back(player::Player(BLUEPLAYERCOLOR, 0));
    _players.push_back(player::Player(REDPLAYERCOLOR, 1));
    _players.push_back(player::Player(GREENPLAYERCOLOR, 2));
    _players.push_back(player::Player(YELLOWPLAYERCOLOR, 3));
    _actualScreen = Screens::Menu;
    initSounds();
    _menu = new indie::menu::MenuScreen;
    _game = new indie::menu::GameScreen(&_players, &_sound_entities, &_sound_systems);
    _premenu = new indie::menu::PreMenuScreen(&_players);
    _gameoptions = new indie::menu::GameOptionsScreen;
    _setFps = new indie::menu::SetFpsScreen;
    _setSound = new indie::menu::SetSoundScreen(&_sound_entities);
    _setMusic = new indie::menu::SetMusicScreen(&_musics);
}

indie::Game::~Game()
{
    delete _menu;
    delete _game;
    delete _premenu;
    delete _gameoptions;
    delete _setFps;
    delete _setSound;
    delete _setMusic;
}

void indie::Game::init()
{
    initScenes();
    initMusic();
    _musics[MENU_SOUND].play();
}

void indie::Game::initMusic()
{
    indie::raylib::Sound menuSound("assets/music/music.ogg");
    menuSound.setVolume(0.5f);
    _musics.insert({MENU_SOUND, menuSound});
}

void indie::Game::initSounds()
{
    std::unique_ptr<ecs::entity::Entity> bombSound = std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    bombSound->addComponent<ecs::component::Sound>("assets/sound/bomb.ogg", false);
    addSoundEntity(std::move(bombSound));

    std::unique_ptr<ecs::entity::Entity> gameReadySound =
        std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    gameReadySound->addComponent<ecs::component::Sound>("assets/sound/game_ready.ogg", false);
    addSoundEntity(std::move(gameReadySound));

    std::unique_ptr<ecs::entity::Entity> selectSound =
        std::make_unique<ecs::entity::Entity>(indie::ecs::entity::UNKNOWN);
    selectSound->addComponent<ecs::component::Sound>("assets/sound/select.ogg", false);
    addSoundEntity(std::move(selectSound));

    std::unique_ptr<indie::ecs::system::ISystem> soundSystem = std::make_unique<indie::ecs::system::Sound>();
    addSoundSystem(std::move(soundSystem));
}

void indie::Game::addSoundEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_sound_entities.push_back(std::move(entity));
}

void indie::Game::addSoundSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_sound_systems.push_back(std::move(system));
}

void indie::Game::initScenes()
{
    _menu->init();
    _game->init();
    _premenu->init();
    _gameoptions->init();
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
        if (!_musics[MENU_SOUND].isPlaying()) {
            _musics[MENU_SOUND].play();
        }
        if (!processEvents())
            break;
        update();
        draw();
    }
}

void indie::Game::destroy()
{
    destroyEntities();
    destroySystems();
    indie::raylib::Window::destroyWindow();
}

void indie::Game::destroyEntities()
{
    std::vector<std::unique_ptr<indie::ecs::entity::Entity>>::iterator _it_sound_entities = _sound_entities.begin();

    while (_it_sound_entities != _sound_entities.end()) {
        _it_sound_entities->reset();
        ++_it_sound_entities;
    }
}

void indie::Game::destroySystems()

{
    std::vector<std::unique_ptr<indie::ecs::system::ISystem>>::iterator _it_sound_systems = _sound_systems.begin();

    while (_it_sound_systems != _sound_systems.end()) {
        _it_sound_systems->reset();
        ++_it_sound_systems;
    }
}

void indie::Game::setSoundEvent(int entitiesIndex)
{
    _sound_entities.at(entitiesIndex)
        ->getComponent<ecs::component::Sound>(ecs::component::compoType::SOUND)
        ->setPlay(true);
    for (auto &system : this->_sound_systems) {
        system->update(this->_sound_entities);
    }
    _sound_entities.at(entitiesIndex)
        ->getComponent<ecs::component::Sound>(ecs::component::compoType::SOUND)
        ->setPlay(false);
}

void indie::Game::handleScreensSwap(int ret)
{
    if (ret == 1) {
        setSoundEvent(SELECT_S);
        reinitGame();
        setActualScreen(Screens::Menu);
    }
    if (ret == 2) {
        setSoundEvent(GAME_READY_S);
        setActualScreen(Screens::Game);
    }
    if (ret == 3) {
        setSoundEvent(SELECT_S);
        setActualScreen(Screens::PreMenu);
    }
    if (ret == 4) {
        setActualScreen(Screens::GameOptions);
    }
    if (ret == 6) {
        setSoundEvent(SELECT_S);
        setActualScreen(Screens::SetMusic);
    }
    if (ret == 7) {
        setSoundEvent(SELECT_S);
        setActualScreen(Screens::SetSound);
    }
    if (ret == 8) {
        setSoundEvent(SELECT_S);
        setActualScreen(Screens::SetFps);
    }
    if (ret == 11)
        saveGame();
    if (ret == 12)
        loadGame();
}

void indie::Game::reinitGame()
{
    _players.clear();
    _players.push_back(player::Player(BLUEPLAYERCOLOR, 0));
    _players.push_back(player::Player(REDPLAYERCOLOR, 1));
    _players.push_back(player::Player(GREENPLAYERCOLOR, 2));
    _players.push_back(player::Player(YELLOWPLAYERCOLOR, 3));
    delete _game;
    _game = new indie::menu::GameScreen(&_players, &_sound_entities, &_sound_systems);
    _game->init();
    delete _premenu;
    _premenu = new indie::menu::PreMenuScreen(&_players);
    _premenu->init();
}

void indie::Game::setActualScreen(Screens newScreen)
{
    _actualScreen = newScreen;
}

void indie::Game::saveGame()
{
    _game->saveMapEntities();
    setActualScreen(Screens::GameOptions);
}

void indie::Game::loadGame()
{
    if (!_game->loadSavedMap()) {
        std::cout << "No game to load" << std::endl;
        return;
    }
    _game->initEntity();
    setActualScreen(Screens::Game);
}
