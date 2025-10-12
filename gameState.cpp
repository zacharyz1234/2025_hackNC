#include"windows.cpp"
#include"colors.cpp"

extern Texture2D frames[2];
extern int currentFrame;


enum Gamestate{
    MAIN_MENU,
    GAME,
    GAME_END,
    
};

Gamestate state = MAIN_MENU;


room generateNewRoom(){
    room r;
    r.roomID = nextRoomId;
    nextRoomId++;
    return r;
}






void gameRunning(){
    updatePlayerPOS(theUser);
    DrawTexture(frames[currentFrame], theUser.x, theUser.y, WHITE);
}

void drawMenu(){
    //DrawText("Press [F] to toggle fullscreen", 40, 40, 20, RAYWHITE);
    //DrawText("Press [ESC] to quit", 70, 70, 20, RAYWHITE);
    DrawText("MAIN MENU", 345, 150, 40, WHITE);
    DrawRectangleLines(335, 140, 253, 50, RED);
    DrawText("PRESS [ENTER] TO START", 320, 250, 20, WHITE);
    DrawText("PRESS [ESC] TO QUIT", 345, 300, 20, WHITE);
}


void HANDLESTATE(){
        switch (state) {
            case MAIN_MENU:
                drawMenu();
                if(IsKeyPressed(KEY_ENTER)){
                    state = GAME;
                }
                break;

            case GAME:
                gameRunning();
                break;

            case GAME_END:
                DrawText("GAME OVER", 180, 200, 30, RED);
                break;
        }
}

