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
                 * @return the compoType value of the component.
                 */
                indie::ecs::component::compoType getType() const;

                bool checkCollision(indie::ecs::component::Collide *otherEntityCollide);

                void setCollide(bool collide);
                bool getCollide() const;

              private:
                bool _collide;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
