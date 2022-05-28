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

                /**
                * @brief Draw text using font and additional parameters
                */
                void drawTextEx(::Font font, const char *text, ::Vector2 position, float spacing);

                /**
                * @brief Draw text using Font and pro parameters (rotation)
                */
                void drawTextPro(::Font font, const char *text, ::Vector2 position, ::Vector2 origin, float rotation, float spacing);

                /**
                * @brief Draw one character (codepoint)
                */
                void drawTextCodepoint(::Font font, int codepoint, ::Vector2 position);

            private:
                int _posX;
                int _posY;
                float _fontSize;
                ::Color _color;
        };
    }
}

#endif /* !DRAW_HPP_ */
