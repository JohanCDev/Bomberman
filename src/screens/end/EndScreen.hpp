/**
 * @file EndScreen.cpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The screen for the end of the game
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef END_SCREEN_HPP_
#define END_SCREEN_HPP_

#include <vector>
#include "../../ecs/entity/Entity.hpp"
#include "../IScreen.hpp"
#include "../ecs/system/Draw2D/Draw2D.hpp"

namespace indie
{
    namespace menu
    {
        class EndScreen : public IScreen {
          public:
            /**
             * @brief Construct a new End Screen object
             * 
             */
            EndScreen();
            /**
             * @brief Destroy the End Screen object
             * 
             */
            ~EndScreen() = default;
            /**
             * @brief Init the End screen
             * 
             */
            void init() override;
            /**
             * @brief Draw the end screen
             * 
             */
            void draw() override;
            /**
             * @brief Update all the entities / elements of the end scene
             * 
             */
            void update() override;
            /**
             * @brief 
             * 
             * @param event the event to be handled
             * @return int 1 if "Enter" or "X" is pressed
             */
            int handleEvent(indie::Event &event) override;
            /**
             * @brief 
             * 
             * @param entity the entity to add for the end screen
             */
            void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) override;
            /**
             * @brief 
             * 
             * @param system the system to add for the end screen
             */
            void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) override;

          private:
            /**
             * @brief vector of entities for the end screen
             * 
             */
            std::vector<std::unique_ptr<indie::ecs::entity::Entity>> _entities;
            /**
             * @brief vector of systems for the end screen
             * 
             */
            std::vector<std::unique_ptr<indie::ecs::system::ISystem>> _systems;
        };
    } // namespace menu
} // namespace indie

#endif /* !END_SCREEN_HPP_ */