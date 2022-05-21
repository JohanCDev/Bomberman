/*
** EPITECH PROJECT, 2022
** Raylib::Window
** File description:
** Raylib::Window
*/

#include "Window.hpp"

void Raylib::Window::initWindow(size_t width, size_t heigth, const std::string title, bool resizable, int baseFps)
{
    if (resizable)
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    else
        SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(width, heigth, title.c_str());
    SetTargetFPS(baseFps);
}

void Raylib::Window::destroyWindow()
{
    CloseWindow();
}

bool Raylib::Window::windowShouldClose()
{
    return (WindowShouldClose());
}

void Raylib::Window::beginDrawing()
{
    BeginDrawing();
}

void Raylib::Window::endDrawing()
{
    EndDrawing();
}

void Raylib::Window::clearBackground()
{

    ClearBackground(RAYWHITE);
}
