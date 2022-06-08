/*
** EPITECH PROJECT, 2021
** Bomberman
** File description:
** PreMenuScreen.hpp
*/

#include "PreMenuScreen.hpp"
#include "../../raylib/Raylib.hpp"

indie::menu::PreMenuScreen::PreMenuScreen()
    : _nb_players(1), _is_player2_playing(false), _is_player3_playing(false), _is_player4_playing(false),
      _is_player1_ready(false), _is_player2_ready(false), _is_player3_ready(false), _is_player4_ready(false)
{
    std::unique_ptr<ecs::entity::Entity> launch_game = std::make_unique<ecs::entity::Entity>();
    launch_game->addComponent<ecs::component::Transform>(
        static_cast<float>(600.0), static_cast<float>(850.0), static_cast<float>(0.0), static_cast<float>(0.0));
    launch_game->addComponent<ecs::component::Drawable2D>(
        "Press Triangle to start the game", static_cast<float>(40.0), BLACK);
    addEntity(std::move(launch_game));

    std::unique_ptr<ecs::entity::Entity> player1 = std::make_unique<ecs::entity::Entity>();
    player1->addComponent<ecs::component::Transform>(
        static_cast<float>(200.0), static_cast<float>(300.0), static_cast<float>(0.0), static_cast<float>(0.0));
    player1->addComponent<ecs::component::Drawable2D>("", static_cast<float>(500.0), static_cast<float>(300.0), BLUE);
    addEntity(std::move(player1));

    std::unique_ptr<indie::ecs::system::ISystem> draw2DSystemPreMenu =
        std::make_unique<indie::ecs::system::Draw2DSystem>();
    addSystem(std::move(draw2DSystemPreMenu));
}

void indie::menu::PreMenuScreen::draw()
{
    indie::raylib::Window::beginDrawing();
    indie::raylib::Window::clearBackground();

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
    if (event.controller[0].code == indie::Event::ControllerCode::T_BUTTON && _nb_players >= 2
        && check_if_players_are_ready())
        return 2;
    return 0;
}

void indie::menu::PreMenuScreen::update(float delta)
{
    (void)delta;
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
            static_cast<float>(280.0), static_cast<float>(500.0), static_cast<float>(0.0), static_cast<float>(0.0));
        ready->addComponent<ecs::component::Drawable2D>("READY", static_cast<float>(40.0), BLACK);
        addEntity(std::move(ready));
        _player1_ready_pos = _entities.size() - 1;
        _is_player1_ready = true;
    }
    if ((event.controller[0].code == indie::Event::ControllerCode::O_BUTTON) && _is_player1_ready) {
        _entities.erase(_entities.begin() + _player1_ready_pos);
        _is_player1_ready = false;
    }
}

void indie::menu::PreMenuScreen::handlePlayer2(indie::Event &event)
{
    if (event.controller[1].connected && (event.controller[1].code == indie::Event::ControllerCode::X_BUTTON)
        && !_is_player2_playing) {
        std::unique_ptr<ecs::entity::Entity> player2 = std::make_unique<ecs::entity::Entity>();
        player2->addComponent<ecs::component::Transform>(
            static_cast<float>(600.0), static_cast<float>(300.0), static_cast<float>(0.0), static_cast<float>(0.0));
        player2->addComponent<ecs::component::Drawable2D>(
            "", static_cast<float>(500.0), static_cast<float>(300.0), RED);
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
            static_cast<float>(680.0), static_cast<float>(500.0), static_cast<float>(0.0), static_cast<float>(0.0));
        ready->addComponent<ecs::component::Drawable2D>("READY", static_cast<float>(40.0), BLACK);
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
}

void indie::menu::PreMenuScreen::handlePlayer3(indie::Event &event)
{
    if (event.controller[2].connected && (event.controller[2].code == indie::Event::ControllerCode::X_BUTTON)
        && !_is_player3_playing) {
        std::unique_ptr<ecs::entity::Entity> player3 = std::make_unique<ecs::entity::Entity>();
        player3->addComponent<ecs::component::Transform>(
            static_cast<float>(1000.0), static_cast<float>(300.0), static_cast<float>(0.0), static_cast<float>(0.0));
        player3->addComponent<ecs::component::Drawable2D>(
            "", static_cast<float>(500.0), static_cast<float>(300.0), GREEN);
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
            static_cast<float>(1080.0), static_cast<float>(500.0), static_cast<float>(0.0), static_cast<float>(0.0));
        ready->addComponent<ecs::component::Drawable2D>("READY", static_cast<float>(40.0), BLACK);
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
}

void indie::menu::PreMenuScreen::handlePlayer4(indie::Event &event)
{
    if (event.controller[3].connected && (event.controller[3].code == indie::Event::ControllerCode::X_BUTTON)
        && !_is_player4_playing) {
        std::unique_ptr<ecs::entity::Entity> player4 = std::make_unique<ecs::entity::Entity>();
        player4->addComponent<ecs::component::Transform>(
            static_cast<float>(1400.0), static_cast<float>(300.0), static_cast<float>(0.0), static_cast<float>(0.0));
        player4->addComponent<ecs::component::Drawable2D>(
            "", static_cast<float>(500.0), static_cast<float>(300.0), YELLOW);
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
            static_cast<float>(1480.0), static_cast<float>(500.0), static_cast<float>(0.0), static_cast<float>(0.0));
        ready->addComponent<ecs::component::Drawable2D>("READY", static_cast<float>(40.0), BLACK);
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
}
