#include "gameState.cpp"



int main() {

    InitWindow(screenWidth, screenHeight, "Raylib Fullscreen Example");
    SetTargetFPS(60);


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
