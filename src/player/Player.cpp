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
        Player::Player(Color color, short unsigned int controllerId, vec2u pos)
        {
            this->_color = color;
            this->_controllerId = controllerId;
            this->_pos = pos;
            this->_isAlive = true;
            this->_bombRadius = 1;
            this->_bombStock = 4;
            this->_maxBombStock = 4;
            this->_crossWalls = false;
            this->_nbBombRadiusBonus = 0;
            this->_nbBombStockBonus = 0;
            this->_nbSpeedBonus = 0;
            this->_speed = 10;
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

        bool Player::getCrossWalls() const
        {
            return (this->_crossWalls);
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

        short unsigned int Player::getNbBombRadiusBonus() const
        {
            return (this->_nbBombRadiusBonus);
        }

        short unsigned int Player::getNbBombStockBonus() const
        {
            return (this->_nbBombStockBonus);
        }

        short unsigned int Player::getNbSpeedBonus() const
        {
            return (this->_nbSpeedBonus);
        }

        vec2u Player::getPos() const
        {
            return (this->_pos);
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

        void Player::setCrossWalls(bool crossWalls)
        {
            this->_crossWalls = crossWalls;
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

        void Player::setNbBombRadiusBonus(short unsigned int value)
        {
            this->_nbBombRadiusBonus = value;
        }

        void Player::setNbBombStockBonus(short unsigned int value)
        {
            this->_nbBombStockBonus = value;
        }

        void Player::setNbSpeedBonus(short unsigned int value)
        {
            this->_nbSpeedBonus = value;
        }

        void Player::setPos(vec2u position)
        {
            this->_pos = position;
        }

        void Player::setColor(Color color)
        {
            this->_color = color;
        }
    } // namespace player
} // namespace indie