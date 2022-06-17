/**
 * @file MapGenerator.cpp
 * @author Victor (victor.harri-chal@epitech.eu)
 * @brief The generator for the map of the game
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "MapGenerator.hpp"

void indie::map::MapGenerator::createWall()
{
    srand(time(NULL));
    for (int i = 0; i < 21; i++) {
        std::vector<char> tmp;
        for (int j = 0; j < 21; j++)
            tmp.push_back(WALL);
        _map.push_back(tmp);
    }
    placeBoxes();
    placeRandomEmptySpace();
    placeBonusBoxes();
    placePlayers();
}

void indie::map::MapGenerator::placeBoxes()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if ((i % 2 != 0) && (j != 0) && (j != 20))
                _map[i][j] = BOX;
            if ((i % 2 == 0) && (j % 2 != 0) && (i != 0) && (i != 20))
                _map[i][j] = BOX;
        }
    }
}

void indie::map::MapGenerator::placeRandomEmptySpace()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (_map[i][j] == BOX) {
                int rd = generateRandomNumber(10);
                if (rd == 1 || rd == 2)
                    _map[i][j] = EMPTY;
            }
        }
    }
}

void indie::map::MapGenerator::placeBonusBoxes()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            int count = countBonusOnLine(i);
            if (count == 2)
                j++;
            else if (_map[i][j] == BOX) {
                int rd = generateRandomNumber(35);
                if (rd == 1 || rd == 11 || rd == 21 || rd == 33) {
                    _map[i][j] = SPEED_BOX;
                } else if (rd == 2 || rd == 22 || rd == 32) {
                    _map[i][j] = BOMB_BOX;
                } else if (rd == 3 || rd == 23) {
                    _map[i][j] = BOMB_RADIUS;
                }
            }
        }
    }
}

void indie::map::MapGenerator::placePlayers()
{
    _map[1][1] = PLAYER3;
    _map[1][2] = EMPTY;
    _map[2][1] = EMPTY;
    _map[1][19] = PLAYER4;
    _map[1][18] = EMPTY;
    _map[2][19] = EMPTY;
    _map[19][1] = PLAYER1;
    _map[19][2] = EMPTY;
    _map[18][1] = EMPTY;
    _map[19][19] = PLAYER2;
    _map[18][19] = EMPTY;
    _map[19][18] = EMPTY;
}

int indie::map::MapGenerator::countBonusOnLine(int i)
{
    int count = 0;
    for (int k = 0; k < 21; k++) {
        if (_map[i][k] == SPEED_BOX || _map[i][k] == BOMB_BOX || _map[i][k] == BOMB_RADIUS)
            count++;
    }
    return count;
}

int indie::map::MapGenerator::generateRandomNumber(int nbrMax)
{
    if (nbrMax == 0)
        return 0;
    return (rand() % nbrMax) + 1;
}
