/**
 * @file GameScreen.hpp
 * @author Victor & Henri(victor.harri-chal@epitech.eu & henri.chauvet@epitech.eu)
 * @brief The screen of the game
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
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
            /**
             * @brief Construct a new Game Screen object
             * 
             * @param players Vector of players in the game
             */
            GameScreen(std::vector<player::Player> *players);
            /**
             * @brief Destroy the Game Screen object
             * 
             */
            ~GameScreen() = default;
            /**
             * @brief Init the Game Screen
             * 
             */
            void init() override;
            /**
             * @brief Draw the Game Screen
             * 
             */
            void draw() override;
            /**
             * @brief Update the Game Screen
             * 
             */

            void update() override;
            /**
             * @brief Handle event for the Game Screen
             * 
             * @param event the event to be handled
             * @return int The scene number
             */
            int handleEvent(indie::Event &event) override;
            /**
             * @brief Handle multiple input from multiple controllers / players
             * 
             * @param event The event to handle
             * @param index The controller number ( 0,1,2,3)
             * @param type The type of entity (Player1, 2, 3 ,4)
             */
            void handleMultipleController(indie::Event &event, int index, indie::ecs::entity::entityType type);
            /**
             * @brief Add entity for the Game Screen
             * 
             * @param entity the entity to add for the Game Screen
             */
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            /**
             * @brief Remove entity from the Game Screen
             * 
             * @param entity the entity to remove from the Game Screen
             */
            void removeEntity(std::unique_ptr<indie::ecs::entity::Entity> entity);
            /**
             * @brief Add a system for the Game Screen
             * 
             * @param system the system to add for the Game Screen
             */
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;
            /**
             * @brief Get the Camera object
             * 
             * @return indie::raylib::Camera3D 
             */
            indie::raylib::Camera3D getCamera() const;
            /**
             * @brief Get the Players state (Playing or not)
             * 
             * @param is_p1_playing is playing or not
             * @param is_p2_playing is playing or not
             * @param is_p3_playing is playing or not
             * @param is_p4_playing is playing or not
             */
            void getPlayersPlaying(bool is_p1_playing, bool is_p2_playing, bool is_p3_playing, bool is_p4_playing);
            /**
             * @brief Init the map for the Game Screen
             * 
             * @param map Vector of vector of char, to draw the map
             */
            void initMap(std::vector<std::vector<char>> map);
            /**
             * @brief Init entities of the Game Screen
             * 
             */
            void initEntity();

          private:
            /**
             * @brief Vector of players
             * 
             */
            std::vector<player::Player> *_players;
            /**
             * @brief Vector of entities of the Game Screen
             * 
             */
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            /**
             * @brief Vector of infoPlayers of the Game Screen
             * 
             */
            std::vector<std::unique_ptr<indie::screens::game::uiPlayerDisplay::UIPlayerDisplay>> _infoPlayers;
            /**
             * @brief Vector of systems of the Game Screen
             * 
             */
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            /**
             * @brief 3D Camera for the game screen
             * 
             */
            indie::raylib::Camera3D _camera;
            /**
             * @brief Player1 is alive or not
             * 
             */
            bool _player1_blue;
            /**
             * @brief Player2 is alive or not
             * 
             */
            bool _player2_red;
            /**
             * @brief Player3 is alive or not
             * 
             */
            bool _player3_green;
            /**
             * @brief Player4 is alive or not
             * 
             */
            bool _player4_yellow;
        };
    } // namespace menu
} // namespace indie

#endif /* !MENUSCREEN_HPP_ */
