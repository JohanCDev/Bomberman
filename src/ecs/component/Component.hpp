/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

extern "C"
{
#include <raylib.h>
}

#include <iostream>
#include "../../raylib/Raylib.hpp"

namespace indie
{
    namespace ecs
    {

        class Transform;

        enum compoType { TRANSFORM, PLAYER, WALL, DRAWABLE2D, UNKOWN };

        enum drawableType { CIRCLE, TEXT, RECTANGLE, UNKNOWN };

        class IComponent {
          public:
            virtual ~IComponent() = default;
            virtual ecs::compoType getType() = 0;

          private:
        };

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

        class NonDrawable : public IComponent {
          public:
            virtual ~NonDrawable()
            {
            }
            virtual ecs::compoType getType() = 0;

          private:
        };

        class Transform : public NonDrawable {
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

    } // namespace ecs
} // namespace indie

#endif /* !COMPONENT_HPP_ */
