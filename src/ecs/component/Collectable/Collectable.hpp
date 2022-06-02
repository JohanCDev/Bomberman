/*
** EPITECH PROJECT, 2022
** Collectable
** File description:
** Collectable
*/

#ifndef COLLECTABLE_HPP_
#define COLLECTABLE_HPP_

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            class Collectable : public IComponent {
              public:
                /**
                 * @brief Create new collectable component.
                 */
                Collectable();

                /**
                 * @brief Create new collectable component with bonusType.
                 */
                Collectable(indie::ecs::component::bonusType type);

                /**
                 * @brief Destroy collectable component.
                 */
                ~Collectable();

                /**
                 * @brief Get type of the bonus.
                 *
                 * @return the bonusType value of the component.
                 */
                indie::ecs::component::bonusType getBonusType() const;

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                indie::ecs::component::compoType getType() const;

              private:
                indie::ecs::component::bonusType _type;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !COLLECTABLE_HPP_ */