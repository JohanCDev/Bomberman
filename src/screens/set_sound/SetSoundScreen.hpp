/**
 * @file SetSoundScreen.cpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen to change the volume of the sounds of the game
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SETSOUNDSCREEN_HPP_
#define SETSOUNDSCREEN_HPP_

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
         * @brief Class for the Set Sound Screen
         *
         */
        class SetSoundScreen : public IScreen {
            /**
             * @brief Cursor enum for sound choice
             *
             */
            enum cursorPosition {
                SOUND_0 = 0,
                SOUND_25 = 1,
                SOUND_50 = 2,
                SOUND_75 = 3,
                SOUND_100 = 4,
            };

          public:
            /**
             * @brief Set the Sound Screen object
             *
             * @param sounds Vector of sounds entity for screen
             */
            SetSoundScreen(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> *sounds);
            /**
             * @brief Destroy the Set Sound Screen object
             *
             */
            ~SetSoundScreen() = default;
            /**
             * @brief Init the Sound Screen
             *
             */
            void init() override;
            /**
             * @brief Draw the Sound Screen
             *
             */
            /**
             * @brief Draw the Sound Screen
             *
             */
            void draw() override;
            /**
             * @brief Set sounds
             *
             * @param volume Sound volume
             *
             */
            void setSounds(float volume);
            /**
             * @brief Update the Sound Screen
             *
             */
            void update() override;
            /**
             * @brief Handle event for the Sound Screen
             *
             * @param event Event to be handled
             * @return int The Scene Number
             */
            int handleEvent(indie::Event &event) override;
            /**
             * @brief Add entity for the Sound Screen
             *
             * @param entity Entity to add for the Sound Screen
             */
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            /**
             * @brief Add system for the Sound Screen
             *
             * @param system System to add for the Sound Screen
             */
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;
            /**
             * @brief Check where the cursor is
             *
             * @param direction True is UP and False is DOWN
             * @return int The index for the button
             */
            int checkCursorPosition(bool direction);

          private:
            /**
             * @brief Pointer to vector of entitites from the Game
             *
             */
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> *_sounds;
            /**
             * @brief Vector of entities for the Sound Screen
             *
             */
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            /**
             * @brief Vector of systems for the Sound Screen
             *
             */
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
            /**
             * @brief Map of positions of the cursor
             *
             */
            std::map<int, float> _positionsCursor;
            /**
             * @brief Index of the cursor position
             *
             */
            int _cursorPosition;
            /**
             * @brief Index of the last clicked cursor position
             *
             */
            int _lastSeenCursorPos;
        };
    } // namespace menu
} // namespace indie

#endif /* !SetFpsScreen_HPP_ */
