/**
 * @file Drawable3D.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Drawable3D component header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef DRAWABLE3D_HPP_
#define DRAWABLE3D_HPP_

#include <string>
#include "../IComponent.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            /// @brief Drawable3D component
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
                 * @param texturePath Path to the texture of the cube
                 * @param height the height of the cube.
                 * @param width the width of the cube.
                 * @param length the length of the cube.
                 * @param color the color of the cube.
                 */
                Drawable3D(std::string texturePath, float height, float width, float length, Color color);
                /**
                 * @brief Destroy drawable 3d component.
                 */
                ~Drawable3D();
                /**
                 * @brief Get type of the component.
                 *
                 * @return indie::ecs::component::compoType CompoType of the component.
                 */
                indie::ecs::component::compoType getType() const;
                /**
                 * @brief Get the draw type of the component.
                 *
                 * @return indie::ecs::component::drawableType DrawableType of the component.
                 */
                indie::ecs::component::drawableType getDrawType();
                /**
                 * @brief Get the color.
                 *
                 * @return Color Color of the component.
                 */
                Color getColor();
                /**
                 * @brief Get the radius value.
                 *
                 * @return float Radius of the component.
                 */
                float getRadius();
                /**
                 * @brief Get the height value.
                 *
                 * @return float Height of the component.
                 */
                float getHeight();
                /**
                 * @brief Get the width value.
                 *
                 * @return float Width of the component.
                 */
                float getWidth();
                /**
                 * @brief Get the length value.
                 *
                 * @return float Length of the component.
                 */
                float getLength();
                /**
                 * @brief Get the Texture Path of the component
                 * 
                 * @return std::string Path to the texture of the component
                 */
                std::string getTexturePath() const;
                /**
                 * @brief Set the Texture Path of the component
                 * 
                 * @param texturePath Path to the texture for the component
                 */
                void setTexturePath(std::string texturePath);
                /**
                 * @brief Get the Texture object of the component
                 * 
                 * @return Texture2D Texture of the component
                 */
                Texture2D getTexture() const;
                /**
                 * @brief Set the Texture of the component
                 * 
                 * @param texturePath Path to the texture for the component
                 */
                void setTexture(std::string texturePath);

              private:
                /**
                 * @brief Value for radius
                 * 
                 */
                float _radius;
                /**
                 * @brief Value for height
                 * 
                 */
                float _height;
                /**
                 * @brief Value for height
                 * 
                 */
                float _width;
                /**
                 * @brief Value for length
                 * 
                 */
                float _length;
                /**
                 * @brief Color object for the component
                 * 
                 */
                Color _color;
                /**
                 * @brief Path to the texture for the component
                 * 
                 */
                std::string _texturePath;
                /**
                 * @brief Texture2D object for the component
                 * 
                 */
                Texture2D _texture;
                /**
                 * @brief CompoType of the component
                 * 
                 */
                indie::ecs::component::compoType _compoType;
                /**
                 * @brief DrawableType of the component
                 * 
                 */
                indie::ecs::component::drawableType _drawableType;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !DRAWABLE3D_HPP_ */
