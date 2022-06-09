/*
** EPITECH PROJECT, 2022
** Window
** File description:
** Window
*/

#ifndef Window_HPP_
#define Window_HPP_

#include "../Raylib.hpp"

namespace indie {
    namespace raylib {
        class Window {
            public:
                /**
                * @brief Windows should not be clonable
                */
                Window(Window &other) = delete;

                /**
                * @brief Windows should not be assignable
                */
                void operator=(const Window &) = delete;

                /**
                * @brief Method that controls the access to the singleton Window instance.
                * On the first run it creates a Window, otherwise it returns the existing Window.
                */
                static Window *getInstance(int width, int height, const std::string title, bool resizable, int baseFps);

                /**
                * @brief Get current FPS
                */
                static int getFPS(void);

                /**
                * @brief Set target FPS (maximum)
                */
                static void setTargetFPS(int fps);

                /**
                * @brief Close window and unload OpenGL context
                */
                static void destroyWindow();

                /**
                * @brief Close window and unload OpenGL context
                */
                static int getWidth();
                /**
                * @brief Close window and unload OpenGL context
                */
                static int getHeight();

                /**
                * @brief Setup canvas (framebuffer) to start drawing
                */
                static void beginDrawing();

                /**
                * @brief End canvas drawing and swap buffers (double buffering)
                */
                static void endDrawing();

                /**
                * @brief Set background color (framebuffer clear color)
                */
                static void clearBackground(Color color);

                /**
                * @brief Check if KEY_ESCAPE pressed or Close icon pressed
                */
                static bool windowShouldClose();

                /**
                * @brief Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
                */
                static void toggleFullScreen();
            private:
                static Window *_window;
                Window(int width, int height, const std::string title, bool resizable, int baseFps);
        };
    }
}

#endif /* !Window_HPP_ */
