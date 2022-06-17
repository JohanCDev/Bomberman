/**
 * @file Object.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../ISystem.hpp"

namespace indie
{
    namespace ecs
    {
        namespace system
        {
            /// @brief Movement system
            class ObjectSystem : public ISystem {
              public:
                /**
                 * @brief Create new movement system.
                 */
                ObjectSystem()
                {
                }
                /**
                 * @brief Destroy movement system.
                 */
                ~ObjectSystem()
                {
                }

                /**
                 * @brief Update all position of given entities.
                 *
                 * @param entities vector of entities.
                 */
                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities) override;

                /**
                 * @brief Get the type of system.
                 *
                 * @return enum value correspond to the type of system
                 */
                indie::ecs::system::SystemType getSystemType() const override;

              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace indie
