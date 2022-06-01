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
                /**
                 * @brief Create a new drawable 3d component.
                 */
                Drawable3D();

                /**
                 * @brief Create a new sphere.
                 *
                 * @param radius the radius of the sphere.
                 * @param color the color of the cube.
                 */
                Drawable3D(float radius, Color color);

                /**
                 * @brief Create a new cube component.
                 *
                 * @param height the height of the cube.
                 * @param width the width of the cube.
                 * @param length the length of the cube.
                 * @param color the color of the cube.
                 */
                Drawable3D(float height, float width, float length, Color color);

                /**
                 * @brief Destroy drawable 3d component.
                 */
                ~Drawable3D();

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                indie::ecs::component::compoType getType();

                /**
                 * @brief Get the draw type of the component.
                 *
                 * @return the drawableType value of the component.
                 */
                indie::ecs::component::drawableType getDrawType();

                /**
                 * @brief Get the color.
                 *
                 * @return the color of the component.
                 */
                Color getColor();

                /**
                 * @brief Get the radius value.
                 *
                 * @return the radius of the component.
                 */
                float getRadius();

                /**
                 * @brief Get the height value.
                 *
                 * @return the height of the component.
                 */
                float getHeight();

                /**
                 * @brief Get the width value.
                 *
                 * @return the width of the component.
                 */
                float getWidth();

                /**
                 * @brief Get the length value.
                 *
                 * @return the length of the component.
                 */
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
