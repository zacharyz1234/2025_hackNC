#include "gameState.cpp"



int main() {

    InitWindow(screenWidth, screenHeight, "Raylib Fullscreen Example");
    SetTargetFPS(60);


    while (!WindowShouldClose()) {
        windowFunctions();



        //start draw
        BeginDrawing();
        ClearBackground((Color{40, 50, 60, 255}));

        DrawText("Press [F] to toggle fullscreen", 40, 40, 20, RAYWHITE);
        DrawText("Press [ESC] to quit", 40, 70, 20, RAYWHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
