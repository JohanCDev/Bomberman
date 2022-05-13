/*
** EPITECH PROJECT, 2022
** Raylib
** File description:
** Raylib
*/

#ifndef RAYLIB_HPP_
#define RAYLIB_HPP_

#include "raylib.h"
#include <cstdio>
#include <string>

class Raylib {
    public:
        Raylib();
        ~Raylib();

        // Setup function
        void initWindow(std::size_t width, std::size_t heigth, const std::string title);
        void destroyWindow();
        
        // Event function
        bool isKeyPressed(KeyboardKey key);
        
        // Window function
        void beginDrawing();
        void endDrawing();
        void clearBackground();
        bool windowShouldClose();

        // Drawing function
        void drawText(const std::string text, int posX, int posY, int fontSize, Color color);
        void drawCircle(int posX, int posY, float radius, Color color);
        void drawRectangle(int posX, int posY, int width, int height, Color color);

    protected:
    private:
};

#endif /* !RAYLIB_HPP_ */
