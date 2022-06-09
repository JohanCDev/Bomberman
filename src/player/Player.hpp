/**
 * @file Player.hpp
 * @author Johan Chrillesen (johan.chrillesen@epitech.eu)
 * @brief Player header class
 * @version 0.1
 * @date 2022-06-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Vec2.hpp"

#include <raylib.h>

namespace indie
{
    namespace player
    {
        /// Player class
        class Player {
          public:
            /// @brief Construct a new Player object
            /// @param color color to give
            /// @param controllerId Id of the controller linked to this player
            /// @param pos position of the player
            Player(Color color, short unsigned int controllerId, vec2u pos);

            /// @brief Construct a new Player object
            /// @param player to copy
            Player(const Player &player) = default;

            /// @brief Construct a new Player object
            /// @param player with which it will be initialized
            Player &operator=(const Player &player) = default;

            /// @brief Destroy the Player object
            ~Player() = default;

            /// Get if the player is alive or not.
            bool getIsAlive() const;
            /// Get if the player can cross walls or not.
            bool getCrossWalls() const;
            /// Get the controllerId linked to the player.
            short unsigned int getControllerId() const;
            /// Get the speed of the player.
            short unsigned int getSpeed() const;
            /// Get the bomb radius of the player.
            short unsigned int getBombRadius() const;
            /// Get the bomb stock of the player.
            short unsigned int getBombStock() const;
            /// Get the max bomb stock of the player.
            short unsigned int getMaxBombStock() const;
            /// Get the number of bomb stock bonus of the player.
            short unsigned int getNbBombStockBonus() const;
            /// Get the number of bomb radius bonus that the player have.
            short unsigned int getNbBombRadiusBonus() const;
            /// Get the number of speed bonus that the player have.
            short unsigned int getNbSpeedBonus() const;
            /// Get the color identifier of the player.
            Color getColor() const;
            /// Get the position of the player.
            vec2u getPos() const;

            /// Set if the player is alive or not.
            /// @param isAlive new value.
            void setIsAlive(bool isAlive);
            /// Set if the player can cross walls or not.
            /// @param crossWalls new value.
            void setCrossWalls(bool crossWalls);
            /// Set the controllerId linked to the player.
            /// @param value new value.
            void setControllerId(short unsigned int value);
            /// Set the speed of the player.
            /// @param value new value.
            void setSpeed(short unsigned int value);
            /// Set the bomb radius of the player.
            /// @param value new value.
            void setBombRadius(short unsigned int value);
            /// Set the bomb stock of the player.
            /// @param value new value.
            void setBombStock(short unsigned int value);
            /// Set the max bomb stock of the player.
            /// @param value new value.
            void setMaxBombStock(short unsigned int value);
            /// Set the number of bomb stock bonus of the player.
            /// @param value new value.
            void setNbBombStockBonus(short unsigned int value);
            /// Set the number of bomb radius bonus that the player have.
            /// @param value new value.
            void setNbBombRadiusBonus(short unsigned int value);
            /// Set the number of speed bonus that the player have.
            /// @param value new value.
            void setNbSpeedBonus(short unsigned int value);
            /// Set the color identifier of the player.
            /// @param color new color identifier.
            void setColor(Color color);
            /// Set the position of the player.
            /// @param position new position.
            void setPos(vec2u position);

          private:
            /// @brief Is the player alive ?
            bool _isAlive;
            /// Can the player cross walls ?
            bool _crossWalls;
            /// Id of the controller linked to the player
            short unsigned int _controllerId;
            /// Bomb stock of the player
            short unsigned int _bombStock;
            /// Max bomb stock of the player
            short unsigned int _maxBombStock;
            /// Speed of the player
            short unsigned int _speed;
            /// Radius of a bomb launched by the player
            short unsigned int _bombRadius;
            /// Number of bomb stock bonus collected
            short unsigned int _nbBombStockBonus;
            /// Number of bomb radius bonus collected
            short unsigned int _nbBombRadiusBonus;
            /// Number of speed bonus collected
            short unsigned int _nbSpeedBonus;
            /// Color of the player
            Color _color;
            /// Position of the player
            vec2u _pos;
        };
    } // namespace player
} // namespace indie

#endif /* !PLAYER_HPP_ */
