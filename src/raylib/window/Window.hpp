/**
 * @file Window.hpp
 * @author Simon Le Fourn (simon.le-fourn@epitech.eu)
 * @brief Window encapsulation header file
 * @version 0.1
 * @date 2022-05-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef Window_HPP_
#define Window_HPP_

#include "../Raylib.hpp"

namespace indie
{
    namespace raylib
    {
        /// @brief Window class encapsulation
        class Window {
          public:
            /**
             * @brief Windows should not be clonable
             * 
             * @param other Window object
             */
            Window(Window &other) = delete;
            /**
             * @brief Windows should not be assignable
             * 
             * @param other Window object
             */
            void operator=(const Window &other) = delete;
            /**
             * @brief Method that controls the access to the singleton Window instance.
             * On the first run it creates a Window, otherwise it returns the existing Window.
             * 
             * @param width Window width
             * @param height Window height
             * @param title Window title
             * @param resizable Is window resizable ?
             * @param baseFps Window base FPS
             * 
             * @return Window* Window pointer
             */
            static Window *getInstance(int width, int height, const std::string title, bool resizable, int baseFps);
            /**
             * @brief Get current FPS
             * 
             * @return int Window FPS
             */
            static int getFPS(void);
            /**
             * @brief Set target FPS (maximum)
             * 
             * @param fps Number of fps
             */
            static void setTargetFPS(int fps);
            /**
             * @brief Close window and unload OpenGL context
             */
            static void destroyWindow();
            /**
             * @brief Get current window width
             * 
             * @return int Window width
             */
            static int getWidth();
            /**
             * @brief Get current window height
             * 
             * @return int Window height
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
             * 
             * @param color Background color
             */
            static void clearBackground(Color color);
            /**
             * @brief Check if KEY_ESCAPE pressed or Close icon pressed
             * 
             * @return true The window should close (ESC pressed)
             * @return false The window shouldn't close (ESC not pressed)
             */
            static bool windowShouldClose();
            /**
             * @brief Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP)
             */
            static void toggleFullScreen();
            /**
             * @brief Is the window resized?
             * 
             * @return true The window has been resized
             * @return false The window hasn't been resized
             */
            static bool isWindowResized(void);

          private:
            /**
             * @brief Window pointer
             * 
             */
            static Window *_window;
            /**
             * @brief Construct a new Window object
             * 
             * @param width Window width
             * @param height Window height
             * @param title Window title
             * @param resizable Is window resizable ?
             * @param baseFps Window base FPS
             */
            Window(int width, int height, const std::string title, bool resizable, int baseFps);
        };
    } // namespace raylib
} // namespace indie

#endif /* !Window_HPP_ */
