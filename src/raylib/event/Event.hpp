/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
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
                * @brief Get the last gamepad button pressed
                */
                static int getGamepadButtonPressed(void);

                /**
                * @brief Get axis movement value for a gamepad axis
                */
                static float getGamepadAxisMovement(int gamepad, int axis);
        };
    }
}
#endif /* !EVENT_HPP_ */
