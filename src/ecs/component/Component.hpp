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

namespace ecs
{

    class Transform;

    enum compoType { TRANSFORM, PLAYER, WALL, RECTANGLE, CIRCLE, TEXT };

    enum drawableType { D2, D3, NONDRAWABLE };

    class IComponent {
      public:
        virtual ~IComponent() = default;
        virtual ecs::compoType getType() = 0;
        virtual bool isDrawable(ecs::drawableType drawType) = 0;

      private:
    };

    class Drawable : public IComponent {
      public:
        virtual ~Drawable()
        {
        }
        virtual ecs::compoType getType() = 0;
        virtual void draw(ecs::Transform transformCompo) = 0;
        virtual bool isDrawable(ecs::drawableType drawType) = 0;

      private:
    };

    class NonDrawable : public IComponent {
      public:
        virtual ~NonDrawable()
        {
        }
        virtual ecs::compoType getType() = 0;
        virtual bool isDrawable(ecs::drawableType drawType) = 0;

      private:
    };

    class Transform : public NonDrawable {
      public:
        Transform();
        Transform(float posX, float posY, float posZ, float speedX, float speedY, float speedZ);
        ~Transform();
        ecs::compoType getType(void) override;
        void printProperties();
        void update(float posX, float posY, float speedX, float speedY);
        float getX() const;
        float getY() const;
        float getZ() const;
        void setX(float posX);
        void setY(float posY);
        void setZ(float posZ);
        float getSpeedX() const;
        float getSpeedY() const;
        float getSpeedZ() const;
        bool isDrawable(ecs::drawableType drawType);

      private:
        float _posX;
        float _posY;
        float _posZ;
        float _speedX;
        float _speedY;
        float _speedZ;
        ecs::drawableType _drawType;
    };

    class Player : public Drawable {
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
    };

    class Text : public Drawable {
      public:
        Text();
        Text(std::string text, float textSize, Color color);
        ~Text();
        ecs::compoType getType() override;
        void draw(ecs::Transform transformCompo) override;
        void update(ecs::Transform transformCompo);
        bool isDrawable(ecs::drawableType drawType);

      private:
        float _textSize;
        ecs::drawableType _drawType;
        Color _color;
        std::string _text;
    };

} // namespace ecs

#endif /* !COMPONENT_HPP_ */
