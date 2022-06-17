/**
 * @file Collectable.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Collectable component header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
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
            /// @brief Collectable component
            class Collectable : public IComponent {
              public:
                /**
                 * @brief Create new collectable component.
                 */
                Collectable();

                /**
                 * @brief Create new collectable component with bonusType.
                 * 
                 * @param type Type of bonus
                 */
                Collectable(indie::ecs::component::bonusType type);

                /**
                 * @brief Destroy collectable component.
                 */
                ~Collectable();

                /**
                 * @brief Get type of the bonus.
                 *
                 * @return indie::ecs::component::bonusType BonusType of the component.
                 */
                indie::ecs::component::bonusType getBonusType() const;

                /**
                 * @brief Get type of the component.
                 *
                 * @return indie::ecs::component::compoType CompoType of the component.
                 */
                indie::ecs::component::compoType getType() const;

              private:
                /**
                 * @brief Type of the bonus.
                 */
                indie::ecs::component::bonusType _type;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !COLLECTABLE_HPP_ */
