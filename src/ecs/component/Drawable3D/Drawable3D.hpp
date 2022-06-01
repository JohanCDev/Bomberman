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
        namespace component
        {
            class Drawable3D : public IComponent {
              public:
                Drawable3D();
                Drawable3D(float radius, Color color);
                Drawable3D(float height, float width, float length, Color color);
                ~Drawable3D();
                indie::ecs::component::compoType getType();
                indie::ecs::component::drawableType getDrawType();
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
                indie::ecs::component::compoType _compoType;
                indie::ecs::component::drawableType _drawableType;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !DRAWABLE3D_HPP_ */
