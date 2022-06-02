/*
** EPITECH PROJECT, 2022
** Explodable
** File description:
** Explodable
*/

#ifndef EXPLODABLE_HPP_
#define EXPLODABLE_HPP_

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            class Explodable : public IComponent {
              public:
                Explodable();
                Explodable(float range, int explosionTime);
                ~Explodable();

                indie::ecs::component::compoType getType() const;

                void setRange(float range);
                void setExplosionTime(int explosionTime);
                void setDropped(bool dropped);

                float getRange() const;
                int getExplosionTime() const;
                bool getDropped() const;

              private:
                float _range;
                int _explosionTime;
                bool _dropped;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !EXPLODABLE_HPP_ */
