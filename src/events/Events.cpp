/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Events.cpp
*/

#include "Events.hpp"
#include "ecs/raylib/Raylib.hpp"

Events::Events()
{
}

Events::~Events()
{
}

void Events::getEventsPlayerA()
{
    if (Raylib::isKeyPressed(KEY_W)) {
        // movePlayerUp(playerA);
    } else if (Raylib::isKeyPressed(KEY_A)) {
        // movePlayerLeft(playerA);
    } else if (Raylib::isKeyPressed(KEY_S)) {
        // movePlayerDown(playerA);
    } else if (Raylib::isKeyPressed(KEY_D)) {
        // movePlayerRight(playerA);
    } else if (Raylib::isKeyPressed(KEY_E)) {
        // actionPlayer(playerA);
    }
}

void Events::getEventsPlayerB()
{
    if (Raylib::isKeyPressed(KEY_T)) {
        // movePlayerUp(playerB);
    } else if (Raylib::isKeyPressed(KEY_F)) {
        // movePlayerLeft(playerB);
    } else if (Raylib::isKeyPressed(KEY_G)) {
        // movePlayerDown(playerB);
    } else if (Raylib::isKeyPressed(KEY_H)) {
        // movePlayerRight(playerB);
    } else if (Raylib::isKeyPressed(KEY_Y)) {
        // actionPlayer(playerB);
    }
}

void Events::getEventsPlayerC()
{
    if (Raylib::isKeyPressed(KEY_O)) {
        // movePlayerUp(playerC);
    } else if (Raylib::isKeyPressed(KEY_K)) {
        // movePlayerLeft(playerC);
    } else if (Raylib::isKeyPressed(KEY_L)) {
        // movePlayerDown(playerC);
    } else if (Raylib::isKeyPressed(KEY_SEMICOLON)) {
        // movePlayerRight(playerC);
    } else if (Raylib::isKeyPressed(KEY_P)) {
        // actionPlayer(playerC);
    }
}

void Events::getEventsPlayerD()
{
    if (Raylib::isKeyPressed(KEY_UP)) {
        // movePlayerUp(playerD);
    } else if (Raylib::isKeyPressed(KEY_LEFT)) {
        // movePlayerLeft(playerD);
    } else if (Raylib::isKeyPressed(KEY_DOWN)) {
        // movePlayerDown(playerD);
    } else if (Raylib::isKeyPressed(KEY_RIGHT)) {
        // movePlayerRight(playerD);
    } else if (Raylib::isKeyPressed(KEY_RIGHT_SHIFT)) {
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
