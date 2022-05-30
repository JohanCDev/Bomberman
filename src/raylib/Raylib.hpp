/*
** EPITECH PROJECT, 2022
** Raylib
** File description:
** Raylib
*/

#ifndef RAYLIB_HPP_
#define RAYLIB_HPP_

#include <cstdio>
#include <raylib.h>
#include <string>
#include "RColor.hpp"
#include "Vec2.hpp"
#include "events.hpp"

namespace indie
{
    /**
     * @brief Raylib encapsulation class
     */
    class Raylib {
      public:
        /**
         * @brief Construct a new Raylib object
         */
        Raylib();
        /**
         * @brief Destroy the Raylib object
         */
        ~Raylib();

        /**
         * @brief Initialize a Raylib Window
         *
         * @param width width of the window
         * @param heigth height of the window
         * @param title title of the window
         * @param resizable The window is resizable or not
         * @param baseFps start fps of the window
         */
        static void initWindow(size_t width = 1920, size_t heigth = 1080, const std::string title = "Window",
            bool resizable = true, int baseFps = 60);

        /**
         * @brief Destroy the window
         *
         */
        static void destroyWindow();

        /**
         * @brief Know if a key is pressed
         *
         * @param key key to check
         * @return true if the key is pressed
         * @return false if the key isn't presed
         */
        static bool isKeyPressed(KeyboardKey key);

        /**
         * @brief Start the drawing on the window
         */
        static void beginDrawing();
        /**
         * @brief End the drawing on the window
         */
        static void endDrawing();
        /**
         * @brief Clear the background of the window
         */
        static void clearBackground();
        /**
         * @brief Know if the window should close or not
         *
         * @return true if it should
         * @return false if it shouldn't
         */
        static bool windowShouldClose();

        /**
         * @brief Draw a text on the window
         *
         * @param text text to display
         * @param posX x position
         * @param posY y position
         * @param fontSize size of the text
         * @param color color of the text
         */
        static void drawText(const std::string text, int posX, int posY, int fontSize, Color color);
        /**
         * @brief Draw a circle on the window
         *
         * @param posX x position
         * @param posY y position
         * @param radius circle's radius
         * @param color color of the circle
         */
        static void drawCircle(int posX, int posY, float radius, Color color);
        /**
         * @brief Draw a rectangle on the window
         *
         * @param posX x position
         * @param posY y position
         * @param width width of the rectangle
         * @param height height of the rectangle
         * @param color color of the rectangle
         */
        static void drawRectangle(int posX, int posY, int width, int height, Color color);

        static indie::vec2u getWindowDimensions();

        static void drawSphere(Vector3 centerPos, float radius, Color color);
        static void drawRectangle3D(Vector3 position, float width, float height, float length, Color color);
        static void drawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color);
        static void drawCubeWires(Vector3 position, float width, float height, float length, Color color);
        static bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);

      protected:
      private:
    };
} // namespace indie

#endif /* !RAYLIB_HPP_ */
