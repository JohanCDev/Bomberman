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
        PLAYER,
        WALL
    };

    class IComponent {
        public:
            virtual ~IComponent() {}
            virtual ecs::compoType getType() = 0;

        private:
    };

    class Drawable : public IComponent {

        public:
            virtual ~Drawable() {}
            virtual ecs::compoType getType() = 0;
            virtual void draw(ecs::Transform transformCompo) = 0;
        private:

    };

    class NonDrawable : public IComponent {

        public:
            virtual ~NonDrawable() {}
            virtual ecs::compoType getType() = 0;

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
            Transform(float posX, float posY, float posZ, float speedX, float speedY, float speedZ) {
                this->_posX = posX;
                this->_posY = posY;
                this->_posZ = posZ;
                this->_speedX = speedX;
                this->_speedY = speedY;
                this->_speedZ = speedZ;
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

            float getZ() const {
                return (this->_posZ);
            }

            void setX(float posX) {
                this->_posX = posX;
            }

            void setY(float posY) {
                this->_posY = posY;
            }

            void setZ(float posZ) {
                this->_posZ = posZ;
            }

            float getSpeedX() const {
                return (this->_speedX);
            }

            float getSpeedY() const {
                return (this->_speedY);
            }

            float getSpeedZ() const {
                return (this->_speedZ);
            }

        private:
            float _posX;
            float _posY;
            float _posZ;
            float _speedX;
            float _speedY;
            float _speedZ;

    };

    class Player : public Drawable {

        public:
            Player() {}

            Player(std::string texture, float radius, Color color) {
                this->_radius = radius;
                this->_color = color;
                this->_texture = texture;
            }

            ~Player() {}

            ecs::compoType getType() override {
                return (ecs::compoType::PLAYER);
            }

            void draw(ecs::Transform transformCompo) {
                Raylib raylib;
                Vector3 vec = (Vector3) {transformCompo.getX(), transformCompo.getY(), transformCompo.getZ()};
                raylib.drawSphere(vec, this->_radius, this->_color);
            }

            void update(ecs::Transform transformCompo) {

            }

        private:
            float _radius;
            Color _color;
            std::string _texture;

    };

    class Wall : public Drawable {

        public:
            Wall() {}

            Wall(std::string texture, float height, float width, Color color) {
                this->_height = height;
                this->_width = width;
                this->_color = color;
                this->_texture_path = texture;
                this->_texture = LoadTexture(this->_texture_path.c_str());
            }

            ~Wall() {}

            ecs::compoType getType() override {
                return (ecs::compoType::WALL);
            }

            void draw(ecs::Transform transformCompo) {
                Raylib raylib;
                if (this->_texture_path == "") {
                    Vector3 vec = (Vector3) {transformCompo.getX(), transformCompo.getY(), transformCompo.getZ()};
                    raylib.drawRectangle3D(vec, this->_width, this->_height, (float)2.0, this->_color);
                } else {
                    // draw 3d rectangle with texture
                }
            }

        private:
            float _width;
            float _height;
            Color _color;
            std::string _texture_path;
            Texture2D _texture;
    };

}

#endif /* !COMPONENT_HPP_ */
