/*
** EPITECH PROJECT, 2022
** Alive
** File description:
** Alive
*/

#ifndef ALIVE_HPP_
#define ALIVE_HPP_

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            class Alive : public IComponent {
              public:
                Alive();

                Alive(bool alive);
                ~Alive();

                void setAlive(bool alive);
                bool getAlive() const;
                indie::ecs::component::compoType getType();

              private:
                bool _alive;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !ALIVE_HPP_ */
