/**
 * @file Alive.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Alive component header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
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
            /// @brief Alive component
            class Alive : public IComponent {
              public:
                /// @brief Constructor
                Alive();
                /// @brief Constructor
                /// @param alive is alive or not
                Alive(bool alive);
                /// @brief Destructor
                ~Alive();
                /// @brief set the alive value
                /// @param alive is alive or not
                void setAlive(bool alive);
                /// @brief get the alive value
                bool getAlive() const;
                /// @brief get the type of the component
                indie::ecs::component::compoType getType() const;

              private:
                /// @brief is alive or not
                bool _alive;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !ALIVE_HPP_ */
