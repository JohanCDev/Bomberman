/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <iostream>
#include "../../raylib/Raylib.hpp"

namespace indie
{
    namespace ecs
    {
        namespace component
        {
            class Transform;

            enum compoType { TRANSFORM, DRAWABLE2D, DRAWABLE3D, ALIVE, UNKOWN };

            enum drawableType { CIRCLE, TEXT, RECTANGLE, SPHERE, CUBE, UNKNOWN };

            class IComponent {
              public:
                /**
                 * @brief Create a new IComponent.
                 */
                virtual ~IComponent() = default;

                /**
                 * @brief Get type of the component.
                 *
                 * @return the compoType value of the component.
                 */
                virtual indie::ecs::component::compoType getType() = 0;

              private:
            };

            /*class Player : public Drawable {
              public:
                Player();
                Player(std::string texture, float radius, Color color);
                ~Player();
                ecs::compoType getType() override;
                void draw(ecs::Transform transformCompo) override;
                void update(ecs::Transform transformCompo);
                bool isDrawable(ecs::drawableType drawType);

              private:
                float _radius;
                ecs::drawableType _drawType;
                Color _color;
                std::string _texture;
            };

            class Wall : public Drawable {
              public:
                Wall();
                Wall(std::string texture, float height, float width, Color color);
                ~Wall();
                ecs::compoType getType() override;
                void draw(ecs::Transform transformCompo) override;
                bool isDrawable(ecs::drawableType drawType);

              private:
                float _width;
                float _height;
                Color _color;
                ecs::drawableType _drawType;
                std::string _texture_path;
                Texture2D _texture;
            };

            class Rectangle : public Drawable {
              public:
                Rectangle();
                Rectangle(std::string texture, float height, float width, Color color);
                ~Rectangle();
                ecs::compoType getType() override;
                void draw(ecs::Transform transformCompo) override;
                void update(ecs::Transform transformCompo);
                bool isDrawable(ecs::drawableType drawType);

              private:
                float _height;
                float _width;
                ecs::drawableType _drawType;
                Color _color;
                std::string _texture_path;
                Texture2D _texture;
            };

            class Circle : public Drawable {
              public:
                Circle();
                Circle(std::string texture, float radius, Color color);
                ~Circle();
                ecs::compoType getType() override;
                void draw(ecs::Transform transformCompo) override;
                void update(ecs::Transform transformCompo);
                bool isDrawable(ecs::drawableType drawType);

              private:
                float _radius;
                ecs::drawableType _drawType;
                Color _color;
                std::string _texture_path;
                Texture2D _texture;
            };*/

            /*class Text : public IComponent {
              public:
                Text();
                Text(std::string text, float textSize, Color color);
                ~Text();
                ecs::compoType getType() override;
                void update(ecs::Transform transformCompo);
                // bool isDrawable(ecs::drawableType drawType);

              private:
                float _textSize;
                // ecs::drawableType _drawType;
                Color _color;
                std::string _text;
            };*/
        } // namespace component
    }     // namespace ecs
} // namespace indie

#endif /* !COMPONENT_HPP_ */
