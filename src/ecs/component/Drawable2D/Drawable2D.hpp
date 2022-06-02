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
        namespace component
        {
            class Drawable2D : public IComponent {
              public:
                /**
                 * @brief Create a new drawable 2d component.
                 */
                Drawable2D();

                /**
                 * @brief Create a new circle component.
                 *
                 * @param radius the radius of the circle.
                 * @param color the color of the circle.
                 */
                Drawable2D(float radius, Color color);

                /**
                 * @brief Create a new text component.
                 *
                 * @param text the text of the component.
                 * @param fontSize the font size of the component.
                 * @param color the color of the text.
                 */
                Drawable2D(std::string text, float fontSize, Color color);

                /**
                 * @brief Create a new rectangle component.
                 *
                 * @param height the height of the rectangle.
                 * @param width the width of the rectangle.
                 * @param color the color of the rectangle.
                 */
                Drawable2D(float height, float width, Color color);

                /**
                 * @brief Destroy the component.
                 */
                ~Drawable2D();

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                indie::ecs::component::compoType getType() const;

                /**
                 * @brief Get the draw type of the component.
                 *
                 * @return the drawableType value of the component.
                 */
                indie::ecs::component::drawableType getDrawType();

                /**
                 * @brief Get the color.
                 */
                Color getColor();

                /**
                 * @brief Get the radius value.
                 */
                float getRadius();

                /**
                 * @brief Get the height value.
                 */
                float getHeight();

                /**
                 * @brief Get the width value.
                 */
                float getWidth();

                /**
                 * @brief Get the font size.
                 */
                float getFontSize();

                /**
                 * @brief Get the text value.
                 */
                std::string getText();

              private:
                float _radius;
                float _height;
                float _width;
                std::string _text;
                float _fontSize;
                Color _color;
                indie::ecs::component::compoType _compoType;
                indie::ecs::component::drawableType _drawableType;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !DRAWABLE2D_HPP_ */