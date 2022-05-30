/*
** EPITECH PROJECT, 2022
** Raylib::Window
** File description:
** Raylib::Window
*/

#include "Window.hpp"

void indie::raylib::Window::initWindow(int width, int height, const std::string title, bool resizable, int baseFps)
{
    if (resizable)
        ::SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    else
        ::SetConfigFlags(FLAG_VSYNC_HINT);
    ::InitWindow(width, height, title.c_str());
    ::SetTargetFPS(baseFps);
}

void indie::raylib::Window::destroyWindow()
{
    ::CloseWindow();
}

int indie::raylib::Window::getWidth()
{
    return ::GetScreenWidth();
}

int indie::raylib::Window::getHeight()
{
    return ::GetScreenHeight();
}

bool indie::raylib::Window::windowShouldClose()
{
    return ::WindowShouldClose();
}

void indie::raylib::Window::beginDrawing()
{
    ::BeginDrawing();
}

void indie::raylib::Window::endDrawing()
{
    ::EndDrawing();
}

void indie::raylib::Window::clearBackground()
{
    ::ClearBackground(RAYWHITE);
}
