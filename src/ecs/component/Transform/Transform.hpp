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
        class Transform : public IComponent {
          public:
            Transform();
            Transform(float posX, float posY, float speedX, float speedY);
            ~Transform();
            ecs::compoType getType(void) override;
            void printProperties();
            void update(float posX, float posY, float speedX, float speedY);
            float getX() const;
            float getY() const;
            void setX(float posX);
            void setY(float posY);
            float getSpeedX() const;
            float getSpeedY() const;

          private:
            float _posX;
            float _posY;
            float _speedX;
            float _speedY;
        };
    } // namespace ecs
} // namespace indie

#endif /* !TRANSFORM_HPP_ */
