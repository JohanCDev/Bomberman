/*
** EPITECH PROJECT, 2022
** Sound
** File description:
** Sound
*/

#pragma once

#include "../ISystem.hpp"

namespace indie
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Sound system
            class Sound : public ISystem {
              public:
                Sound();
                ~Sound();

                /**
                 * @brief Update all the entities with the system properties.
                 *
                 * @param entities vector of entites to update
                 */
                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities);

                /**
                 * @brief Get the type of system.
                 *
                 * @return enum value correspond to the type of system
                 */
                indie::ecs::system::SystemType getSystemType() const;

              protected:
              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace indie
