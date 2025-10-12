#include "gameState.cpp"

const int FRAMES = 2;
Texture2D frames[FRAMES];
int currentFrame = 0;
float frameTime = 0.2f; //Seconds per frame
float timer = 0.0f;

int main() {

    InitWindow(screenWidth, screenHeight, "Raylib Fullscreen Example");
    SetTargetFPS(60);

    //Load the textures AFTER the window is initialized
    frames[0] = LoadTexture("AdventurerFrame1.png");
    frames[1] = LoadTexture("AdventurerFrame2.png");

    setDefaults(); // 0 out all functions
    while (!WindowShouldClose()) {
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

        HANDLESTATE();

        EndDrawing();
    }

    //Unload textures
    for(int i = 0; i < FRAMES; i++)
    {
        UnloadTexture(frames[i]);
    }

    CloseWindow();
    return 0;
}
