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
            /**
             * @brief Construct a new Player object
             *
             * @param color Player color
             * @param controllerId Player controller Id
             * @param isAlive Player is alive or not
             * @param isPlaying Player is playing or not
             * @param bombRadius Player's bomb radius
             * @param bombStock Player's bomb stock
             * @param maxBombStock Player's max bomb stock
             * @param speed Player's speed
             */
            Player(Color color, short unsigned int controllerId, bool isAlive = true, bool isPlaying = false,
                unsigned short bombRadius = 1, unsigned short bombStock = 2, unsigned short maxBombStock = 2,
                unsigned int speed = 10);

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
             * @brief Get the Controller Id
             *
             * @return short unsigned int Controller Id
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
             * @brief Get the Color
             *
             * @return Color Color object
             */
            Color getColor() const;
            /// Set if the player is alive or not.
            /// @param isAlive new value.
            void setIsAlive(bool isAlive);
            /**
             * @brief Set player's playing state
             *
             * @param isPlaying Player's state
             */
            void setIsPlaying(bool isPlaying);
            /// Set the controllerId linked to the player.
            /// @param value new value.
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
             * @brief Set the Color
             *
             * @param color New color
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
            /// Color of the player
            Color _color;
        };
    } // namespace player
} // namespace indie

#endif /* !PLAYER_HPP_ */
