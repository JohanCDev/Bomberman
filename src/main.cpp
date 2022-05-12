#include <raylib.h>
#include <unistd.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");
    CloseWindow();
    return 0;
}
