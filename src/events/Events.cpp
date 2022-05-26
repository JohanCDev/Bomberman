/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Events.cpp
*/

#include <iostream>
#include "Events.hpp"
#include "../raylib/Raylib.hpp"

Events::Events()
{
}

Events::~Events()
{
}

void Events::getEventsPlayerA()
{
    if (indie::Raylib::isKeyPressed(KEY_W)) {
        // movePlayerUp(playerA);
    } else if (indie::Raylib::isKeyPressed(KEY_A)) {
        // movePlayerLeft(playerA);
    } else if (indie::Raylib::isKeyPressed(KEY_S)) {
        // movePlayerDown(playerA);
    } else if (indie::Raylib::isKeyPressed(KEY_D)) {
        // movePlayerRight(playerA);
    } else if (indie::Raylib::isKeyPressed(KEY_E)) {
        // actionPlayer(playerA);
    }
}

void Events::getEventsPlayerB()
{
    if (indie::Raylib::isKeyPressed(KEY_T)) {
        // movePlayerUp(playerB);
    } else if (indie::Raylib::isKeyPressed(KEY_F)) {
        // movePlayerLeft(playerB);
    } else if (indie::Raylib::isKeyPressed(KEY_G)) {
        // movePlayerDown(playerB);
        std::cout << "said G\n";
    } else if (indie::Raylib::isKeyPressed(KEY_H)) {
        // movePlayerRight(playerB);
    } else if (indie::Raylib::isKeyPressed(KEY_Y)) {
        // actionPlayer(playerB);
    }
}

void Events::getEventsPlayerC()
{
    if (indie::Raylib::isKeyPressed(KEY_O)) {
        // movePlayerUp(playerC);
    } else if (indie::Raylib::isKeyPressed(KEY_K)) {
        // movePlayerLeft(playerC);
    } else if (indie::Raylib::isKeyPressed(KEY_L)) {
        // movePlayerDown(playerC);
    } else if (indie::Raylib::isKeyPressed(KEY_SEMICOLON)) {
        // movePlayerRight(playerC);
    } else if (indie::Raylib::isKeyPressed(KEY_P)) {
        // actionPlayer(playerC);
    }
}

void Events::getEventsPlayerD()
{
    if (indie::Raylib::isKeyPressed(KEY_UP)) {
        // movePlayerUp(playerD);
    } else if (indie::Raylib::isKeyPressed(KEY_LEFT)) {
        // movePlayerLeft(playerD);
    } else if (indie::Raylib::isKeyPressed(KEY_DOWN)) {
        // movePlayerDown(playerD);
    } else if (indie::Raylib::isKeyPressed(KEY_RIGHT)) {
        // movePlayerRight(playerD);
    } else if (indie::Raylib::isKeyPressed(KEY_RIGHT_SHIFT)) {
        // actionPlayer(playerC);
    }
}

void Events::inputUpdate()
{
    Events::getEventsPlayerA();
    Events::getEventsPlayerB();
    Events::getEventsPlayerC();
    Events::getEventsPlayerD();
}
