/**
 * @file SetMusicScreen.hpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen to change the volume of the music
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SETMUSICSCREEN_HPP_
#define SETMUSICSCREEN_HPP_

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
         * @brief Class for the Set Music Screen
         *
         */
        class SetMusicScreen : public IScreen {
            /**
             * @brief Cursor enum for music choice
             *
             */
            enum cursorPosition {
                MUSIC_0 = 0,
                MUSIC_25 = 1,
                MUSIC_50 = 2,
                MUSIC_75 = 3,
                MUSIC_100 = 4,
            };

          public:
            /**
             * @brief Set the Music Screen object
             *
             * @param musics Map for music on the screen
             *
             */
            SetMusicScreen(std::map<int, indie::raylib::Sound> *musics);
            /**
             * @brief Destroy the Set Music Screen object
             *
             */
            ~SetMusicScreen() = default;
            /**
             * @brief Init the Music Screen
             *
             */
            void init() override;
            /**
             * @brief Draw the Music Screen
             *
             */
            void draw() override;
            /**
             * @brief Update the Music Screen
             *
             */
            void update() override;
            /**
             * @brief Handle event for the Music Screen
             *
             * @param event Event to be handled
             * @return int The scene number
             */
            int handleEvent(indie::Event &event) override;
            /**
             * @brief Add entity for the Music Screen
             *
             * @param entity Entity to add for the Music Screen
             */
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            /**
             * @brief Add system for the Music Screen
             *
             * @param system System to add for the Music Screen
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
             * @brief Pointer of map of Sound from the Game
             *
             */
            std::map<int, indie::raylib::Sound> *_musics;
            /**
             * @brief Vector of entities for the Music Screen
             *
             */
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            /**
             * @brief Vector of systems for the Music Screen
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
