/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Events
*/

/// @file
///
/// The Event data structure.

#ifndef INDIE_EVENT_HPP_
#define INDIE_EVENT_HPP_

#include "Vec2.hpp"

namespace indie
{
    /// Contains an event's data.
    ///
    /// Event data is fetched by first checking its type and then accessing the correspoding member.
    struct Event {
        /// Key code for keyboard events.
        ///
        /// Keys are represented by their corresponding character, meaning that some keys are not currently
        /// representable using this format (such as the Enter key).
        using Key = char;

        /// Size events parameters (Event::Type::Resized).
        struct SizeEvent {
            /// Old size, in units.
            vec2u oldSize;
            /// New size, in units.
            vec2u newSize;
        };

        /// @brief Keyboard event parameters (Event::Type::KeyPressed, Event::Type::KeyReleased).
        struct KeyEvent {
            /// Is the Left Alt key pressed?
            bool l_alt;
            /// Is the Right Alt key pressed?
            bool r_alt;
            /// Is the Left Control key pressed?
            bool l_control;
            /// Is the Right Control key pressed?
            bool r_control;
            /// Is the Left Shift key pressed?
            bool l_shift;
            /// Is the Right Shift key pressed?
            bool r_shift;
            /// Is the up key pressed?
            bool up;
            /// Is the down key pressed?
            bool down;
            /// Is the left key pressed?
            bool left;
            /// Is the right key pressed?
            bool right;
            /// Code of the key that has been pressed.
            Key code;
        };

        /// Enumeration of the different types of events.
        enum class Type {
            /// The window requested to be closed (no data).
            Closed,
            /// The window was resized (data in Event.size).
            Resized,
            /// A key was pressed (data in Event.key).
            KeyPressed,
            /// A key was released (data in Event.key).
            KeyReleased,

            /// Keep last -- the total number of event types.
            Count
        };

        // Member data

        /// Type of the event.
        Type type;

        union {
            /// Size event parameters (Event::Resized).
            SizeEvent size;
            /// Key event parameters (Event::KeyPressed, Event::KeyReleased).
            KeyEvent key;
        };
    };
} // namespace indie

#endif // !defined(ARCADE_EVENT_HPP_)
