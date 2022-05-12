#include <raylib.h>

#if defined(WIN32)
    #include <windows.h>
#else
    #include <unistd.h>
#endif

extern "C" void InitWindow(int width, int height, const char *title);
extern "C" void CloseWindow();

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");
    CloseWindow();
    return 0;
}
