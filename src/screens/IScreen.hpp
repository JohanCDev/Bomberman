/**
 * @file SetSoundScreen.cpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The Screen Inteface to manipulate all the screens
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef ISCREEN_HPP_
#define ISCREEN_HPP_

#include <memory>
#include "../ecs/entity/Entity.hpp"
#include "../ecs/system/ISystem.hpp"
#include "events.hpp"

namespace indie
{
    /// @brief IScreen class
    class IScreen {
      public:
        /// @brief Destructor
        virtual ~IScreen() = default;
        /// @brief Initialize the screen
        virtual void init() = 0;
        /// @brief Draw the screen
        virtual void draw() = 0;
        /// @brief Update the screen
        virtual void update() = 0;
        /// @brief handle events
        virtual int handleEvent(indie::Event &event) = 0;
        /// @brief Add an entity to the screen
        virtual void addEntity(std::unique_ptr<indie::ecs::entity::Entity> entity) = 0;
        /// @brief Add a system to the screen
        virtual void addSystem(std::unique_ptr<indie::ecs::system::ISystem> system) = 0;
    };
} // namespace indie

#endif /* !ISCREEN_HPP_ */
