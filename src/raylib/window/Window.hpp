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
            Window(int width = 1920, int height = 1080);
            ~Window() = default;

            // Setup function
            void initWindow(const std::string title = "Window",
                bool resizable = true, int baseFps = 60);
            static void destroyWindow();

            static int getWidth();
            static int getHeight();
            // static ::Vector2 getWindowDimensions();
            // indie::vec2u getWindowDimensions();

            // Window function
            static void beginDrawing();
            static void endDrawing();
            static void clearBackground();
            static bool windowShouldClose();

        private:
            int _width;
            int _height;
        };
    }
}

#endif /* !Window_HPP_ */
