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
            // Setup function
            static void initWindow(int width = 1920, int height = 1080, const std::string title = "Window",
                bool resizable = true, int baseFps = 60);
            static void destroyWindow();

            static int getWidth();
            static int getHeight();

            // Window function
            static void beginDrawing();
            static void endDrawing();
            static void clearBackground();
            static bool windowShouldClose();
        };
    }
}

#endif /* !Window_HPP_ */
