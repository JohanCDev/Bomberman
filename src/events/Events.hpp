/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Events.hpp
*/

#ifndef EVENTS_HPP_
#define EVENTS_HPP_

namespace indie {
    /**
     * @brief Events base class
     *
     */
    class Events {
      public:
        /**
         * @brief Construct a new Events object
         */
        Events();

        /**
         * @brief Destroy the Events object
         */
        ~Events();

        /**
         * @brief Get input events and update game
         */
        void inputUpdate();

        /**
         * @brief Get key events from player A and update game
         */
        void getEventsPlayerA();

        /**
         * @brief Get key events from player B and update game
         */
        void getEventsPlayerB();

        /**
         * @brief Get key events from player C and update game
         */
        void getEventsPlayerC();

        /**
         * @brief Get key events from player D and update game
         */
        void getEventsPlayerD();

      protected:
      private:
    };
}

#endif /* !EVENTS_HPP_ */
