/**
 * @file Event.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Event encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// Event class encapsulation
        class Event {
          public:
            Event() = default;
            ~Event() = default;

            /**
             * @brief Check if a key has been pressed once
             */
            static bool isKeyPressed(KeyboardKey key);

            // Input-related functions: gamepads
            /**
             * @brief Check if a gamepad is available
             */
            static bool isGamepadAvailable(int gamepad);

            /**
             * @brief Check if a specific button on a specific gamepad is pressed
             */
            static bool isGamepadButtonPressed(int gamepadId, int buttonId);

            /**
             * @brief Get axis movement value for a gamepad axis
             */
            static float getGamepadAxisMovement(int gamepad, int axis);
        };
    } // namespace raylib
} // namespace indie
#endif /* !EVENT_HPP_ */
