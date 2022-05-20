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

namespace ecs {

    enum compoType {
        TRANSFORM
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
            virtual void draw() = 0;
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

        protected:
        private:
            float _posX;
            float _posY;
            float _speedX;
            float _speedY;

    };

}

#endif /* !COMPONENT_HPP_ */
