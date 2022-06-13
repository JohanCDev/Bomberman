/*
** EPITECH PROJECT, 2022
** Collide
** File description:
** Collide
*/

#ifndef COLLIDE_HPP_
#define COLLIDE_HPP_

#include "../ISystem.hpp"

namespace indie
{
    namespace ecs
    {
        namespace system
        {
            class Collide : public ISystem {
              public:
                Collide();
                ~Collide();

                /**
                 * @brief Update all the entities with the system properties.
                 *
                 * @param entities vector of entites to update
                 */
                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities);

                void checkCubeCollision(auto drawable, auto collide, indie::ecs::component::Transform *transform,
                    auto otherEntityCollide, auto otherEntityDrawable,
                    indie::ecs::component::Transform *otherTransform);

                void checkSphereCollision(std::unique_ptr<indie::ecs::entity::Entity> &entity,
                    std::unique_ptr<indie::ecs::entity::Entity> &otherEntity, std::vector<int> &compoToRemove,
                    int &count);

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

#endif /* !COLLIDE_HPP_ */
