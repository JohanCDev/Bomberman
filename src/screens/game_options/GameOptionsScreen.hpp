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

#ifndef GAME_OPTIONS_SCREEN_HPP_
#define GAME_OPTIONS_SCREEN_HPP_

#include <map>
#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"

namespace indie
{
    namespace menu
    {
        /**
         * @brief Class for the Game Options Screen
         * 
         */
        class GameOptionsScreen : public IScreen {
          public:
            /**
             * @brief Enum for the Cursor position
             *
             */
            enum cursorPosition {
                RESUME = 0,
                MENU = 1,
                SAVE = 2,
                MUSIC = 3,
                SOUND = 4,
                FPS = 5,
                EXIT = 6,
            };
            /**
             * @brief Construct a new Game Options Screen object
             *
             */
            GameOptionsScreen();
            /**
             * @brief Destroy the Game Options Screen object
             *
             */
            ~GameOptionsScreen() = default;
            /**
             * @brief Init the Game Option Screen
             *
             */
            void init() override;
            /**
             * @brief Draw the Game Option Screen
             *
             */
            void draw() override;
            /**
             * @brief Update the Game Option Screen
             *
             */
            void update() override;
            /**
             * @brief Handle events for the Game Option Screen
             *
             * @param event the event to be handled
             * @return int The scene number
             */
            int handleEvent(indie::Event &event) override;
            /**
             * @brief Add Entity for the Game Option Screen
             *
             * @param entity the entity to add for the Game Option Screen
             */
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            /**
             * @brief Add system for the Game Option Screen
             *
             * @param system the system to remove from the Game Option Screen
             */
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;
            /**
             * @brief Get the Is Game Options Calling object
             *
             * @return if the game option is called or not
             */
            bool getIsGameOptionsCalling() const;
            /**
             * @brief Check where the cursor is
             *
             * @param direction True is UP and False is DOWN
             * @return int The index for the button
             */
            int checkCursorPosition(bool direction);

          private:
            /**
             * @brief Vector of entities for the Game Option Screen
             *
             */
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            /**
             * @brief Vector of systems for the Game Option Screen
             *
             */
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            /**
             * @brief Map of positions of the cursor
             *
             */
            std::map<int, float> _positionsCursor;
            /**
             * @brief Index for the cursor position
             *
             */
            int _cursorPosition;
            /**
             * @brief Is game option called
             *
             */
            bool _isGameOptionsCalling;
        };
    } // namespace menu
} // namespace indie

#endif /* !GAME_OPTIONS_SCREEN_HPP_ */