/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        class Cylinder {
            public:
                Cylinder(::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, ::Color color = BLACK);
                ~Cylinder() = default;

                /**
                * @brief Get cylinder position
                */
                ::Vector3 getPosition() const;

                /**
                * @brief Set cylinder position
                */
                void setPosition(::Vector3 position);

                /**
                * @brief Get cylinder radius top
                */
                float getRadiusTop() const;

                /**
                * @brief Set cylinder radius top
                */
                void setRadiusTop(float radiusTop);

                /**
                * @brief Get cylinder radius bottom
                */
                float getRadiusBottom() const;

                /**
                * @brief Set cylinder radius bottom
                */
                void setRadiusBottom(float radiusBottom);

                /**
                * @brief Get cylinder height
                */
                float getHeight() const;

                /**
                * @brief Set cylinder height
                */
                void setHeight(float height);

                /**
                * @brief Get cylinder slices
                */
                int getSlices() const;

                /**
                * @brief Set cylinder slices
                */
                void setSlices(int slices);

                /**
                * @brief Get cylinder color
                */
                ::Color getColor() const;

                /**
                * @brief Set cylinder color
                */
                void setColor(::Color color);

                /**
                * @brief Draw a cylinder/cone
                */
                void draw();
                static void draw(::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, ::Color color);

                /**
                * @brief Draw a cylinder with base at startPos and top at endPos
                */
                void drawEx(::Vector3 startPos, ::Vector3 endPos);
                static void drawEx(::Vector3 startPos, ::Vector3 endPos, float radiusTop, float radiusBottom, float height, int slices, ::Color color);

                /**
                * @brief Draw a cylinder/cone wires
                */
                void drawWires();
                static void drawWires(::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, ::Color color);

                /**
                * @brief Draw a cylinder wires with base at startPos and top at endPos
                */
                void drawWiresEx(::Vector3 startPos, ::Vector3 endPos);
                static void drawWiresEx(::Vector3 startPos, ::Vector3 endPos, float radiusTop, float radiusBottom, float height, int slices, ::Color color);

            private:
                ::Vector3 _position;
                float _radiusTop;
                float _radiusBottom;
                float _height;
                int _slices;
                ::Color _color;
        };
    }
}

#endif /* !CYLINDER_HPP_ */
