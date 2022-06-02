/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Events.hpp
*/

#ifndef GAMEEVENTS_HPP_
#define GAMEEVENTS_HPP_

#include "events.hpp"

namespace indie
{
    /**
     * @brief Events base class
     *
     */
    class GameEvents {
      public:
        /**
         * @brief Get input events and update game
         * @returns false if escape is pressed
         */
        bool inputUpdate(indie::Event &event);

        /**
         * @brief Get a char input
         *
         * @param event event class to modify
         */
        void getCharKeys(indie::Event &event);

        /**
         * @brief Get a system input
         *
         * @param event event class to modify
         */
        void getSystemKeys(indie::Event &event);

        /**
         * @brief Get a controller event
         *
         * @param event event class to modify
         * @param controllerId id of the controller
         */
        void getControllerEvents(indie::Event &event, int controllerId);
    };
} // namespace indie

#endif /* !EVENTS_HPP_ */
