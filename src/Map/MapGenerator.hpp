/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-titouan.deschanels
** File description:
** mapGenerator
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

#define WALL           '#'
#define EMPTY          ' '
#define BOX           '.'
#define SPEED_BOX     'S'
#define BOMB_BOX      'B'
#define WALL_PASS_BOX 'T'
#define PLAYER1        '1'
#define PLAYER2        '2'
#define PLAYER3        '3'
#define PLAYER4        '4'

class MapGenerator {
  public:
    // Ctor & Dtor
    MapGenerator() = default;
    ~MapGenerator() = default;
    MapGenerator(const MapGenerator &component) = default;
    MapGenerator &operator=(const MapGenerator &component) = default;

    // Members functions
    void createWall();
    void placeBoxes();
    void placeRandomEmptySpace();
    void placeBonusBoxes();
    void placePlayers();
    int countBonusOnLine(int i);
    int generateRandomNumber(int nbrMax);

    // Getters & Setters
    inline const std::vector<std::vector<char>> &getMap(void) const
    {
        return _map;
    };

  private:
    std::vector<std::vector<char>> _map;
};

#endif /* !MAPGENERATOR_HPP_ */
