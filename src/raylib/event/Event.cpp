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

bool indie::raylib::Event::isGamepadAvailable(int gamepad)
{
    return ::IsGamepadAvailable(gamepad);
}

int indie::raylib::Event::getGamepadButtonPressed(void)
{
    return ::GetGamepadButtonPressed();
}

float indie::raylib::Event::getGamepadAxisMovement(int gamepad, int axis)
{
    return ::GetGamepadAxisMovement(gamepad, axis);
}
