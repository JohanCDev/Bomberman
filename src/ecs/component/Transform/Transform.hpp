/*
** EPITECH PROJECT, 2022
** Transform
** File description:
** Transform
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
                 * @return the compoType value of the component.
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
                 * @return the x position.
                 */
                float getX() const;

                /**
                 * @brief Get the y position.
                 *
                 * @return the y position.
                 */
                float getY() const;

                /**
                 * @brief Set a new x position.
                 */
                void setX(float posX);

                /**
                 * @brief Set a new y position.
                 */
                void setY(float posY);

                /**
                 * @brief Get the x speed.
                 *
                 * @return the x speed.
                 */
                float getSpeedX() const;

                /**
                 * @brief Get the y speed.
                 *
                 * @return the y speed.
                 */
                float getSpeedY() const;

                void setSpeedY(float speed);

                void setSpeedX(float speed);

              private:
                float _posX;
                float _posY;
                float _speedX;
                float _speedY;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !TRANSFORM_HPP_ */
