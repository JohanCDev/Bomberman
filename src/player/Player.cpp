/**
 * @file Player.cpp
 * @author Johan Chrillesen (johan.chrillesen@epitech.eu)
 * @brief Player class
 * @version 0.1
 * @date 2022-06-07
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Player.hpp"

namespace indie
{
    namespace player
    {
        Player::Player(Color color, short unsigned int controllerId, bool isAlive, bool isPlaying,
            unsigned short bombRadius, unsigned short bombStock, unsigned short maxBombStock, unsigned int speed)
        {
            this->_color = color;
            this->_controllerId = controllerId;
            this->_isAlive = isAlive;
            this->_isPlaying = isPlaying;
            this->_bombRadius = bombRadius;
            this->_bombStock = bombStock;
            this->_maxBombStock = maxBombStock;
            this->_speed = speed;
        }

        ////////////////////////////////////////////
        // Getters                                //
        ////////////////////////////////////////////

        bool Player::getIsAlive() const
        {
            return (this->_isAlive);
        }

        bool Player::getIsPlaying() const
        {
            return (this->_isPlaying);
        }

        short unsigned int Player::getBombRadius() const
        {
            return (this->_bombRadius);
        }

        short unsigned int Player::getBombStock() const
        {
            return (this->_bombStock);
        }

        short unsigned int Player::getMaxBombStock() const
        {
            return (this->_maxBombStock);
        }

        short unsigned int Player::getSpeed() const
        {
            return (this->_speed);
        }

        short unsigned int Player::getControllerId() const
        {
            return (this->_controllerId);
        }

        Color Player::getColor() const
        {
            return (this->_color);
        }

        ////////////////////////////////////////////
        // Setters                                //
        ////////////////////////////////////////////

        void Player::setIsAlive(bool isAlive)
        {
            this->_isAlive = isAlive;
        }

        void Player::setIsPlaying(bool isPlaying)
        {
            this->_isPlaying = isPlaying;
        }

        void Player::setControllerId(short unsigned int controllerId)
        {
            this->_controllerId = controllerId;
        }

        void Player::setBombRadius(short unsigned int value)
        {
            this->_bombRadius = value;
        }

        void Player::setBombStock(short unsigned int value)
        {
            this->_bombStock = value;
        }

        void Player::setMaxBombStock(short unsigned int value)
        {
            this->_maxBombStock = value;
        }

        void Player::setSpeed(short unsigned int value)
        {
            this->_speed = value;
        }

        void Player::changeSpeed(short int difference)
        {
            this->_speed += difference;
        }

        void Player::setColor(Color color)
        {
            this->_color = color;
        }
    } // namespace player
} // namespace indie