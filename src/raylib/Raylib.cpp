/*
** EPITECH PROJECT, 2022
** Raylib
** File description:
** Raylib
*/

#include "Raylib.hpp"

indie::Raylib::Raylib()
{
}

indie::Raylib::~Raylib()
{
}

void indie::Raylib::initWindow(size_t width, size_t heigth, const std::string title, bool resizable, int baseFps)
{
    if (resizable)
        SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    else
        SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(width, heigth, title.c_str());
    SetTargetFPS(baseFps);
}

void indie::Raylib::destroyWindow()
{
    CloseWindow();
}

bool indie::Raylib::windowShouldClose()
{
    return (WindowShouldClose());
}

void indie::Raylib::beginDrawing()
{
    BeginDrawing();
}

void indie::Raylib::endDrawing()
{
    EndDrawing();
}

bool indie::Raylib::isKeyPressed(KeyboardKey key)
{
    return (IsKeyPressed(key));
}

void indie::Raylib::clearBackground()
{

    ClearBackground(RAYWHITE);
}

void indie::Raylib::drawText(const std::string text, int posX, int posY, int fontSize, Color color)
{
    DrawText(text.c_str(), posX, posY, fontSize, color);
}

void indie::Raylib::drawCircle(int posX, int posY, float radius, Color color)
{
    DrawCircle(posX, posY, radius, color);
}

void indie::Raylib::drawRectangle(int posX, int posY, int width, int height, Color color)
{
    DrawRectangle(posX, posY, width, height, color);
}