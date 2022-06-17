/**
 * @file Collide.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Collide component header file
 * @version 0.1
 * @date 2022-06-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            /// @brief Collide component
            class Collide : public IComponent {
              public:
                /**
                 * @brief Create new collide component.
                 */
                Collide();
                /**
                 * @brief Destructor.
                 */
                ~Collide();
                /**
                 * @brief Get type of the component.
                 *
                 * @return indie::ecs::component::compoType CompoType of the component.
                 */
                indie::ecs::component::compoType getType() const;
                /**
                 * @brief Check if there is a collision with other entity 
                 * 
                 * @param otherEntityCollide The other component
                 * @return true There is a collision
                 * @return false There isn't a collision
                 */
                bool checkCollision(indie::ecs::component::Collide *otherEntityCollide);
                /**
                 * @brief Set the state of collision
                 * 
                 * @param collide True for collision, False for no collision
                 */
                void setCollide(bool collide);
                /**
                 * @brief Get if the entity has a Collide component
                 * 
                 * @return true Entity has the collide component
                 * @return false Entity hasn't the collide component
                 */
                bool getCollide() const;

              private:
                /**
                 * @brief Collision state value
                 * 
                 */
                bool _collide;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
