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
            protected:
            private:
        };
    }
}
#endif /* !EVENT_HPP_ */
