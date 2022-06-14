/**
 * @file Event.cpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Event encapsulation source file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
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

bool indie::raylib::Event::isGamepadButtonPressed(int gamepadId, int buttonId)
{
    return ::IsGamepadButtonPressed(gamepadId, buttonId);
}

float indie::raylib::Event::getGamepadAxisMovement(int gamepad, int axis)
{
    return ::GetGamepadAxisMovement(gamepad, axis);
}
