/**
 * @file IComponent.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Interface for every compponents
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
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

            /**
             * @brief Enum for component type
             *
             */
            enum compoType {
                TRANSFORM,
                DRAWABLE2D,
                DRAWABLE3D,
                ALIVE,
                COLLECTABLE,
                INVENTORY,
                EXPLODABLE,
                COLLIDE,
                SOUND,
                DESTROYABLE,
                MODEL,
                ANIMATED,
                UNKNOWNCOMPO
            };
            /**
             * @brief Enum for drawable type
             *
             */
            enum drawableType { CIRCLE, TEXT, RECTANGLE, SPHERE, CUBE, OBJECT, UNKNOWNDRAWABLE };
            /**
             * @brief Enum for bonus type
             *
             */
            enum bonusType { BOMBUP, SPEEDUP, FIREUP, WALLPASS, UNKNOWNBONUS };

            /// @brief Component interface
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
