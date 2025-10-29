#include "gameState.cpp"
#include "cStructs.h"


float frameTime = 0.2f; //Seconds per frame
float timer = 0.0f;

int main() {
    srand(time(0)); // seed for rand
    InitWindow(global_screenWidth, global_screenHeight, "Raylib Fullscreen Example");
    SetTargetFPS(60);

    loadEnemyTextures();

    
   
    Texture2D ScreenOverlay = LoadTexture("images/Screen_overlay.png");
    Texture2D overlayFrame = LoadTexture("images/UNC_Boy_Frame.png");



    //Load the textures AFTER the window is initialized
    frames[0] = LoadTexture("images/AdventurerFrame1.png");
    frames[1] = LoadTexture("images/AdventurerFrame2.png");
    PlayerStats player = { 100, 0, 0.0f };
    double startTime = GetTime();

    setDefaults(); // 0 out all functions
    genFirstRoom();

    int timeAlive;

    while (!WindowShouldClose()) {
        float delta = GetFrameTime(); // seconds passed since last frame

        if (global_isGameRunning) {
            timeAlive += delta;}  // accumulate time while game is active}
        player.timeAlive = timeAlive;
        windowFunctions();

        //Update animation timer
        float dt = GetFrameTime();
        timer += dt;
        if(timer >= frameTime)
        {
            currentFrame = (currentFrame + 1) % FRAMES;
            timer = 0.0f;
        }

        //start draw
        BeginDrawing();
        

        HANDLESTATE(player);
        

        DrawTexture(ScreenOverlay, 0, 0, WHITE);
        //Draw overlay last so it stays on top
        DrawTexture(overlayFrame, 0, 0, WHITE);

        EndDrawing();
    }

    //Unload textures
    for(int i = 0; i < FRAMES; i++)
    {
        UnloadTexture(frames[i]);
    }

    unloadEnemyTextures();
   
    UnloadTexture(overlayFrame);
    UnloadTexture(ScreenOverlay);

    CloseWindow();
    return 0;
}
