/*
** EPITECH PROJECT, 2022
** Drawable3D
** File description:
** Drawable3D
*/

#ifndef DRAWABLE3D_HPP_
#define DRAWABLE3D_HPP_

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        class Drawable3D : public IComponent {
          public:
            Drawable3D();
            Drawable3D(float radius, Color color);
            Drawable3D(float height, float width, float length, Color color);
            ~Drawable3D();
            ecs::compoType getType();
            ecs::drawableType getDrawType();
            Color getColor();
            float getRadius();
            float getHeight();
            float getWidth();
            float getLength();

          private:
            float _radius;
            float _height;
            float _width;
            float _length;
            Color _color;
            indie::ecs::compoType _compoType;
            indie::ecs::drawableType _drawableType;
        };
    } // namespace ecs
} // namespace indie

#endif /* !DRAWABLE3D_HPP_ */
