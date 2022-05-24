/*
** EPITECH PROJECT, 2022
** Raylib
** File description:
** Raylib
*/

#include "Raylib.hpp"

Raylib::Raylib()
{
}

Raylib::~Raylib()
{
}

extern "C"
{
    void Raylib::initWindow(size_t width, size_t heigth, const std::string title)
    {
        InitWindow(width, heigth, title.c_str());
        SetTargetFPS(60);
    }

    void Raylib::destroyWindow()
    {
        CloseWindow();
    }

    bool Raylib::windowShouldClose()
    {
        return (WindowShouldClose());
    }

    void Raylib::beginDrawing()
    {
        BeginDrawing();
    }

    void Raylib::endDrawing()
    {
        EndDrawing();
    }

    bool Raylib::isKeyPressed(KeyboardKey key)
    {
        return (IsKeyPressed(key));
    }

    void Raylib::clearBackground()
    {
        ClearBackground(RAYWHITE);
    }

    void Raylib::drawText(const std::string text, int posX, int posY, int fontSize, Color color)
    {
        DrawText(text.c_str(), posX, posY, fontSize, color);
    }

    void Raylib::drawCircle(int posX, int posY, float radius, Color color)
    {
        DrawCircle(posX, posY, radius, color);
    }

    void Raylib::drawRectangle(int posX, int posY, int width, int height, Color color)
    {
        DrawRectangle(posX, posY, width, height, color);
    }

    void Raylib::drawSphere(Vector3 centerPos, float radius, Color color)
    {
        DrawSphere(centerPos, radius, color);
    }

    void Raylib::drawRectangle3D(Vector3 position, float width, float height, float length, Color color)
    {
        DrawCube(position, width, height, length, color);
    }
}
