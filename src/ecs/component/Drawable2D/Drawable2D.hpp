/**
 * @file Drawable2D.hpp
 * @author Cédric Corge (cedric.corge@epitech.eu)
 * @brief Drawable2D component header file
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
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
            /// @brief Drawable2D component
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
                 * @param texturePath Path to the texture
                 * @param height the height of the rectangle.
                 * @param width the width of the rectangle.
                 * @param color the color of the rectangle.
                 */
                Drawable2D(std::string texturePath, float height, float width, Color color);
                /**
                 * @brief Destroy the component.
                 */
                ~Drawable2D();
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
                 * @return Color Color object of the component
                 */
                Color getColor();
                /**
                 * @brief Get the radius value.
                 * 
                 * @return float Radius of the component
                 */
                float getRadius();
                /**
                 * @brief Get the height value.
                 * 
                 * @return float Height of the component
                 */
                float getHeight();
                /**
                 * @brief Get the width value.
                 * 
                 * @return float Width of the component
                 */
                float getWidth();
                /**
                 * @brief Set the radius of the component
                 * 
                 * @param radius Radius value
                 */
                void setRadius(float radius);
                /**
                 * @brief Set the height of the component
                 * 
                 * @param height Height value
                 */
                void setHeight(float height);
/**
                 * @brief Set the width of the component
                 * 
                 * @param width Width value
                 */
                void setWidth(float width);
                /**
                 * @brief Get the font size.
                 * 
                 * @return float Font size of the component
                 */
                float getFontSize();
                /**
                 * @brief Set the font size of the component
                 * 
                 * @param fontSize Font size value
                 */
                void setFontSize(float fontSize);
                /**
                 * @brief Get the text value.
                 * 
                 * @return std::string Text of the component
                 */
                std::string getText();
                /**
                 * @brief Set the text of the component
                 * 
                 * @param text Text value
                 */
                void setText(std::string text);
                /**
                 * @brief Get the texture path of the component

                 * 
                 * @return std::string Path to the texture of the component
                 */
                std::string getTexturePath() const;
                /**
                 * @brief Set the texture path of the component
                 * 
                 * @param texturePath Path to the texture of the component
                 */
                void setTexturePath(std::string texturePath);
                /**
                 * @brief Get the Texture object of the component
                 * 
                 * @return Texture2D Texture2D Object of the component
                 */
                Texture2D getTexture() const;
                /**
                 * @brief Set the Texture of the component
                 * 
                 * @param texturePath Path to the texture of the component
                 */
                void setTexture(std::string texturePath);

              private:
                /**
                 * @brief Radius value
                 * 
                 */
                float _radius;
                /**
                 * @brief Height value
                 * 
                 */
                float _height;
                /**
                 * @brief Width value
                 * 
                 */
                float _width;
                /**
                 * @brief Text value
                 * 
                 */
                std::string _text;
                /**
                 * @brief Font size value
                 * 
                 */
                float _fontSize;
                /**
                 * @brief Color object
                 * 
                 */
                Color _color;
                /**
                 * @brief Texture path value
                 * 
                 */
                std::string _texturePath;
                /**
                 * @brief Texture2D Object
                 * 
                 */
                Texture2D _texture;
                /**
                 * @brief CompoType object
                 * 
                 */
                indie::ecs::component::compoType _compoType;
                /**
                 * @brief DrawableType object
                 * 
                 */
                indie::ecs::component::drawableType _drawableType;
            };
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !DRAWABLE2D_HPP_ */