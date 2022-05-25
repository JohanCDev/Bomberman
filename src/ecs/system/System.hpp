/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "events.hpp"

namespace ecs
{
  /**
   * @brief System class implementation
   * 
   */
    class System {
      public:
        /**
         * @brief Construct a new System object
         */
        System();
        /**
         * @brief Destroy the System object
         */
        ~System();
        /**
         * @brief poll an event on the window
         * 
         * @param event event to poll
         * @return true if there is an event in the queue
         * @return false if there isn't no event
         */
        static bool pollEvent(indie::Event &event);

      protected:
      private:
    };

} // namespace ecs

#endif /* !SYSTEM_HPP_ */
