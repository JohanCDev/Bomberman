/*
** EPITECH PROJECT, 2022
** Movement
** File description:
** Movement
*/

#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_

#include "../ISystem.hpp"

namespace indie
{
    namespace ecs
    {
        namespace system
        {
            class MovementSystem : public ISystem {
              public:
                /**
                 * @brief Create new movement system.
                 */
                MovementSystem()
                {
                }
                /**
                 * @brief Destroy movement system.
                 */
                ~MovementSystem()
                {
                }

                /**
                 * @brief Update all position of given entities.
                 *
                 * @param entites vector of entities.
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

#endif /* !MOVEMENT_HPP_ */
