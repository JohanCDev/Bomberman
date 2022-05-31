/*
** EPITECH PROJECT, 2022
** Drawable2D
** File description:
** Drawable2D
*/

#ifndef DRAWABLE2D_HPP_
#define DRAWABLE2D_HPP_

#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        class Drawable2D : public IComponent {
          public:
            Drawable2D();
            Drawable2D(float radius, Color color);
            Drawable2D(std::string text, float fontSize, Color color);
            Drawable2D(float height, float width, Color color);
            ~Drawable2D();
            ecs::compoType getType();
            ecs::drawableType getDrawType();
            Color getColor();
            float getRadius();
            float getHeight();
            float getWidth();
            float getFontSize();
            std::string getText();

          private:
            float _radius;
            float _height;
            float _width;
            std::string _text;
            float _fontSize;
            Color _color;
            indie::ecs::compoType _compoType;
            indie::ecs::drawableType _drawableType;
        };
    } // namespace ecs
} // namespace indie

#endif /* !DRAWABLE2D_HPP_ */
