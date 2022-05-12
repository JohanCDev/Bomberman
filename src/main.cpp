#include <raylib.h>
#include <unistd.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");
    DrawCircle(screenWidth / 2, screenHeight / 2, 50, GREEN);
    sleep(5);
    CloseWindow();
    return 0;
}
