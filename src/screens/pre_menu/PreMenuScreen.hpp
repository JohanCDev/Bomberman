/**
 * @file PreMenuScreen.hpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen for the pre-menu
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PRE_MENU_SCREEN_HPP_
#define PRE_MENU_SCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"
#include "../player/Player.hpp"

namespace indie
{
    namespace menu
    {
        /**
         * @brief Class for the Pre-Menu Screen
         * 
         */
        class PreMenuScreen : public IScreen {
          public:
          /**
           * @brief Construct a new Pre Menu Screen object
           * 
           * @param players Vector of player for the game
           */
            PreMenuScreen(std::vector<player::Player> *players);
            /**
             * @brief Destroy the Pre Menu Screen object
             * 
             */
            ~PreMenuScreen() = default;
            /**
             * @brief Init the Pre-Menu Screen
             * 
             */
            void init() override;
            /**
             * @brief Draw the Pre-Menu Screen
             * 
             */
            void draw() override;
            /**
             * @brief Update the Pre-Menu Screen
             * 
             */
            void update() override;
            /**
             * @brief Handle event for the Pre-Menu Screen
             * 
             * @param event Event to be handled
             * @return int The scene number
             */
            int handleEvent(indie::Event &event) override;
            /**
             * @brief Add entity for the Pre-Menu Screen
             * 
             * @param entity Entity to add for the Pre-Menu Screen
             */
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            /**
             * @brief Add system for the Pre-Menu Screen
             * 
             * @param system System to add for the Pre-Menu Screen
             */
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;

            /**
             * @brief Get the Number of players
             * 
             * @return int The numer of players
             */
            int getNbPlayers() const;
            /**
             * @brief Player2 is playing or not
             * 
             * @return true Player2 is playing
             * @return false Player2 is not playing
             */
            bool isPlayer2Playing() const;
            /**
             * @brief Player3 is playing or not
             * 
             * @return true Player3 is playing
             * @return false Player3 is not playing
             */
            bool isPlayer3Playing() const;
            /**
             * @brief Player4 is playing or not
             * 
             * @return true Player4 is playing
             * @return false Player4 is not playing
             */
            bool isPlayer4Playing() const;
            /**
             * @brief Check if the game is ready or not
             * 
             * @return true The game is ready
             * @return false The game is not ready
             */
            bool getIsGameReady() const;
            /**
             * @brief Set the state of the game
             * 
             * @param is_game_ready True for game ready and False for game not ready
             */
            void setIsGameReady(bool is_game_ready);
            /**
             * @brief Check if all players are ready
             * 
             * @return true All players are ready
             * @return false 1 or more player is not ready
             */
            bool check_if_players_are_ready();
            /**
             * @brief Handle Event from player 1
             * 
             * @param event Event to be handled
             */
            void handlePlayer1(indie::Event &event);
            /**
             * @brief Handle Event from player 2
             * 
             * @param event Event to be handled
             */
            void handlePlayer2(indie::Event &event);
            /**
             * @brief Handle Event from player 3
             * 
             * @param event Event to be handled
             */
            void handlePlayer3(indie::Event &event);
            /**
             * @brief Handle Event from player 4
             * 
             * @param event Event to be handled
             */
            void handlePlayer4(indie::Event &event);

          private:
            /**
             * @brief Vector of entities for the Pre-Menu Screen
             * 
             */
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            /**
             * @brief Vector of systems for the Pre-Menu Screen
             * 
             */
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            /**
             * @brief Vector of players for the Pre-Menu Screen
             * 
             */
            std::vector<player::Player> *_players;
            /**
             * @brief Number of players
             * 
             */
            int _nb_players;
            /**
             * @brief Player2 is playing or not
             * 
             */
            bool _is_player2_playing;
            /**
             * @brief Player3 is playing or not
             * 
             */
            bool _is_player3_playing;
            /**
             * @brief Player4 is playing or not
             * 
             */
            bool _is_player4_playing;
            /**
             * @brief Player 1 is ready or not
             * 
             */
            bool _is_player1_ready;
            /**
             * @brief Player 2 is ready or not
             * 
             */
            bool _is_player2_ready;
            /**
             * @brief Player 3 is ready or not
             * 
             */
            bool _is_player3_ready;
            /**
             * @brief Player 4 is ready or not
             * 
             */
            bool _is_player4_ready;

            /**
             * @brief Player 2 position
             * 
             */
            int _player2_pos;
            /**
             * @brief Player 3 position
             * 
             */
            int _player3_pos;
            /**
             * @brief Player 4 position
             * 
             */
            int _player4_pos;
            /**
             * @brief Player 1 "Ready" text symbol position
             * 
             */
            int _player1_ready_pos;
            /**
             * @brief Player 2 "Ready" text symbol position
             * 
             */
            int _player2_ready_pos;
            /**
             * @brief Player 3 "Ready" text symbol position
             * 
             */
            int _player3_ready_pos;
            /**
             * @brief Player 4 "Ready" text symbol position
             * 
             */
            int _player4_ready_pos;
            /**
             * @brief Game is ready or not
             * 
             */
            bool _game_is_ready;
        };
    } // namespace menu
} // namespace indie

#endif /* !PRE_MENU_SCREEN_HPP_ */