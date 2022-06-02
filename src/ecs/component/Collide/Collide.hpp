/*
** EPITECH PROJECT, 2022
** Collide
** File description:
** Collide
*/

#pragma once

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            class Collide : public IComponent {
              public:
                Collide();
                ~Collide();

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                indie::ecs::component::compoType getType() const;

                bool checkCollision(indie::ecs::component::Collide *otherEntityCollide);

                void setXCollide(bool collide);
                void setYCollide(bool collide);

                bool getXCollide() const;
                bool getYCollide() const;

              private:
                bool _xCollide;
                bool _yCollide;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
