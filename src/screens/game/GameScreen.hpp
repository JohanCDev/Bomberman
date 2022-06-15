/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** GameScreen
*/

#ifndef GAMESCREEN_HPP_
#define GAMESCREEN_HPP_

#include <memory>
#include <vector>

#include "../../ecs/entity/Entity.hpp"
#include "../../ecs/system/ISystem.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Collide/Collide.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"
#include "../ecs/system/Draw3D/Draw3D.hpp"
#include "../ecs/system/Explodable/Explodable.hpp"
#include "../ecs/system/Movement/Movement.hpp"
#include "../ecs/system/Sound/Sound.hpp"
#include "events.hpp"
#include "uiPlayerDisplay/UIPlayerDisplay.hpp"

namespace indie
{
    namespace menu
    {
        class GameScreen : public IScreen {
          public:
            GameScreen(std::vector<player::Player> *players, std::vector<std::unique_ptr<indie::ecs::entity::Entity>> *_soundEntities, std::vector<std::unique_ptr<indie::ecs::system::ISystem>> *soundSystems);
            ~GameScreen() = default;
            void init() override;
            void draw() override;
            void update() override;
            int handleEvent(indie::Event &event) override;
            void handleMultipleController(indie::Event &event, int index, indie::ecs::entity::entityType type);
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            void removeEntity(std::unique_ptr<indie::ecs::entity::Entity> entity);
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;
            indie::raylib::Camera3D getCamera() const;
            void getPlayersPlaying(bool is_p1_playing, bool is_p2_playing, bool is_p3_playing, bool is_p4_playing);
            void initMap(std::vector<std::vector<char>> map);
            void initEntity();

          private:
            std::vector<player::Player> *_players;
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> *_soundEntities;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> *_soundSystems;
            std::vector<std::unique_ptr<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>> _infoPlayers;
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            indie::raylib::Camera3D _camera;

            bool _player1_blue;
            bool _player2_red;
            bool _player3_green;
            bool _player4_yellow;
        };
    } // namespace menu
} // namespace indie

#endif /* !MENUSCREEN_HPP_ */
