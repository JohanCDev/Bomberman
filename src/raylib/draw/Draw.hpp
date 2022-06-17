/**
 * @file Draw.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Draw encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef DRAW_HPP_
#define DRAW_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// @brief Draw class encapsulation
        class Draw {
          public:
            /**
             * @brief Construct a new Draw object
             * 
             * @param posX X position
             * @param posY Y position
             * @param fontSize Font size
             * @param color Color
             */
            Draw(int posX = 0, int posY = 0, float fontSize = 100, ::Color color = BLACK);
            /**
             * @brief Destroy the Draw object
             * 
             */
            ~Draw() = default;

            /**
             * @brief Get posX
             * 
             * @return int X position
             */
            int getPositionX() const;
            /**
             * @brief Set posX
             * 
             * @param positionX X position
             */
            void setPositionX(int positionX);
            /**
             * @brief Get posY
             * 
             * @return int Y position
             */
            int getPositionY() const;
            /**
             * @brief Set posY
             * 
             * @param positionY Y position
             */
            void setPositionY(int positionY);
            /**
             * @brief Get font size
             * 
             * @return float Font size
             */
            float getFontSize() const;
            /**
             * @brief Set font size
             * 
             * @param fontSize Font size
             */
            void setFontSize(float fontSize);
            /**
             * @brief Get color
             * 
             * @return Color Draw color
             */
            ::Color getColor() const;
            /**
             * @brief Set color
             * 
             * @param color Draw color
             */
            void setColor(::Color color);
            /**
             * @brief Draw text (using default font)
             * 
             * @param text Text to draw
             */
            void drawText(const std::string text);
            /**
             * @brief Draw current FPS
             */
            void drawFPS();
            /**
             * @brief Draw current FPS
             * 
             * @param posX X position
             * @param posY Y position
             */
            static void drawFPS(int posX, int posY);
            /**
             * @brief Draw text using font and additional parameters
             * 
             * @param font Drawing font
             * @param text Drawing text
             * @param position Drawing position
             * @param spacing Drawing spacing
             */
            void drawTextEx(::Font font, const char *text, ::Vector2 position, float spacing);
            /**
             * @brief Draw text using font and additional parameters
             * 
             * @param font Drawing font
             * @param text Drawing text
             * @param position Drawing position
             * @param fontSize Drawing font size
             * @param spacing Drawing spacing
             * @param color Drawing color
             */
            static void drawTextEx(
                ::Font font, const char *text, ::Vector2 position, float fontSize, float spacing, ::Color color);

            /**
             * @brief Draw text using Font and pro parameters (rotation)
             * 
             * @param font Drawing font
             * @param text Drawing text
             * @param position Drawing position
             * @param origin Drawing origin
             * @param rotation Drawing rotation
             * @param spacing Drawing spacing
             */
            void drawTextPro(
                ::Font font, const char *text, ::Vector2 position, ::Vector2 origin, float rotation, float spacing);
            /**
             * @brief Draw text using Font and pro parameters (rotation)
             * 
             * @param font Drawing font
             * @param text Drawing text
             * @param position Drawing position
             * @param origin Drawing origin
             * @param rotation Drawwing rotation
             * @param fontSize Drawing font size
             * @param spacing Drawing spacing
             * @param color Drawing color
             */
            static void drawTextPro(::Font font, const char *text, ::Vector2 position, ::Vector2 origin, float rotation,
                float fontSize, float spacing, ::Color color);
            /**
             * @brief Draw one character (codepoint)
             * 
             * @param font Drawing font
             * @param codepoint Drawing codepoint
             * @param position Drawing position
             */
            void drawTextCodepoint(::Font font, int codepoint, ::Vector2 position);
            /**
             * @brief Draw one character (codepoint)
             * 
             * @param font Drawing font
             * @param codepoint Drawing codepoint
             * @param position Drawing position
             * @param fontSize Drawing fontsize
             * @param color Drawing color
             */
            static void drawTextCodepoint(
                ::Font font, int codepoint, ::Vector2 position, float fontSize, ::Color color);
            /**
             * @brief Draw a plane XZ
             * 
             * @param centerPos Drawing Position (Center)
             * @param size Drawing size
             */
            void drawPlane(::Vector3 centerPos, ::Vector2 size);
            /**
             * @brief Draw a plane XZ
             * 
             * @param centerPos Drawing Position (Center)
             * @param size Drawing size
             * @param color Drawing color
             */
            static void drawPlane(::Vector3 centerPos, ::Vector2 size, ::Color color);
            /**
             * @brief Draw a ray line
             * 
             * @param ray Drawing ray line
             */
            void drawRay(::Ray ray);
            /**
             * @brief Draw a ray line
             * 
             * @param ray Drawing ray line
             * @param color Drawing color
             */
            static void drawRay(::Ray ray, ::Color color);
            /**
             * @brief Draw a grid (centered at (0, 0, 0))
             * 
             * @param slices Drawing slices
             * @param spacing Drawing spacing
             */
            static void drawGrid(int slices, float spacing);

          private:
            /**
             * @brief Drawing position X
             * 
             */
            int _posX;
            /**
             * @brief Drawing position Y
             * 
             */
            int _posY;
            /**
             * @brief Drawing font size
             * 
             */
            float _fontSize;
            /**
             * @brief Drawing color
             * 
             */
            ::Color _color;
        };
    } // namespace raylib
} // namespace indie

#endif /* !DRAW_HPP_ */
