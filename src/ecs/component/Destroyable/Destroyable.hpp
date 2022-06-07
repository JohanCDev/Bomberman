/*
** EPITECH PROJECT, 2022
** Destroyable
** File description:
** Destroyable
*/

#ifndef DESTROYABLE_HPP_
#define DESTROYABLE_HPP_

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            class Destroyable : public IComponent {
              public:
                Destroyable();
                ~Destroyable();

                indie::ecs::component::compoType getType() const;

              protected:
              private:
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !DESTROYABLE_HPP_ */
