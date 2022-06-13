/*
** EPITECH PROJECT, 2022
** Explodable
** File description:
** Explodable
*/

#pragma once

#include <chrono>
#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            /// @brief Explodable component
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
                std::chrono::time_point<std::chrono::system_clock> getTStart() const;
                std::chrono::seconds getSeconds() const;

              private:
                float _range;
                int _explosionTime;
                bool _dropped;
                bool _exploded;
                std::chrono::time_point<std::chrono::system_clock> _tStart;
                std::chrono::seconds _seconds;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
