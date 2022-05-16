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

#include "types.hpp"

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

        /// Represents a mouse button.
        enum class MouseButton {
            /// The left mouse button.
            Left,
            /// The right mouse button.
            Right,
            /// The middle (wheel) mouse button.
            Middle,

            /// Keep last -- the total number of mouse buttons.
            Count
        };

        /// Size events parameters (Event::Type::Resized).
        struct SizeEvent {
            /// Old size, in units.
            vec2u oldSize;
            /// New size, in units.
            vec2u newSize;
        };

        /// @brief Keyboard event parameters (Event::Type::KeyPressed, Event::Type::KeyReleased).
        struct KeyEvent {
            /// Is the Alt key pressed?
            bool alt;
            /// Is the Control key pressed?
            bool control;
            /// Is the Shift key pressed?
            bool shift;
            /// Is the System key pressed?
            bool system;
            /// Code of the key that has been pressed.
            Key code;
        };

        /// Mouse move event parameters (Event::Type::MouseMoved)
        struct MouseMoveEvent {
            /// Position of the mouse pointer, relative to the left of the owner window.
            vec2i pos;
        };

        /// Mouse buttons events parameters (Event::Type::MouseButtonPressed, Event::Type::MouseButtonReleased).
        struct MouseButtonEvent {
            /// Code of the button that has been pressed.
            MouseButton button;
            /// Position of the mouse pointer, relative to the left of the owner window.
            vec2i pos;
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
            /// A mouse button was pressed (data in Event.mouseButton).
            MouseButtonPressed,
            /// A mouse button was released (data in Event.mouseButton).
            MouseButtonReleased,
            /// The mouse cursor moved (data in Event.mouseMove).
            MouseMoved,

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
            /// Mouse move event parameters (Event::MouseMoved).
            MouseMoveEvent mouseMove;
            /// Mouse button event parameters (Event::MouseButtonPressed, Event::MouseButtonReleased).
            MouseButtonEvent mouseButton;
        };
    };
} // namespace arcade

#endif // !defined(ARCADE_EVENT_HPP_)
