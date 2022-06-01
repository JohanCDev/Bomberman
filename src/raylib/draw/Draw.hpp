/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Draw
*/

#ifndef DRAW_HPP_
#define DRAW_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        class Draw {
            public:
                Draw(int posX = 0, int posY = 0, float fontSize = 100, ::Color color = BLACK);
                ~Draw() = default;

                /**
                * @brief Get posX
                */
                int getPositionX() const;

                /**
                * @brief Set posX
                */
                void setPositionX(int positionX);

                /**
                * @brief Get posY
                */
                int getPositionY() const;

                /**
                * @brief Set posY
                */
                void setPositionY(int positionY);

                /**
                * @brief Get font size
                */
                float getFontSize() const;

                /**
                * @brief Set font size
                */
                void setFontSize(float fontSize);

                /**
                * @brief Get color
                */
                ::Color getColor() const;

                /**
                * @brief Set color
                */
                void setColor(::Color color);

                /**
                * @brief Draw text (using default font)
                */
                void drawText(const std::string text);

                /**
                * @brief Draw current FPS
                */
                void drawFPS();
                static void drawFPS(int posX, int posY);

                /**
                * @brief Draw text using font and additional parameters
                */
                void drawTextEx(::Font font, const char *text, ::Vector2 position, float spacing);
                static void drawTextEx(::Font font, const char *text, ::Vector2 position, float fontSize, float spacing, ::Color color);

                /**
                * @brief Draw text using Font and pro parameters (rotation)
                */
                void drawTextPro(::Font font, const char *text, ::Vector2 position, ::Vector2 origin, float rotation, float spacing);
                static void drawTextPro(::Font font, const char *text, ::Vector2 position, ::Vector2 origin, float rotation, float fontSize, float spacing, ::Color color);

                /**
                * @brief Draw one character (codepoint)
                */
                void drawTextCodepoint(::Font font, int codepoint, ::Vector2 position);
                static void drawTextCodepoint(::Font font, int codepoint, ::Vector2 position, float fontSize, ::Color color);

                /**
                * @brief Draw a plane XZ
                */
                void drawPlane(::Vector3 centerPos, ::Vector2 size);
                static void drawPlane(::Vector3 centerPos, ::Vector2 size, ::Color color);

                /**
                * @brief Draw a ray line
                */
                void drawRay(::Ray ray);
                static void drawRay(::Ray ray, ::Color color);

                /**
                * @brief Draw a grid (centered at (0, 0, 0))
                */
                static void drawGrid(int slices, float spacing);

            private:
                int _posX;
                int _posY;
                float _fontSize;
                ::Color _color;
        };
    }
}

#endif /* !DRAW_HPP_ */
