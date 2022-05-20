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
#include "Raylib.hpp"

namespace ecs {

    class Transform;

    enum compoType {
        TRANSFORM,
        CIRCLE,
        RECTANGLE
    };

    class IComponent {
        public:
            virtual ~IComponent() {}
            virtual ecs::compoType getType() = 0;
        protected:

        private:
    };

    class Drawable : public IComponent {

        public:
            virtual ~Drawable() {}
            virtual ecs::compoType getType() = 0;
            virtual void draw(ecs::Transform transformCompo) = 0;
        protected:
        private:

    };

    class NonDrawable : public IComponent {

        public:
            virtual ~NonDrawable() {}
            virtual ecs::compoType getType() = 0;
        protected:
        private:

    };

    class Transform : public NonDrawable {

        public:
            Transform() {
                this->_posX = 0;
                this->_posY = 0;
                this->_speedX = 0;
                this->_speedY = 0;
            }
            Transform(float posX, float posY, float speedX, float speedY) {
                this->_posX = posX;
                this->_posY = posY;
                this->_speedX = speedX;
                this->_speedY = speedY;
            }
            ~Transform() {}

            ecs::compoType getType(void) override {
                return (ecs::compoType::TRANSFORM);
            }

            void printProperties() {
                std::cout << this->_posX << " " << this->_posY << " " << this->_speedX << " " << this->_speedY << std::endl;
            }

            void update(float posX, float posY, float speedX, float speedY) {
                this->_posX = posX;
                this->_posY = posY;
                this->_speedX = speedX;
                this->_speedY = speedY;
            }

            float getX() const {
                return (this->_posX);
            }

            float getY() const {
                return (this->_posY);
            }

            float speedX() const {
                return (this->_speedX);
            }

            float speedY() const {
                return (this->_speedY);
            }

        protected:
        private:
            float _posX;
            float _posY;
            float _speedX;
            float _speedY;

    };

    class Circle : public Drawable {

        public:
            Circle() {}

            Circle(double radius, Color color) {
                this->_radius = radius;
                this->_color = color;
            }

            ~Circle() {}

            ecs::compoType getType() override {
                return (ecs::compoType::CIRCLE);
            }

            void draw(ecs::Transform transformCompo) {
                Raylib raylib;
                raylib.drawCircle(transformCompo.getX(), transformCompo.getY(), this->_radius, this->_color);
            }

        protected:
        private:
            double _radius;
            Color _color;

    };

    class Rectangle : public Drawable {

        public:
            Rectangle() {}

            Rectangle(int height, int width, Color color) {
                this->_height = height;
                this->_width = width;
                this->_color = color;
            }

            ~Rectangle() {}

            ecs::compoType getType() override {
                return (ecs::compoType::CIRCLE);
            }

            void draw(ecs::Transform transformCompo) {
                Raylib raylib;
                raylib.drawRectangle(transformCompo.getX(), transformCompo.getY(), this->_width, this->_height, this->_color);
            }

        protected:
        private:
            int _width;
            int _height;
            Color _color;

    };

}

#endif /* !COMPONENT_HPP_ */
