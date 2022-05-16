/*
** EPITECH PROJECT, 2022
** Raylib
** File description:
** Raylib
*/

#ifndef RAYLIB_HPP_
#define RAYLIB_HPP_

#include <raylib.h>
#include <cstdio>
#include <string>

class Raylib {
    public:
        Raylib();
        ~Raylib();

        // Setup function
        static void initWindow(size_t width = 1920, size_t heigth = 1080, const std::string title = "Window", bool resizable = true, int baseFps = 60);
        static void destroyWindow();
        
        // Event function
        static bool isKeyPressed(KeyboardKey key);
        
        // Window function
        static void beginDrawing();
        static void endDrawing();
        static void clearBackground();
        static bool windowShouldClose();

        // Drawing function
        static void drawText(const std::string text, int posX, int posY, int fontSize, Color color);
        static void drawCircle(int posX, int posY, float radius, Color color);
        static void drawRectangle(int posX, int posY, int width, int height, Color color);

    protected:
    private:
};

#endif /* !RAYLIB_HPP_ */
