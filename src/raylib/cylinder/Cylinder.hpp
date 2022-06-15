/**
 * @file Cylinder.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Cylinder encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// @brief Cylinder class encapsulation
        class Cylinder {
          public:
            /**
             * @brief Construct a new Cylinder object
             * 
             * @param position Cylinder position
             * @param radiusTop Cylinder top radius
             * @param radiusBottom Cylinder bottom radius
             * @param height Cylinder height
             * @param slices Cylinder slices
             * @param color Cylinder color
             */
            Cylinder(::Vector3 position, float radiusTop, float radiusBottom, float height, int slices,
                ::Color color = BLACK);
            /**
             * @brief Destroy the Cylinder object
             * 
             */
            ~Cylinder() = default;
            /**
             * @brief Get cylinder position
             * 
             * @return Vector3 Cylinder position
             */
            ::Vector3 getPosition() const;
            /**
             * @brief Set cylinder position
             * 
             * @param position Cylinder position
             */
            void setPosition(::Vector3 position);
            /**
             * @brief Get cylinder top radius
             * 
             * @return float Cylinder top radius
             */
            float getRadiusTop() const;
            /**
             * @brief Set cylinder radius top
             * 
             * @param radiusTop Cylinder top radius
             */
            void setRadiusTop(float radiusTop);
            /**
             * @brief Get cylinder bottom radius
             * 
             * @return Cylinder bottom radius
             */
            float getRadiusBottom() const;
            /**
             * @brief Set cylinder bottom radius
             * 
             * @param radiusBottom 
             */
            void setRadiusBottom(float radiusBottom);
            /**
             * @brief Get cylinder height
             * 
             * @return float Cylinder height
             */
            float getHeight() const;
            /**
             * @brief Set cylinder height
             * 
             * @param height Cylinder height
             */
            void setHeight(float height);
            /**
             * @brief Get cylinder slices
             * 
             * @return int Cylinder slices
             */
            int getSlices() const;
            /**
             * @brief Set cylinder slices
             * 
             * @param slices Cylinder slices
             */
            void setSlices(int slices);
            /**
             * @brief Get cylinder color
             * 
             * @return Color Cylinder color
             */
            ::Color getColor() const;
            /**
             * @brief Set cylinder color
             * 
             * @param color Cylinder color
             */
            void setColor(::Color color);
            /**
             * @brief Draw a cylinder/cone
             */
            void draw();
            /**
             * @brief Draw a cylinder/cone
             * 
             * @param position Cylinder position
             * @param radiusTop Cylinder top radius
             * @param radiusBottom Cylinder bottom radius
             * @param height Cylinder height
             * @param slices Cylinder slices
             * @param color Cylinder color
             */
            static void draw(
                ::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, ::Color color);
            /**
             * @brief Draw a cylinder with base at startPos and top at endPos
             * 
             * @param startPos Cylinder startPos
             * @param endPos Cylinder endPos
             */
            void drawEx(::Vector3 startPos, ::Vector3 endPos);
            /**
             * @brief Draw a cylinder with base at startPos and top at endPos
             * 
             * @param startPos Cylinder startPos
             * @param endPos Cylinder endPos
             * @param radiusTop Cylinder top radius
             * @param radiusBottom Cylinder bottom radius
             * @param height Cylinder height
             * @param slices Cylinder slices
             * @param color Cylinder color
             */
            static void drawEx(::Vector3 startPos, ::Vector3 endPos, float radiusTop, float radiusBottom, float height,
                int slices, ::Color color);

            /**
             * @brief Draw a cylinder/cone wires
             */
            void drawWires();
            /**
             * @brief Draw cylinder/cone wires
             * 
             * @param position Cylinder wires position
             * @param radiusTop Cylinder wires top radius
             * @param radiusBottom Cylinder wires bottom radius
             * @param height Cylinder wires height
             * @param slices Cylinder wires slices
             * @param color Cylinder wires color
             */
            static void drawWires(
                ::Vector3 position, float radiusTop, float radiusBottom, float height, int slices, ::Color color);
            /**
             * @brief Draw a cylinder wires with base at startPos and top at endPos
             * 
             * @param startPos Cylinder wires startPos
             * @param endPos Cylinder wires endPos
             */
            void drawWiresEx(::Vector3 startPos, ::Vector3 endPos);
            /**
             * @brief Draw a cylinder wires with base at startPos and top at endPos
             * 
             * @param startPos Cylinder wires startPos
             * @param endPos Cylinder wires endPos
             * @param radiusTop Cylinder wires top radius
             * @param radiusBottom Cylinder wires bottom radius
             * @param height Cylinder wires height
             * @param slices Cylinder wires slices
             * @param color Cylinder wires color
             */
            static void drawWiresEx(::Vector3 startPos, ::Vector3 endPos, float radiusTop, float radiusBottom,
                float height, int slices, ::Color color);

          private:
            /**
             * @brief Cylinder position
             * 
             */
            ::Vector3 _position;
            /**
             * @brief Cylinder top radius
             * 
             */
            float _radiusTop;
            /**
             * @brief Cylinder bottom radius
             * 
             */
            float _radiusBottom;
            /**
             * @brief Cylinder height
             * 
             */
            float _height;
            /**
             * @brief Cylinder slices
             * 
             */
            int _slices;
            /**
             * @brief Cylinder color
             * 
             */
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !CYLINDER_HPP_ */
