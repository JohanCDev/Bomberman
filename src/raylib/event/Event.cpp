/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Event
*/

#include "Event.hpp"

bool raylib::Event::isKeyPressed(KeyboardKey key)
{
    return (IsKeyPressed(key));
}
