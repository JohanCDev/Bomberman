/**
 * @file MenuScreen.hpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen for the menu
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MENUSCREEN_HPP_
#define MENUSCREEN_HPP_

#include <map>
#include <memory>
#include <raylib.h>
#include <vector>

#include "../../ecs/entity/Entity.hpp"
#include "../../tools/Tools.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"

namespace indie
{
    namespace menu
    {
        /**
         * @brief Class for the Menu Screen
         * 
         */
        class MenuScreen : public IScreen {
          public:
            /**
             * @brief Cursor enum for the option choice (New game, Load game or exit game)
             * 
             */
            enum cursorPosition { NEW_GAME = 0, LOAD_GAME = 1, EXIT = 2 };
            /**
             * @brief Construct a new Menu Screen object
             * 
             */
            MenuScreen();
            /**
             * @brief Destroy the Menu Screen object
             * 
             */
            ~MenuScreen() = default;
            /**
             * @brief Init the Menu Screen
             * 
             */
            void init() override;
            /**
             * @brief Draw the Menu Screen
             * 
             */
            void draw() override;
            /**
             * @brief Update the Menu Screen
             * 
             */
            void update() override;
            /**
             * @brief Handle event for the Menu Screen
             * 
             * @param event Event to be handled
             * @return int The Scene Number
             */
            int handleEvent(indie::Event &event) override;
            /**
             * @brief Add entity for the Menu Screen
             * 
             * @param entity Entity to add for the Menu Screen
             */
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            /**
             * @brief Add system for the Menu Screen
             * 
             * @param system System to add for the Menu Screen
             */
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;
            /**
             * @brief Set the size of the Menu Screen
             * 
             * @param where Position
             * @param height Height  
             * @param width Width
             */
            void setSize(int where, float height, float width);
            /**
             * @brief Check where the cursor is
             * 
             * @param direction True is UP and False is DOWN
             * @return int The index for the button
             */
            int checkCursorPosition(bool direction);

          private:
            /**
             * @brief Vector of entities for the Menu Screen
             * 
             */
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            /**
             * @brief Vector of systems for the Menu Screen
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
        };
    } // namespace menu
} // namespace indie

#endif /* !MENUSCREEN_HPP_ */
