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
        /// @brief Player class
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
            /// @return Player Player object
            Player &operator=(const Player &player) = default;

            /// @brief Destroy the Player object
            ~Player() = default;
            /**
             * @brief Get if the player is alive or not.
             * 
             * @return true Player is alive
             * @return false Player is not alive
             */
            bool getIsAlive() const;
            /**
             * @brief Get if the player is playing or not.
             * 
             * @return true Player is playing
             * @return false Player is not playing
             */
            bool getIsPlaying() const;
            /**
             * @brief Get if the player can cross walls
             * 
             * @return true Player can cross walls
             * @return false Player can't cross walls
             */
            bool getCrossWalls() const;
            /**
             * @brief Get the controller id linked to the player
             * 
             * @return int Controller ID
             */
            short unsigned int getControllerId() const;
            /**
             * @brief Get the speed of the player
             * 
             * @return int Player's speed
             */
            short unsigned int getSpeed() const;
            /**
             * @brief Get the bomb radius of the player
             * 
             * @return int Player's bomb radius
             */
            short unsigned int getBombRadius() const;
            /**
             * @brief Get the bomb stock of the player
             * 
             * @return int Player's bomb stock
             */
            short unsigned int getBombStock() const;
            /**
             * @brief Get the max bomb stock of the player
             * 
             * @return int Player's max bomb stock
             */
            short unsigned int getMaxBombStock() const;
            /**
             * @brief Get the number of bomb stock bonus
             * 
             * @return int Bomb stock bonus's number
             */
            short unsigned int getNbBombStockBonus() const;
            /**
             * @brief Get the number of bomb radius bonus
             * 
             * @return int Bomb radius bonus's number
             */
            short unsigned int getNbBombRadiusBonus() const;
            /**
             * @brief Get the number of speed bonus
             * 
             * @return int Speed bonus's number
             */
            short unsigned int getNbSpeedBonus() const;
            /**
             * @brief Get the player's color
             * 
             * @return Color Player's color
             */
            Color getColor() const;
            /**
             * @brief Get the player's position
             * 
             * @return vec2u Player's position
             */
            vec2u getPos() const;
            /**
             * @brief Set player's alive state
             * 
             * @param isAlive Player's state
             */
            void setIsAlive(bool isAlive);
            /**
             * @brief Set player's playing state
             * 
             * @param isPlaying Player's state
             */
            void setIsPlaying(bool isPlaying);
            /**
             * @brief Set player's crossWalls state
             * 
             * @param crossWalls Player's state
             */
            void setCrossWalls(bool crossWalls);
            /**
             * @brief Set player's controllerId
             * 
             * @param value Controller Id
             */
            void setControllerId(short unsigned int value);
            /**
             * @brief Set player's speed
             * 
             * @param value Speed value
             */
            void setSpeed(short unsigned int value);
            /**
             * @brief Change player's speed
             * 
             * @param difference Speed value difference
             */
            void changeSpeed(short int difference);
            /**
             * @brief Set player's bomb radius
             * 
             * @param value Bomb radius value
             */
            void setBombRadius(short unsigned int value);
            /**
             * @brief Set player's bomb stock
             * 
             * @param value Bomb stock value
             */
            void setBombStock(short unsigned int value);
            /**
             * @brief Set player's max bomb stock
             * 
             * @param value Max bomb stock value
             */
            void setMaxBombStock(short unsigned int value);
            /**
             * @brief Set Bomb stock bonus number
             * 
             * @param value Bomb stock bonus value
             */
            void setNbBombStockBonus(short unsigned int value);
            /**
             * @brief Set Bomb radius bonus number
             * 
             * @param value Bomb radius bonus value
             */
            void setNbBombRadiusBonus(short unsigned int value);
            /**
             * @brief Set speed bonus number
             * 
             * @param value Speed bonus value
             */
            void setNbSpeedBonus(short unsigned int value);
            /**
             * @brief Set Player's color
             * 
             * @param color Player's color
             */
            void setColor(Color color);
            /**
             * @brief Set player's position
             * 
             * @param position Player's position
             */
            void setPos(vec2u position);

          private:
            /// @brief Is the player alive ?
            bool _isAlive;
            /// @brief Is the player playing ?
            bool _isPlaying;
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
