#include "prim.cpp"




void windowFunctions(){
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


