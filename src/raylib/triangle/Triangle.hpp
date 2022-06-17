/**
 * @file Triangle.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Triangle encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef TRIANGLE_HPP_
#define TRIANGLE_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// @brief Triangle class encapsulation
        class Triangle {
          public:
            /**
             * @brief Construct a new Triangle object
             * 
             * @param v1 First position vector
             * @param v2 Second position vector
             * @param v3 Third position vector
             * @param color Triangle color
             */
            Triangle(::Vector2 v1, ::Vector2 v2, ::Vector2 v3, ::Color color = BLACK);
            /**
             * @brief Destroy the Triangle object
             * 
             */
            ~Triangle() = default;
            /**
             * @brief Get triangle first position vector
             * 
             * @return Vector2 First position vector
             */
            ::Vector2 getVec1() const;
            /**
             * @brief Set triangle first position vector
             * 
             * @param v1 First position vector
             */
            void setVec1(::Vector2 v1);
            /**
             * @brief Get triangle second position vector
             * 
             * @return Vector2 Second position vector
             */
            ::Vector2 getVec2() const;
            /**
             * @brief Set triangle second position vector
             * 
             * @param v2 Second position vector
             */
            void setVec2(::Vector2 v2);
            /**
             * @brief Get triangle third position vector
             * 
             * @return Vector2 Third position vector
             */
            ::Vector2 getVec3() const;
            /**
             * @brief Set triangle third position vector
             * 
             * @param v3 Third position vector
             */
            void setVec3(::Vector2 v3);
            /**
             * @brief Get triangle color
             * 
             * @return Color Triangle color
             */
            ::Color getColor() const;
            /**
             * @brief Set triangle color
             * 
             * @param color Triangle color
             */
            void setColor(::Color color);
            /**
             * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
             */
            void draw();
            /**
             * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
             * 
             * @param v1 First position vector
             * @param v2 Second position vector
             * @param v3 Third position vector
             * @param color Triangle color
             */
            static void draw(::Vector2 v1, ::Vector2 v2, ::Vector2 v3, ::Color color);
            /**
             * @brief Draw triangle outline (vertex in counter-clockwise order!)
             */
            void drawLines();
            /**
             * @brief Draw triangle outline (vertex in counter-clockwise order!)
             * 
             * @param v1 First position vector
             * @param v2 Second position vector
             * @param v3 Third position vector
             * @param color Triangle color
             */
            static void drawLines(::Vector2 v1, ::Vector2 v2, ::Vector2 v3, ::Color color);
            /**
             * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
             * 
             * @param v1 First position vector
             * @param v2 Second position vector
             * @param v3 Third position vector 
             */
            void draw3D(::Vector3 v1, ::Vector3 v2, ::Vector3 v3);
            /**
             * @brief Draw a color-filled triangle (vertex in counter-clockwise order!)
             * 
             * @param v1 First position vector
             * @param v2 Second position vector
             * @param v3 Third position vector
             * @param color Triangle color
             */
            static void draw3D(::Vector3 v1, ::Vector3 v2, ::Vector3 v3, ::Color color);

          private:
            /**
             * @brief Vector2 object
             * 
             */
            ::Vector2 _v1;
            /**
             * @brief Vector2 object
             * 
             */
            ::Vector2 _v2;
            /**
             * @brief Vector2 object
             * 
             */
            ::Vector2 _v3;
            /**
             * @brief Color object
             * 
             */
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !TRIANGLE_HPP_ */
