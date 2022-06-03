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
                Collide(BoundingBox boundingBox);
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

                void setCollide(bool collide);
                bool getCollide() const;

                BoundingBox getBoundingBox() const;
                void setBoundingBox(BoundingBox boundingBox);

              private:
                bool _collide;
                bool _xCollide;
                bool _yCollide;
                BoundingBox _boundingBox;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
