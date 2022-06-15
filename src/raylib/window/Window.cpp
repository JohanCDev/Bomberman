/**
 * @file Window.cpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Window encapsulation source file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Window.hpp"

#include <iostream>

indie::raylib::Window *indie::raylib::Window::_window = nullptr;

indie::raylib::Window::Window(int width, int height, const std::string title, bool resizable, int baseFps)
{
    if (resizable)
        ::SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    else
        ::SetConfigFlags(FLAG_VSYNC_HINT);

    ::InitWindow(width, height, title.c_str());

    ::SetTargetFPS(baseFps);
    ::MaximizeWindow();
    indie::raylib::Sound::initAudioDevice();
}

indie::raylib::Window *indie::raylib::Window::getInstance(
    int width, int height, const std::string title, bool resizable, int baseFps)
{
    if (_window == nullptr) {
        _window = new Window(width, height, title, resizable, baseFps);
    }
    return _window;
}

int indie::raylib::Window::getFPS(void)
{
    return ::GetFPS();
}

void indie::raylib::Window::setTargetFPS(int fps)
{
    ::SetTargetFPS(fps);
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

void indie::raylib::Window::clearBackground(Color color)
{
    ::ClearBackground(color);
}

void indie::raylib::Window::toggleFullScreen()
{
    ::ToggleFullscreen();
}

bool indie::raylib::Window::isWindowResized()
{
    return ::IsWindowResized();
}
