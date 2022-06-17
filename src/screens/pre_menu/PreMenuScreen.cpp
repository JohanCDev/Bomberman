/**
 * @file PreMenuScreen.cpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen for the pre-menu
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "PreMenuScreen.hpp"
#include "../../player/Player.hpp"
#include "../../raylib/Raylib.hpp"
#include "../../tools/Tools.hpp"

indie::menu::PreMenuScreen::PreMenuScreen(std::vector<player::Player> *players)
    : _nb_players(1), _is_player2_playing(false), _is_player3_playing(false), _is_player4_playing(false),
      _is_player1_ready(false), _is_player2_ready(false), _is_player3_ready(false), _is_player4_ready(false),
      _game_is_ready(false)
{
    _players = players;
    _players->at(0).setIsPlaying(true);
}

void indie::menu::PreMenuScreen::init()
{
    std::unique_ptr<ecs::entity::Entity> background = std::make_unique<ecs::entity::Entity>();
    background->addComponent<ecs::component::Transform>(0.0f, 0.0f, 0.0f, 0.0f);
    background->addComponent<ecs::component::Drawable2D>("assets/menu/bg.png",
        tools::Tools::getPercentage(100.f, false), tools::Tools::getPercentage(100.f, true), WHITE);
    addEntity(std::move(background));

    std::unique_ptr<ecs::entity::Entity> launch_game = std::make_unique<ecs::entity::Entity>();
    launch_game->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(32.f, true), tools::Tools::getPercentage(88.f, false), 0.0f, 0.0f);
    launch_game->addComponent<ecs::component::Drawable2D>(
        "Press Triangle to start the game", tools::Tools::getPercentage(4.f, false), BLACK);
    addEntity(std::move(launch_game));

    std::unique_ptr<ecs::entity::Entity> joinText = std::make_unique<ecs::entity::Entity>();
    joinText->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(30.f, true), tools::Tools::getPercentage(4.f, false), 0.0f, 0.0f);
    joinText->addComponent<ecs::component::Drawable2D>(
        "Press X to join the game and again to confirm", tools::Tools::getPercentage(3.f, false), BLACK);
    addEntity(std::move(joinText));

    std::unique_ptr<ecs::entity::Entity> player1 = std::make_unique<ecs::entity::Entity>();
    player1->addComponent<ecs::component::Transform>(
        tools::Tools::getPercentage(7.f, true), tools::Tools::getPercentage(37.5f, false), 0.0f, 0.0f);
    player1->addComponent<ecs::component::Drawable2D>(
        "assets/blue.png", tools::Tools::getPercentage(25.f, false), tools::Tools::getPercentage(25.f, false), WHITE);
    addEntity(std::move(player1));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemPreMenu =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemPreMenu));
}

void indie::menu::PreMenuScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground(WHITE);

    for (auto &system : this->_systems) {
        system->update(this->_entities);
    }

    indie::raylib::Window::endDrawing();
}

int indie::menu::PreMenuScreen::handleEvent(indie::Event &event)
{
    handlePlayer1(event);
    handlePlayer2(event);
    handlePlayer3(event);
    handlePlayer4(event);
    if ((event.controller[0].code == indie::Event::ControllerCode::T_BUTTON || event.key.r_shift) && _nb_players >= 2
        && check_if_players_are_ready()) {
        _game_is_ready = true;
        return 2;
    }
    if (event.controller[0].code == indie::Event::ControllerCode::OPTION_BUTTON) {
        _game_is_ready = true;
        return 2;
    }
    return 0;
}

void indie::menu::PreMenuScreen::update()
{
}

void indie::menu::PreMenuScreen::addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity)
{
    this->_entities.push_back(std::move(entity));
}

void indie::menu::PreMenuScreen::addSystem(std::unique_ptr<indie::ecs::system::ISystem> system)
{
    this->_systems.push_back(std::move(system));
}

int indie::menu::PreMenuScreen::getNbPlayers() const
{
    return _nb_players;
}

bool indie::menu::PreMenuScreen::isPlayer2Playing() const
{
    return _is_player2_playing;
}

bool indie::menu::PreMenuScreen::isPlayer3Playing() const
{
    return _is_player3_playing;
}

bool indie::menu::PreMenuScreen::isPlayer4Playing() const
{
    return _is_player4_playing;
}

bool indie::menu::PreMenuScreen::getIsGameReady() const
{
    return _game_is_ready;
}

void indie::menu::PreMenuScreen::setIsGameReady(bool is_game_ready)
{
    _game_is_ready = is_game_ready;
}

bool indie::menu::PreMenuScreen::check_if_players_are_ready()
{
    if (!_is_player1_ready)
        return false;
    if (_is_player2_playing && !_is_player2_ready)
        return false;
    if (_is_player3_playing && !_is_player3_ready)
        return false;
    if (_is_player4_playing && !_is_player4_ready)
        return false;
    return true;
}

void indie::menu::PreMenuScreen::handlePlayer1(indie::Event &event)
{
    if ((event.controller[0].code == indie::Event::ControllerCode::X_BUTTON) && !_is_player1_ready) {
        std::unique_ptr<ecs::entity::Entity> ready = std::make_unique<ecs::entity::Entity>();
        ready->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(12.f, true), tools::Tools::getPercentage(40.5f, false), 0.0f, 0.0f);
        ready->addComponent<ecs::component::Drawable2D>("assets/menu/ready.png",
            tools::Tools::getPercentage(15.f, true), tools::Tools::getPercentage(17.f, false), WHITE);
        addEntity(std::move(ready));
        _player1_ready_pos = _entities.size() - 1;
        _is_player1_ready = true;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::O_BUTTON) && _is_player1_ready) {
        _entities.erase(_entities.begin() + _player1_ready_pos);
        _is_player1_ready = false;
    }
    _players->at(0).setIsPlaying(_is_player1_ready);
}

void indie::menu::PreMenuScreen::handlePlayer2(indie::Event &event)
{
    if (event.controller[1].connected && (event.controller[1].code == indie::Event::ControllerCode::X_BUTTON)
        && !_is_player2_playing) {
        std::unique_ptr<ecs::entity::Entity> player2 = std::make_unique<ecs::entity::Entity>();
        player2->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(29.f, true), tools::Tools::getPercentage(37.5f, false), 0.0f, 0.0f);
        player2->addComponent<ecs::component::Drawable2D>("assets/red.png", tools::Tools::getPercentage(28.f, false),
            tools::Tools::getPercentage(28.f, false), WHITE);
        addEntity(std::move(player2));
        _nb_players++;
        _player2_pos = _entities.size() - 1;
        _is_player2_playing = true;
        event.controller[1].code = indie::Event::ControllerCode::CONTROLLER_NONE;
    }
    if (event.controller[1].connected && (event.controller[1].code == indie::Event::ControllerCode::O_BUTTON)
        && _is_player2_playing && !_is_player2_ready) {
        _entities.erase(_entities.begin() + _player2_pos);
        _nb_players--;
        _is_player2_playing = false;
    }
    if ((event.controller[1].code == indie::Event::ControllerCode::X_BUTTON) && !_is_player2_ready
        && _is_player2_playing) {
        std::unique_ptr<ecs::entity::Entity> ready = std::make_unique<ecs::entity::Entity>();
        ready->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(34.f, true), tools::Tools::getPercentage(40.5f, false), 0.0f, 0.0f);
        ready->addComponent<ecs::component::Drawable2D>("assets/menu/ready.png",
            tools::Tools::getPercentage(15.f, true), tools::Tools::getPercentage(17.f, false), WHITE);
        addEntity(std::move(ready));
        _player2_ready_pos = _entities.size() - 1;
        _is_player2_ready = true;
    }
    if ((event.controller[1].code == indie::Event::ControllerCode::O_BUTTON) && _is_player2_ready) {
        _entities.erase(_entities.begin() + _player2_ready_pos);
        _is_player2_ready = false;
    }
    if (!event.controller[1].connected && _is_player2_playing) {
        _entities.erase(_entities.begin() + _player2_pos);
        _nb_players--;
        _is_player2_playing = false;
        if (_is_player2_ready) {
            _entities.erase(_entities.begin() + _player2_ready_pos);
            _is_player2_ready = false;
        }
    }
    _players->at(1).setIsPlaying(_is_player2_ready);
}

void indie::menu::PreMenuScreen::handlePlayer3(indie::Event &event)
{
    if (event.controller[2].connected && (event.controller[2].code == indie::Event::ControllerCode::X_BUTTON)
        && !_is_player3_playing) {
        std::unique_ptr<ecs::entity::Entity> player3 = std::make_unique<ecs::entity::Entity>();
        player3->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(52.f, true), tools::Tools::getPercentage(37.5f, false), 0.0f, 0.0f);
        player3->addComponent<ecs::component::Drawable2D>("assets/green.png", tools::Tools::getPercentage(28.f, false),
            tools::Tools::getPercentage(28.f, false), WHITE);
        addEntity(std::move(player3));
        _player3_pos = _entities.size() - 1;
        _nb_players++;
        _is_player3_playing = true;
        event.controller[2].code = indie::Event::ControllerCode::CONTROLLER_NONE;
    }
    if (event.controller[2].connected && (event.controller[2].code == indie::Event::ControllerCode::O_BUTTON)
        && _is_player3_playing && !_is_player3_ready) {
        _entities.erase(_entities.begin() + _player3_pos);
        _nb_players--;
        _is_player3_playing = false;
    }
    if ((event.controller[2].code == indie::Event::ControllerCode::X_BUTTON) && !_is_player3_ready
        && _is_player3_playing) {
        std::unique_ptr<ecs::entity::Entity> ready = std::make_unique<ecs::entity::Entity>();
        ready->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(57.f, true), tools::Tools::getPercentage(40.5f, false), 0.0f, 0.0f);
        ready->addComponent<ecs::component::Drawable2D>("assets/menu/ready.png",
            tools::Tools::getPercentage(15.f, false), tools::Tools::getPercentage(17.f, true), WHITE);
        addEntity(std::move(ready));
        _player3_ready_pos = _entities.size() - 1;
        _is_player3_ready = true;
    }
    if ((event.controller[2].code == indie::Event::ControllerCode::O_BUTTON) && _is_player3_ready) {
        _entities.erase(_entities.begin() + _player3_ready_pos);
        _is_player3_ready = false;
    }
    if (!event.controller[2].connected && _is_player3_playing) {
        _entities.erase(_entities.begin() + _player3_pos);
        _nb_players--;
        _is_player3_playing = false;
        if (_is_player3_ready) {
            _entities.erase(_entities.begin() + _player3_ready_pos);
            _is_player3_ready = false;
        }
    }
    _players->at(2).setIsPlaying(_is_player3_ready);
}

void indie::menu::PreMenuScreen::handlePlayer4(indie::Event &event)
{
    if (event.controller[3].connected && (event.controller[3].code == indie::Event::ControllerCode::X_BUTTON)
        && !_is_player4_playing) {
        std::unique_ptr<ecs::entity::Entity> player4 = std::make_unique<ecs::entity::Entity>();
        player4->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(74.f, true), tools::Tools::getPercentage(37.5f, false), 0.0f, 0.0f);
        player4->addComponent<ecs::component::Drawable2D>("assets/yellow.png", tools::Tools::getPercentage(28.f, false),
            tools::Tools::getPercentage(28.f, false), WHITE);
        addEntity(std::move(player4));
        _player4_pos = _entities.size() - 1;
        _nb_players++;
        _is_player4_playing = true;
        event.controller[3].code = indie::Event::ControllerCode::CONTROLLER_NONE;
    }
    if (event.controller[3].connected && (event.controller[3].code == indie::Event::ControllerCode::O_BUTTON)
        && _is_player4_playing && !_is_player4_ready) {
        _entities.erase(_entities.begin() + _player4_pos);
        _nb_players--;
        _is_player4_playing = false;
    }
    if ((event.controller[3].code == indie::Event::ControllerCode::X_BUTTON) && !_is_player4_ready
        && _is_player4_playing) {
        std::unique_ptr<ecs::entity::Entity> ready = std::make_unique<ecs::entity::Entity>();
        ready->addComponent<ecs::component::Transform>(
            tools::Tools::getPercentage(79.f, true), tools::Tools::getPercentage(40.5f, false), 0.0f, 0.0f);
        ready->addComponent<ecs::component::Drawable2D>("assets/menu/ready.png",
            tools::Tools::getPercentage(15.f, true), tools::Tools::getPercentage(17.f, false), WHITE);
        addEntity(std::move(ready));
        _player4_ready_pos = _entities.size() - 1;
        _is_player4_ready = true;
    }
    if ((event.controller[3].code == indie::Event::ControllerCode::O_BUTTON) && _is_player4_ready) {
        _entities.erase(_entities.begin() + _player4_ready_pos);
        _is_player4_ready = false;
    }
    if (!event.controller[3].connected && _is_player4_playing) {
        _entities.erase(_entities.begin() + _player4_pos);
        _nb_players--;
        _is_player4_playing = false;
        if (_is_player4_ready) {
            _entities.erase(_entities.begin() + _player4_ready_pos);
            _is_player4_ready = false;
        }
    }
    _players->at(3).setIsPlaying(_is_player4_ready);
}
