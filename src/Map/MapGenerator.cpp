/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-titouan.deschanels
** File description:
** main
*/

#include "MapGenerator.hpp"

void MapGenerator::createWall()
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

void MapGenerator::placeBoxes()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if ((i % 2 != 0) && (j != 0) && (j != 20))
                _map[i][j] = BOXE;
            if ((i % 2 == 0) && (j % 2 != 0) && (i != 0) && (i != 20))
                _map[i][j] = BOXE;
        }
    }
}

void MapGenerator::placeRandomEmptySpace()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            if (_map[i][j] == BOXE) {
                int rd = generateRandomNumber(10);
                if (rd == 1 || rd == 2)
                    _map[i][j] = EMPTY;
            }
        }
    }
}

void MapGenerator::placeBonusBoxes()
{
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            int count = countBonusOnLine(i);
            if (count == 2)
                j++;
            else if (_map[i][j] == BOXE) {
                int rd = generateRandomNumber(50);
                if (rd == 1 || rd == 11 || rd == 21) {
                    _map[i][j] = SPEED_BOXE;
                } else if (rd == 2 || rd == 22 || rd == 32) {
                    _map[i][j] = BOMB_BOXE;
                } else if (rd == 3) {
                    _map[i][j] = WALL_PASS_BOXE;
                }
            }
        }
    }
}

void MapGenerator::placePlayers()
{
    _map[1][1] = PLAYER1;
    _map[1][2] = EMPTY;
    _map[2][1] = EMPTY;
    _map[1][19] = PLAYER2;
    _map[1][18] = EMPTY;
    _map[2][19] = EMPTY;
    _map[19][1] = PLAYER3;
    _map[19][2] = EMPTY;
    _map[18][1] = EMPTY;
    _map[19][19] = PLAYER4;
    _map[18][19] = EMPTY;
    _map[19][18] = EMPTY;
}

int MapGenerator::countBonusOnLine(int i)
{
    int count = 0;
    for (int k = 0; k < 21; k++) {
        if (_map[i][k] == SPEED_BOXE || _map[i][k] == BOMB_BOXE || _map[i][k] == WALL_PASS_BOXE)
            count++;
    }
    return count;
}

int MapGenerator::generateRandomNumber(int nbrMax)
{
    if (nbrMax == 0)
        return 0;
    return (rand() % nbrMax) + 1;
}