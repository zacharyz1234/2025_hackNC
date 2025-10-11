#include"windows.cpp"
#include"colors.cpp"


enum Gamestate{
    MAIN_MENU,
    GAME,
    GAME_END,
    
};

Gamestate state = MAIN_MENU;









void gameRunning(){
    updatePlayerPOS(theUser);
    DrawCircle(theUser.x, theUser.y, (float)5, RED);
}


void HANDLESTATE(){
        switch (state) {
            case MAIN_MENU:
                DrawText("Press [F] to toggle fullscreen", 40, 40, 20, RAYWHITE);
            DrawText("Press [ESC] to quit", 40, 70, 20, RAYWHITE);
                DrawText("MAIN MENU", 200, 150, 40, WHITE);
                DrawText("PRESS [ENTER] TO START", 180, 250, 20, WHITE);
                DrawText("PRESS [ESC] TO QUIT", 200, 300, 20, WHITE);
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

