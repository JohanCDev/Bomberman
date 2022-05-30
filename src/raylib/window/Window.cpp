/*
** EPITECH PROJECT, 2022
** Raylib::Window
** File description:
** Raylib::Window
*/

#include "Window.hpp"

indie::raylib::Window *indie::raylib::Window::_window = nullptr;;

indie::raylib::Window::Window(int width, int height, const std::string title, bool resizable, int baseFps)
{
    if (resizable)
        ::SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    else
        ::SetConfigFlags(FLAG_VSYNC_HINT);
    ::InitWindow(width, height, title.c_str());
    ::SetTargetFPS(baseFps);
    toggleFullScreen();

}

indie::raylib::Window *indie::raylib::Window::getInstance(int width, int height, const std::string title, bool resizable, int baseFps)
{
    if(_window == nullptr){
        _window = new Window(width, height, title, resizable, baseFps);
    }
    return _window;
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

void indie::raylib::Window::toggleFullScreen()
{
    ::ToggleFullscreen();
}
