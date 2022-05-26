/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Event
*/

#include "Event.hpp"

bool indie::raylib::Event::isKeyPressed(KeyboardKey key)
{
    return (IsKeyPressed(key));
}
