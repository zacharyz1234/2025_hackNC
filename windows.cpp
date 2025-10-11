#include "prim.cpp"






void windowFunctions(){
    ClearBackground(BLACK);

    if (IsKeyPressed(KEY_F)) {
    fullscreen = !fullscreen;

    if (fullscreen) {
        SetWindowState(FLAG_FULLSCREEN_MODE);
    } else {
        ClearWindowState(FLAG_FULLSCREEN_MODE);
        SetWindowSize(screenWidth, screenHeight);
            }
        }
}


