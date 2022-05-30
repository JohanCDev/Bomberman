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

                // Setup function
                static void destroyWindow();

                static int getWidth();
                static int getHeight();

                // Window function
                static void beginDrawing();
                static void endDrawing();
                static void clearBackground();
                static bool windowShouldClose();
                static void toggleFullScreen();
            private:
                static Window *_window;
                Window(int width, int height, const std::string title, bool resizable, int baseFps);
        };
    }
}

#endif /* !Window_HPP_ */
