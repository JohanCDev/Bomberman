/**
 * @file MapGenerator.hpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The generator for the map of the game
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MAPGENERATOR_HPP_
#define MAPGENERATOR_HPP_

// OWN INCLUDE

// BASIC INCLUDE
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

/**
 * @brief Macro for wall
 * 
 */
#define WALL        '#'
/**
 * @brief Macro for nothing
 * 
 */
#define EMPTY       ' '
/**
 * @brief Macro for boxes
 * 
 */
#define BOX         '.'
/**
 * @brief Macro for speed bonus
 * 
 */
#define SPEED_BOX   'S'
/**
 * @brief Macro for bomb box bonus
 * 
 */
#define BOMB_BOX    'B'
/**
 * @brief Macro for bomb radius bonus
 * 
 */
#define BOMB_RADIUS 'R'
/**
 * @brief Macro for player1
 * 
 */
#define PLAYER1     '1'
/**
 * @brief Macro for player2
 * 
 */
#define PLAYER2     '2'
/**
 * @brief Macro for player3
 * 
 */
#define PLAYER3     '3'
/**
 * @brief Macro for player4
 * 
 */
#define PLAYER4     '4'

namespace indie
{
    namespace map
    {
        /**
         * @brief Map generator class implementation
         */
        class MapGenerator {
          public:
            /**
             * @brief Construct a new Map Generator object
             */
            MapGenerator() = default;
            /**
             * @brief Destroy the Map Generator object
             */
            ~MapGenerator() = default;
            /**
             * @brief Construct a new Map Generator object from a copy
             *
             * @param component to copy
             */
            MapGenerator(const MapGenerator &component) = default;
            /**
             * @brief Copy a map generator object
             *
             * @param component to copy
             * 
             * @return MapGenerator MapGenerator object
             */
            MapGenerator &operator=(const MapGenerator &component) = default;

            /**
             * @brief Create a Wall
             */
            void createWall();
            /**
             * @brief Place a box
             */
            void placeBoxes();
            /**
             * @brief Place an empty space
             */
            void placeRandomEmptySpace();
            /**
             * @brief Place a bonus box
             */
            void placeBonusBoxes();
            /**
             * @brief Place the players
             */
            void placePlayers();
            /**
             * @brief Count the bonuses on a line
             *
             * @param i line to check
             * @return int Number of bonuses on the line
             */
            int countBonusOnLine(int i);
            /**
             * @brief Generate a random number
             *
             * @param nbrMax max number generated
             * @return int the number generated
             */
            int generateRandomNumber(int nbrMax);

            /**
             * @brief Get the Map object
             *
             * @return const std::vector<std::vector<char>>& the map
             */
            inline const std::vector<std::vector<char>> &getMap(void) const
            {
                return _map;
            };

          private:
            std::vector<std::vector<char>> _map;
        };
    } // namespace map
} // namespace indie

#endif /* !MAPGENERATOR_HPP_ */
