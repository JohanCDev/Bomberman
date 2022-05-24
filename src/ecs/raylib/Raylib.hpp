/*
** EPITECH PROJECT, 2022
** Raylib
** File description:
** Raylib
*/

#ifndef RAYLIB_HPP_
#define RAYLIB_HPP_

#include <raylib.h>
#include <cstdio>
#include <string>

class Raylib {
    public:
        Raylib();
        ~Raylib();

        // Setup function
        void initWindow(std::size_t width, std::size_t heigth, const std::string title);
        void destroyWindow();
        
        // Event function
        bool isKeyPressed(KeyboardKey key);
        
        // Window function
        void beginDrawing();
        void endDrawing();
        void clearBackground();
        bool windowShouldClose();

        // Drawing function
        void drawText(const std::string text, int posX, int posY, int fontSize, Color color);
        void drawCircle(int posX, int posY, float radius, Color color);
        void drawRectangle(int posX, int posY, int width, int height, Color color);
        void drawSphere(Vector3 centerPos, float radius, Color color);
        void drawRectangle3D(Vector3 position, float width, float height, float length, Color color);
        void drawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color);
        void drawCubeWires(Vector3 position, float width, float height, float length, Color color);
        bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius);

    protected:
    private:
};

#endif /* !RAYLIB_HPP_ */
