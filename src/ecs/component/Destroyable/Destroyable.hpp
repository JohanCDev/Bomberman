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
            /// @brief Destroyable component
            class Destroyable : public IComponent {
              public:
                /**
                 * @brief Create new destroyable component.
                 */
                Destroyable();
                /**
                 * @brief Destructor
                 */
                ~Destroyable();

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                indie::ecs::component::compoType getType() const;

              protected:
              private:
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !DESTROYABLE_HPP_ */
