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
        /// @brief Event class encapsulation
        class Event {
          public:
            /**
             * @brief Construct a new Event object
             * 
             */
            Event() = default;
            /**
             * @brief Destroy the Event object
             * 
             */
            ~Event() = default;
            /**
             * @brief Check if a key is pressed
             * 
             * @param key The pressed key
             * 
             * @return true The key is pressed
             * @return false The key isn't pressed
             */
            static bool isKeyPressed(KeyboardKey key);
            // Input-related functions: gamepads
            /**
             * @brief Check if a gamepad is available
             * 
             * @param gamepad The gamepad
             * 
             * @return true The gamepad is available
             * @return false The gamepad isn't available
             */
            static bool isGamepadAvailable(int gamepad);
            /**
             * @brief Check if a specific button on a specific gamepad is pressed
             * 
             * @param gamepadId Gamepad ID
             * @param buttonId Button ID
             * 
             * @return true Button is pressed
             * @return false Button isn't pressed
             */
            static bool isGamepadButtonPressed(int gamepadId, int buttonId);
            /**
             * @brief Get axis movement value for a gamepad axis
             * 
             * @param gamepad The gamepad
             * @param axis The gamepad axis
             * 
             * @return float The axis movement value
             */
            static float getGamepadAxisMovement(int gamepad, int axis);
        };
    } // namespace raylib
} // namespace indie
#endif /* !EVENT_HPP_ */
