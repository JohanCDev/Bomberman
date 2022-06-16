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
                /**
                 * @brief Construct a new Alive object
                 * 
                 */
                Alive();
                /**
                 * @brief Construct a new Alive object
                 * 
                 * @param alive Is alive or not
                 */
                Alive(bool alive);
                /**
                 * @brief Destroy the Alive object
                 * 
                 */
                ~Alive();
                /**
                 * @brief Set alive state
                 * 
                 * @param alive True if is alive, False otherwise
                 */
                void setAlive(bool alive);
                /**
                 * @brief Get the alive state
                 * 
                 * @return true Is alive
                 * @return false Isn't alive
                 */
                bool getAlive() const;
                /**
                 * @brief Get the Type object
                 * 
                 * @return indie::ecs::component::compoType CompoType of the component.
                 */
                indie::ecs::component::compoType getType() const;

              private:
                /**
                 * @brief Is alive or not
                 * 
                 */
                bool _alive;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !ALIVE_HPP_ */
