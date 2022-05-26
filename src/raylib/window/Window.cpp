/*
** EPITECH PROJECT, 2022
** Raylib::Window
** File description:
** Raylib::Window
*/

#include "Window.hpp"

void raylib::Window::initWindow(size_t width, size_t heigth, const std::string title, bool resizable, int baseFps)
{
    if (resizable)
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    else
        SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(width, heigth, title.c_str());
    SetTargetFPS(baseFps);
}

void raylib::Window::destroyWindow()
{
    CloseWindow();
}

bool raylib::Window::windowShouldClose()
{
    return (WindowShouldClose());
}

void raylib::Window::beginDrawing()
{
    BeginDrawing();
}

void raylib::Window::endDrawing()
{
    EndDrawing();
}

void raylib::Window::clearBackground()
{

    ClearBackground(RAYWHITE);
}
