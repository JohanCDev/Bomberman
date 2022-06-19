/**
 * @file ISystem.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Interface for all systems classes
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "../component/IComponent.hpp"
#include "../entity/Entity.hpp"

namespace indie
{
    namespace ecs
    {
        namespace system
        {
            /**
             * @brief Enum for system types
             * 
             */
            enum SystemType {
                DRAWABLE3DSYSTEM,
                DRAWABLE2DSYSTEM,
                MOVEMENTSYSTEM,
                COLLIDESYSTEM,
                SOUNDSYSTEM,
                EXPLODABLESYSTEM,
                OBJECTSYSTEM
            };
            /// @brief System
            class ISystem {
              public:
                /**
                 * @brief Destroy system.
                 */
                virtual ~ISystem() = default;

                /**
                 * @brief Update all the entities with the system properties.
                 *
                 * @param entities vector of entites to update
                 */
                virtual void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities) = 0;

                /**
                 * @brief Get the type of system.
                 *
                 * @return enum value correspond to the type of system
                 */
                virtual indie::ecs::system::SystemType getSystemType() const = 0;

              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace indie

#endif /* !SYSTEM_HPP_ */
