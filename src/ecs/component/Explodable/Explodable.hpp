/**
 * @file Explodable.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Explodable component header file
 * @version 0.1
 * @date 2022-06-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <chrono>
#include "../../entity/Entity.hpp"
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
                void setExplode(bool explode);
                void setPlayer(int player);

                float getRange() const;
                int getExplosionTime() const;
                bool getDropped() const;
                bool getExploded() const;
                bool getExplode() const;
                int getPlayer() const;
                std::chrono::time_point<std::chrono::system_clock> getTStart() const;
                std::chrono::seconds getSeconds() const;

              private:
                float _range;
                int _explosionTime;
                bool _dropped;
                bool _explode;
                bool _exploded;
                std::chrono::time_point<std::chrono::system_clock> _tStart;
                std::chrono::seconds _seconds;
                int _player;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
