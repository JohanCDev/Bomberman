/**
 * @file GameEvents.cpp
 * @author Nathan Le Bigot (nathan.le-bigot@epitech.eu)
 * @brief 
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "GameEvents.hpp"
#include <iostream>
#include "../raylib/Raylib.hpp"

namespace indie
{
    void GameEvents::getCharKeys(indie::Event &event)
    {
        if (indie::raylib::Event::isKeyPressed(KEY_A))
            event.key.code = 'a';
        else if (indie::raylib::Event::isKeyPressed(KEY_B))
            event.key.code = 'b';
        else if (indie::raylib::Event::isKeyPressed(KEY_C))
            event.key.code = 'c';
        else if (indie::raylib::Event::isKeyPressed(KEY_D))
            event.key.code = 'd';
        else if (indie::raylib::Event::isKeyPressed(KEY_E))
            event.key.code = 'e';
        else if (indie::raylib::Event::isKeyPressed(KEY_F))
            event.key.code = 'f';
        else if (indie::raylib::Event::isKeyPressed(KEY_G))
            event.key.code = 'g';
        else if (indie::raylib::Event::isKeyPressed(KEY_H))
            event.key.code = 'h';
        else if (indie::raylib::Event::isKeyPressed(KEY_I))
            event.key.code = 'i';
        else if (indie::raylib::Event::isKeyPressed(KEY_J))
            event.key.code = 'j';
        else if (indie::raylib::Event::isKeyPressed(KEY_K))
            event.key.code = 'k';
        else if (indie::raylib::Event::isKeyPressed(KEY_L))
            event.key.code = 'l';
        else if (indie::raylib::Event::isKeyPressed(KEY_M))
            event.key.code = 'm';
        else if (indie::raylib::Event::isKeyPressed(KEY_N))
            event.key.code = 'n';
        else if (indie::raylib::Event::isKeyPressed(KEY_O))
            event.key.code = 'o';
        else if (indie::raylib::Event::isKeyPressed(KEY_P))
            event.key.code = 'p';
        else if (indie::raylib::Event::isKeyPressed(KEY_Q))
            event.key.code = 'q';
        else if (indie::raylib::Event::isKeyPressed(KEY_R))
            event.key.code = 'r';
        else if (indie::raylib::Event::isKeyPressed(KEY_S))
            event.key.code = 's';
        else if (indie::raylib::Event::isKeyPressed(KEY_T))
            event.key.code = 't';
        else if (indie::raylib::Event::isKeyPressed(KEY_U))
            event.key.code = 'u';
        else if (indie::raylib::Event::isKeyPressed(KEY_V))
            event.key.code = 'v';
        else if (indie::raylib::Event::isKeyPressed(KEY_W))
            event.key.code = 'w';
        else if (indie::raylib::Event::isKeyPressed(KEY_X))
            event.key.code = 'x';
        else if (indie::raylib::Event::isKeyPressed(KEY_Y))
            event.key.code = 'y';
        else if (indie::raylib::Event::isKeyPressed(KEY_Z))
            event.key.code = 'z';
        else if (indie::raylib::Event::isKeyPressed(KEY_SPACE))
            event.key.code = ' ';
        else if (indie::raylib::Event::isKeyPressed(KEY_APOSTROPHE))
            event.key.code = '\'';
        else if (indie::raylib::Event::isKeyPressed(KEY_TAB))
            event.key.code = '\t';
        else
            event.key.code = '\0';
    }

    void GameEvents::getSystemKeys(indie::Event &event)
    {
        if (indie::raylib::Event::isKeyPressed(KEY_DOWN))
            event.key.down = true;
        else
            event.key.down = false;
        if (indie::raylib::Event::isKeyPressed(KEY_RIGHT))
            event.key.right = true;
        else
            event.key.right = false;
        if (indie::raylib::Event::isKeyPressed(KEY_LEFT))
            event.key.left = true;
        else
            event.key.left = false;
        if (indie::raylib::Event::isKeyPressed(KEY_UP))
            event.key.up = true;
        else
            event.key.up = false;
        if (indie::raylib::Event::isKeyPressed(KEY_ENTER))
            event.key.enter = true;
        else
            event.key.enter = false;
        if (indie::raylib::Event::isKeyPressed(KEY_LEFT_CONTROL))
            event.key.l_control = true;
        else
            event.key.l_control = false;
        if (indie::raylib::Event::isKeyPressed(KEY_RIGHT_CONTROL))
            event.key.r_control = true;
        else
            event.key.r_control = false;
        if (indie::raylib::Event::isKeyPressed(KEY_LEFT_ALT))
            event.key.l_alt = true;
        else
            event.key.l_alt = false;
        if (indie::raylib::Event::isKeyPressed(KEY_RIGHT_ALT))
            event.key.r_alt = true;
        else
            event.key.r_alt = false;
        if (indie::raylib::Event::isKeyPressed(KEY_LEFT_SHIFT))
            event.key.l_shift = true;
        else
            event.key.l_shift = false;
        if (indie::raylib::Event::isKeyPressed(KEY_RIGHT_SHIFT))
            event.key.r_shift = true;
        else
            event.key.r_shift = false;
    }

    void GameEvents::getControllerEvents(indie::Event &event, int controllerId)
    {
        if (indie::raylib::Event::isGamepadAvailable(controllerId)) {
            if (indie::raylib::Event::isGamepadButtonPressed(controllerId, indie::Event::ControllerCode::X_BUTTON))
                event.controller[controllerId].code = indie::Event::ControllerCode::X_BUTTON;
            else if (indie::raylib::Event::isGamepadButtonPressed(controllerId, indie::Event::ControllerCode::O_BUTTON))
                event.controller[controllerId].code = indie::Event::ControllerCode::O_BUTTON;
            else if (indie::raylib::Event::isGamepadButtonPressed(controllerId, indie::Event::ControllerCode::T_BUTTON))
                event.controller[controllerId].code = indie::Event::ControllerCode::T_BUTTON;
            else if (indie::raylib::Event::isGamepadButtonPressed(
                         controllerId, indie::Event::ControllerCode::OPTION_BUTTON))
                event.controller[controllerId].code = indie::Event::ControllerCode::OPTION_BUTTON;
            else if (indie::raylib::Event::isGamepadButtonPressed(
                         controllerId, indie::Event::ControllerCode::UP_BUTTON))
                event.controller[controllerId].code = indie::Event::ControllerCode::UP_BUTTON;
            else if (indie::raylib::Event::isGamepadButtonPressed(
                         controllerId, indie::Event::ControllerCode::DOWN_BUTTON))
                event.controller[controllerId].code = indie::Event::ControllerCode::DOWN_BUTTON;
            else if (indie::raylib::Event::isGamepadButtonPressed(
                         controllerId, indie::Event::ControllerCode::LEFT_BUTTON))
                event.controller[controllerId].code = indie::Event::ControllerCode::LEFT_BUTTON;
            else if (indie::raylib::Event::isGamepadButtonPressed(
                         controllerId, indie::Event::ControllerCode::RIGHT_BUTTON))
                event.controller[controllerId].code = indie::Event::ControllerCode::RIGHT_BUTTON;
            else
                event.controller[controllerId].code = indie::Event::ControllerCode::CONTROLLER_NONE;

            float xAxisLeft = indie::raylib::Event::getGamepadAxisMovement(controllerId, 0);
            float yAxisLeft = indie::raylib::Event::getGamepadAxisMovement(controllerId, 1);
            float xAxisRight = indie::raylib::Event::getGamepadAxisMovement(controllerId, 2);
            float yAxisRight = indie::raylib::Event::getGamepadAxisMovement(controllerId, 3);

            if (xAxisLeft >= -1 && xAxisLeft <= -0.75)
                event.controller[controllerId].leftJoystick = indie::Event::JoystickDirection::LEFT;
            else if (xAxisLeft >= 0.75 && xAxisLeft <= 1)
                event.controller[controllerId].leftJoystick = indie::Event::JoystickDirection::RIGHT;
            else if (yAxisLeft >= -1 && yAxisLeft <= -0.75)
                event.controller[controllerId].leftJoystick = indie::Event::JoystickDirection::UP;
            else if (yAxisLeft >= 0.75 && yAxisLeft <= 1)
                event.controller[controllerId].leftJoystick = indie::Event::JoystickDirection::DOWN;
            else
                event.controller[controllerId].leftJoystick = indie::Event::JoystickDirection::JOYSTICK_NONE;
            if (xAxisRight >= -1 && xAxisRight <= -0.75)
                event.controller[controllerId].rightJoystick = indie::Event::JoystickDirection::LEFT;
            else if (xAxisRight >= 0.75 && xAxisRight <= 1)
                event.controller[controllerId].rightJoystick = indie::Event::JoystickDirection::RIGHT;
            else if (yAxisRight >= -1 && yAxisRight <= -0.75)
                event.controller[controllerId].rightJoystick = indie::Event::JoystickDirection::UP;
            else if (yAxisRight >= 0.75 && yAxisRight <= 1)
                event.controller[controllerId].rightJoystick = indie::Event::JoystickDirection::DOWN;
            else
                event.controller[controllerId].rightJoystick = indie::Event::JoystickDirection::JOYSTICK_NONE;
            event.controller[controllerId].connected = true;
        } else
            event.controller[controllerId].connected = false;
    }

    bool GameEvents::inputUpdate(indie::Event &event)
    {
        event.resized = indie::raylib::Window::isWindowResized();
        this->getCharKeys(event);
        this->getSystemKeys(event);
        this->getControllerEvents(event, 0);
        this->getControllerEvents(event, 1);
        this->getControllerEvents(event, 2);
        this->getControllerEvents(event, 3);
        if (indie::raylib::Event::isKeyPressed(KEY_ESCAPE))
            return false;
        return true;
    }
} // namespace indie
