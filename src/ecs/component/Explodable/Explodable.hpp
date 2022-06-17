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
                /**
                 * @brief Construct a new Explodable object
                 * 
                 */
                Explodable();
                /**
                 * @brief Construct a new Explodable object
                 * 
                 * @param range Range of explosion
                 * @param explosionTime Time before explosion
                 */
                Explodable(float range, int explosionTime);
                /**
                 * @brief Destroy the Explodable object
                 * 
                 */
                ~Explodable();
                /**
                 * @brief Get the CompoType of the comoponent
                 * 
                 * @return indie::ecs::component::compoType CompoType of the component
                 */
                indie::ecs::component::compoType getType() const;
                /**
                 * @brief Set the Range of explosion
                 * 
                 * @param range Value for explosion range
                 */
                void setRange(float range);
                /**
                 * @brief Set the time before explosion 
                 * 
                 * @param explosionTime Value for time before explosion
                 */
                void setExplosionTime(int explosionTime);
                /**
                 * @brief Set the state of the bomb
                 * 
                 * @param dropped True if bomb is dropped, False otherwise
                 */
                void setDropped(bool dropped);
                /**
                 * @brief Set the state of the bomb explosion
                 * 
                 * @param exploded True if bomb has exploded , False otherwise
                 */
                void setExploded(bool exploded);
                /**
                 * @brief Set the state of the bomb explosion
                 * 
                 * @param explode True if bomb has exploded , False otherwise
                 */
                void setExplode(bool explode);
                /**
                 * @brief Set the Player to the component
                 * 
                 * @param player The player's number
                 */
                void setPlayer(int player);
                /**
                 * @brief Get the Range of explosion
                 * 
                 * @return float Range of explosion
                 */
                float getRange() const;
                /**
                 * @brief Get the time before explosion
                 * 
                 * @return int Time before explosion
                 */
                int getExplosionTime() const;
                /**
                 * @brief Get the state of the bomb
                 * 
                 * @return true Bomb is dropped
                 * @return false Bomb isn't dropped
                 */
                bool getDropped() const;
                /**
                 * @brief Get the state of the bomb explosion
                 * 
                 * @return true Bomb has exploded
                 * @return false Bomb hasn't exploded
                 */
                bool getExploded() const;
                /**
                 * @brief Get the state of the bomb explosion bis
                 * 
                 * @return true Bomb has exploded
                 * @return false Bomb hasn't exploded
                 */
                bool getExplode() const;
                /**
                 * @brief Get the Player number
                 * 
                 * @return int Player's number
                 */
                int getPlayer() const;
                /**
                 * @brief Get the Time point start 
                 * 
                 * @return std::chrono::time_point<std::chrono::system_clock> Time point start
                 */
                std::chrono::time_point<std::chrono::system_clock> getTStart() const;
                /**
                 * @brief Get the time in seconds from timer
                 * 
                 * @return std::chrono::seconds Time from timer, in seconds
                 */
                std::chrono::seconds getSeconds() const;

              private:
                /**
                 * @brief Value for explosion range
                 * 
                 */
                float _range;
                /**
                 * @brief Value for time before explosion
                 * 
                 */
                int _explosionTime;
                /**
                 * @brief State for bomb
                 * 
                 */
                bool _dropped;
                /**
                 * @brief State for explode
                 * 
                 */
                bool _explode;
                /**
                 * @brief State for bomb explosion
                 * 
                 */
                bool _exploded;
                /**
                 * @brief Time point for explosion time
                 * 
                 */
                std::chrono::time_point<std::chrono::system_clock> _tStart;
                /**
                 * @brief Time in seconds, for explosion time
                 * 
                 */
                std::chrono::seconds _seconds;
                /**
                 * @brief Player's number
                 * 
                 */
                int _player;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie
