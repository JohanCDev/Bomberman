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
                 * @return indie::ecs::component::compoType CompoType of the component.
                 */
                indie::ecs::component::compoType getType() const;
                /**
                 * @brief Get Bomb up bonus status.
                 *
                 * @return true BombUp bonus OK
                 * @return false BombUp bonus KO
                 */
                bool getBombUp() const;
                /**
                 * @brief Get Fire up bonus status.
                 *
                 * @return true FireUp bonus OK
                 * @return false FireUp bonus KO
                 */
                bool getFireUp() const;
                /**
                 * @brief Get Speed up bonus status.
                 *
                 * @return true SpeedUp bonus OK
                 * @return false SpeedUp bonus KO
                 */
                bool getSpeedUp() const;
                /**
                 * @brief Get WallPass bonus status.
                 *
                 * @return true WallPass bonus OK
                 * @return false WallPass bonus KO
                 */
                bool getWallPass() const;
                /**
                 * @brief Set bomb up bonus status.
                 * 
                 * @param bonus True if bonus is good, False if not
                 */
                void setBombUp(bool bonus);
                /**
                 * @brief Set Fire up bonus status.
                 * 
                 * @param bonus True if bonus is good, False if not
                 */
                void setFireUp(bool bonus);
                /**
                 * @brief Set speed up bonus status.
                 * 
                 * @param bonus True if bonus is good, False if not
                 */
                void setSpeedUp(bool bonus);
                /**
                 * @brief Set WallPass bonus status.
                 * 
                 * @param bonus True if bonus is good, False if not
                 */
                void setWallPass(bool bonus);

                /**
                 * @brief Set the bonus status
                 *
                 * @param type of the bonus
                 */
                void setBonus(indie::ecs::component::bonusType type);

              private:
                /**
                 * @brief True if bonus is good, False if not
                 * 
                 */
                bool _bombUp;
                /**
                 * @brief True if bonus is good, False if not
                 * 
                 */
                bool _fireUp;
                /**
                 * @brief True if bonus is good, False if not
                 * 
                 */
                bool _speedUp;
                /**
                 * @brief True if bonus is good, False if not
                 * 
                 */
                bool _wallPass;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !INVENTORY_HPP_ */
