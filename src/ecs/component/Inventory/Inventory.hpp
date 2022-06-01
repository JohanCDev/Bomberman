/*
** EPITECH PROJECT, 2022
** Inventory
** File description:
** Inventory
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
            class Inventory : public IComponent {
              public:
                Inventory();
                ~Inventory();

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                indie::ecs::component::compoType getType() const;

                bool getBombUp() const;
                bool getFireUp() const;
                bool getSpeedUp() const;
                bool getWallPass() const;

                void setBombUp(bool bonus);
                void setFireUp(bool bonus);
                void setSpeedUp(bool bonus);
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
