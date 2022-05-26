/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Event
*/

#include "Event.hpp"

bool Raylib::Event::isKeyPressed(KeyboardKey key)
{
    return (IsKeyPressed(key));
}
