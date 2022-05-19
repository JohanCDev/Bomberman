#include <raylib.h>
#include "test.hpp"

#if defined(WIN32)
    #include <windows.h>
#else
    #include <unistd.h>
    #include <iostream>
#endif

extern "C" void InitWindow(int width, int height, const char *title);
extern "C" void CloseWindow();

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");
    CloseWindow();
    std::cout << TEST << std::endl;
    return 0;
}
