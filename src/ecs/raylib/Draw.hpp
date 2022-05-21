/*
** EPITECH PROJECT, 2022
** Bomberman
** File description:
** Draw
*/

#ifndef DRAW_HPP_
#define DRAW_HPP_

#include "Raylib.hpp"

namespace Raylib {
    class Draw {
        public:
            Draw() = default;
            ~Draw() = default;

            // Drawing function
            static void drawText(const std::string text, int posX, int posY, int fontSize, Color color);
            static void drawCircle(int posX, int posY, float radius, Color color);
            static void drawRectangle(int posX, int posY, int width, int height, Color color);

        protected:
        private:
    };
}

#endif /* !DRAW_HPP_ */
