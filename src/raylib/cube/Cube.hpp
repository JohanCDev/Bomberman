/**
 * @file Cube.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Cube encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// @brief Cube class encapsulation
        class Cube {
          public:
            /**
             * @brief Construct a new Cube object
             * 
             * @param x Cube X position
             * @param y Cube Y position
             * @param z Cube Z position
             * @param width Cube Width
             * @param height Cube height
             * @param length Cube length
             */
            Cube(float x, float y, float z, float width, float height, float length);
            /**
             * @brief Construct a new Cube object
             * 
             * @param x Cube X position
             * @param y Cube Y position
             * @param z Cube Z position
             * @param width Cube Width
             * @param height Cube height
             * @param length Cube length
             * @param color Cube Color
             */
            Cube(float x, float y, float z, float width, float height, float length, ::Color color);
            /**
             * @brief Destroy the Cube object
             * 
             */
            ~Cube() = default;

            /**
             * @brief Get cube position
             * 
             * @return Vector3 Cube position
             */
            ::Vector3 getPosition() const;

            /**
             * @brief Set the Cube position
             * 
             * @param newX Cube X position
             * @param newY Cube Y position
             * @param newZ Cube Z position
             */
            void setPosition(float newX, float newY, float newZ);
            /**
             * @brief Get cube size
             * 
             * @return Vector3 Cube size
             */
            ::Vector3 getSize() const;

            /**
             * @brief Set the Cube size
             * 
             * @param newWidth Cube width value
             * @param newHeight Cube height value
             * @param newLength Cube length value
             */
            void setSize(float newWidth, float newHeight, float newLength);
            /**
             * @brief Get Cube color
             * 
             * @return Color Cube color
             */
            ::Color getColor() const;

            /**
             * @brief Set Cube color
             * 
             * @param color Cube color
             */
            void setColor(::Color color);
            /**
             * @brief Draw cube
             */
            void draw();
            /**
             * @brief Draw cube
             * 
             * @param position Cube position
             * @param size Cube size
             * @param color Cube color
             */
            static void draw(::Vector3 position, ::Vector3 size, ::Color color);
            /**
             * @brief Draw cube wires
             */
            void drawWires();
            /**
             * @brief Draw cube wires
             * 
             * @param position Cube position
             * @param size Cube size
             * @param color Cube color
             */
            static void drawWires(::Vector3 position, ::Vector3 size, ::Color color);
            /**
             * @brief Draw textured-cube
             * 
             * @param texture Cube texture
             * @param position Cube position
             * @param width Cube width
             * @param height Cube height
             * @param length Cube length
             * @param color Cube color
             */
            static void drawTexture(
                ::Texture2D texture, ::Vector3 position, float width, float height, float length, ::Color color);

          private:
            /**
             * @brief Cube position
             * 
             */
            ::Vector3 _position;
            /**
             * @brief Cube size
             * 
             */
            ::Vector3 _size;
            /**
             * @brief Cube color
             * 
             */
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !CUBE_HPP_ */
