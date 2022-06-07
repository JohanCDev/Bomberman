/*
** EPITECH PROJECT, 2022
** Explodable
** File description:
** Explodable
*/

#pragma once

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
                void setExploded(bool exploded);

                float getRange() const;
                int getExplosionTime() const;
                bool getDropped() const;
                bool getExploded() const;

              private:
                float _range;
                int _explosionTime;
                bool _dropped;
                bool _exploded;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
