/**
 * @file Inventory.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Inventory component header file
 * @version 0.1
 * @date 2022-06-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            /// @brief Inventory component
            class Inventory : public IComponent {
              public:
                /**
                 * @brief Create new inventory component.
                 */
                Inventory();

                /**
                 * @brief Destroy inventory component.
                 */
                ~Inventory();

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                indie::ecs::component::compoType getType() const;

                /**
                 * @brief Get Bomb up bonus status.
                 *
                 * @return a boolean of the bonus status.
                 */
                bool getBombUp() const;

                /**
                 * @brief Get Fire up bonus status.
                 *
                 * @return a boolean of the bonus status.
                 */
                bool getFireUp() const;

                /**
                 * @brief Get Speed up bonus status.
                 *
                 * @return a boolean of the bonus status.
                 */
                bool getSpeedUp() const;

                /**
                 * @brief Get Wall pass bonus status.
                 *
                 * @return a boolean of the bonus status.
                 */
                bool getWallPass() const;

                /**
                 * @brief Set bomb up bonus status.
                 */
                void setBombUp(bool bonus);

                /**
                 * @brief Set fire up bonus status.
                 */
                void setFireUp(bool bonus);

                /**
                 * @brief Set speed up bonus status.
                 */
                void setSpeedUp(bool bonus);

                /**
                 * @brief Set wall pass bonus status.
                 */
                void setWallPass(bool bonus);

              private:
                bool _bombUp;
                bool _fireUp;
                bool _speedUp;
                bool _wallPass;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !INVENTORY_HPP_ */
