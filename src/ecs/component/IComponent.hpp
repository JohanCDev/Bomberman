/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <iostream>
#include "../../raylib/Raylib.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            class Transform;

            enum compoType {
                TRANSFORM,
                DRAWABLE2D,
                DRAWABLE3D,
                ALIVE,
                COLLECTABLE,
                INVENTORY,
                EXPLODABLE,
                UNKNOWNCOMPO
            };

            enum drawableType { CIRCLE, TEXT, RECTANGLE, SPHERE, CUBE, UNKNOWNDRAWABLE };

            enum bonusType { BOMBUP, SPEEDUP, FIREUP, WALLPASS, UNKNOWNBONUS };

            class IComponent {
              public:
                /**
                 * @brief Create a new IComponent.
                 */
                virtual ~IComponent() = default;

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                virtual indie::ecs::component::compoType getType() const = 0;

              private:
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !COMPONENT_HPP_ */