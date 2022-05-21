/*
** EPITECH PROJECT, 2022
** MapGenerator
** File description:
** main
*/

#include "MapGenerator.hpp"

void print_vector(std::vector<std::vector<char>> const &map)
{
    for (int i = 0; i < 21; i++) {
       for (int j = 0; j < 21; j++) {
           std::cout << map[i][j];
       }
       std::cout << std::endl;
    }
}

int main(void)
{  
    MapGenerator map;
    map.createWall();
    // map.doSpawnArea();
    // map.destroyRandomWall();
    // map.assignPercentagePowerUp();
    // map.callPlaceRandomPowerUp();
    print_vector(map.getMap());
    return 0;
}
