/**
 * @file Transform.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Transform component header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            /// @brief Transform component
            class Transform : public IComponent {
              public:
                /**
                 * @brief Create a new transform component.
                 */
                Transform();
                /**
                 * @brief Create a new transform component.
                 *
                 * @param posX the x position.
                 * @param posY the y position.
                 * @param speedX the x speed.
                 * @param speedY the y speed.
                 */
                Transform(float posX, float posY, float speedX, float speedY);
                /**
                 * @brief Destroy the transform component.
                 */
                ~Transform();
                /**
                 * @brief Get type of the component.
                 *
                 * @return indie::ecs::component::compoType CompoType of the component.
                 */
                indie::ecs::component::compoType getType(void) const override;
                /**
                 * @brief Update the value of the component.
                 *
                 * @param posX the x position.
                 * @param posY the y position.
                 * @param speedX the x speed.
                 * @param speedY the y speed.
                 */
                void update(float posX, float posY, float speedX, float speedY);
                /**
                 * @brief Get the x position.
                 *
                 * @return float the x position.
                 */
                float getX() const;
                /**
                 * @brief Get the y position.
                 *
                 * @return float the y position.
                 */
                float getY() const;
                /**
                 * @brief Get the z position.
                 *
                 * @return float the z position.
                 */
                float getZ() const;
                /**
                 * @brief Set a new x position.
                 * 
                 * @param posX X position
                 */
                void setX(float posX);
                /**
                 * @brief Set a new y position.
                 * 
                 * @param posY Y position
                 */
                void setY(float posY);
                /**
                 * @brief Set a new Z position.
                 * 
                 * @param posZ Z position
                 */
                void setZ(float posZ);
                /**
                 * @brief Get the x speed.
                 *
                 * @return float the x speed.
                 */
                float getSpeedX() const;
                /**
                 * @brief Get the y speed.
                 *
                 * @return float the y speed.
                 */
                float getSpeedY() const;
                /**
                 * @brief Set a new Y speed.
                 * 
                 * @param speed Y speed
                 */
                void setSpeedY(float speed);
                /**
                 * @brief Set a new X speed.
                 * 
                 * @param speed X speed
                 */
                void setSpeedX(float speed);

              private:
                /**
                 * @brief X position
                 * 
                 */
                float _posX;
                /**
                 * @brief Y position
                 * 
                 */
                float _posY;
                /**
                 * @brief Z position
                 * 
                 */
                float _posZ;
                /**
                 * @brief X speed
                 * 
                 */
                float _speedX;
                /**
                 * @brief Y speed
                 * 
                 */
                float _speedY;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !TRANSFORM_HPP_ */
