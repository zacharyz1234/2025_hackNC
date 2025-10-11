#include "gameState.cpp"



int main() {

    InitWindow(screenWidth, screenHeight, "Raylib Fullscreen Example");
    SetTargetFPS(60);

    setDefaults(); // 0 out all functions
    while (!WindowShouldClose()) {
        windowFunctions();

        //start draw
        BeginDrawing();

        HANDLESTATE();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
