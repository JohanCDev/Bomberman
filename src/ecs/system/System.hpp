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
    class System {
      public:
        System();
        ~System();
        static bool pollEvent(indie::Event &event);

      protected:
      private:
    };

} // namespace ecs

#endif /* !SYSTEM_HPP_ */
