/**
 * @file Collide.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Collide system header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
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
            /// @brief Collide system
            class Collide : public ISystem {
              public:
                /**
                 * @brief Construct a new Collide object
                 * 
                 */
                Collide();
                /**
                 * @brief Destroy the Collide object
                 * 
                 */
                ~Collide();
                /**
                 * @brief Update all the entities with the system properties.
                 *
                 * @param entities vector of entites to update
                 */
                void update(std::vector<std::unique_ptr<indie::ecs::entity::Entity>> &entities);
                /**
                 * @brief Check collisions between cubes
                 * 
                 * @param drawable The drawable component
                 * @param collide The collide component
                 * @param transform The transform component
                 * @param otherEntityCollide The other collide component
                 * @param otherEntityDrawable The other drawable component
                 * @param otherTransform The other transform component
                 */
                void checkCubeCollision(auto drawable, auto collide, indie::ecs::component::Transform *transform,
                    auto otherEntityCollide, auto otherEntityDrawable,
                    indie::ecs::component::Transform *otherTransform);
                /**
                 * @brief Check collisions between cubes
                 * 
                 * @param collide The collide component
                 * @param transform The transform component
                 * @param drawable The drawable component
                 * @param otherEntityTransform The other transform component
                 * @param otherEntityCollide The other collide component
                 * @param otherEntityDrawable The other drawable component
                 */
                void checkSphereCollision(auto collide, auto transform, auto drawable,
                    indie::ecs::component::Transform *otherEntityTransform,
                    indie::ecs::component::Collide *otherEntityCollide,
                    indie::ecs::component::Drawable3D *otherEntityDrawable);

                /**
                 * @brief Get the type of system.
                 *
                 * @return indie::ecs::system::SystemType SystemType
                 */
                indie::ecs::system::SystemType getSystemType() const;

              protected:
              private:
            };
        } // namespace system
    }     // namespace ecs
} // namespace indie

#endif /* !COLLIDE_HPP_ */
