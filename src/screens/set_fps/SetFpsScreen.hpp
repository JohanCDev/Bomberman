/**
 * @file SetFpsScreen.hpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen to change FPS of the game
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SETFPSSCREEN_HPP_
#define SETFPSSCREEN_HPP_

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
         * @brief Class for the Set Fps Screen
         *
         */
        class SetFpsScreen : public IScreen {
            /**
             * @brief Cursor enum for fps choice
             *
             */
            enum cursorPosition { FPS_30 = 0, FPS_60 = 1 };

          public:
            /**
             * @brief Set the Fps Screen object
             *
             */
            SetFpsScreen();
            /**
             * @brief Destroy the Set Fps Screen object
             *
             */
            ~SetFpsScreen() = default;
            /**
             * @brief Init the Fps Screen
             *
             */
            void init() override;
            /**
             * @brief Draw the Fps Screen
             *
             */
            void draw() override;
            /**
             * @brief Update the Fps Screen
             *
             */
            void update() override;
            /**
             * @brief Handle event for Fps Screen
             *
             * @param event Event to be handled
             * @return int The scene number
             */
            int handleEvent(indie::Event &event) override;
            /**
             * @brief Add Entity for the Fps Screen
             *
             * @param entity Entity to add for the Fps Screen
             */
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            /**
             * @brief Add System for the Fps Screen
             *
             * @param system System to add for the Fps Screen
             */
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;
            /**
             * @brief Set the scene to the previous one
             *
             * @param scene The scene to draw
             */
            void setPreviousScene(bool scene);
            /**
             * @brief Check where the cursor is
             *
             * @param direction True is UP and False is DOWN
             * @return int The index for the button
             */
            int checkCursorPosition(bool direction);

          private:
            /**
             * @brief Vector of entities for the Fps Screen
             *
             */
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            /**
             * @brief Vector of systems for the Fps Screen
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
