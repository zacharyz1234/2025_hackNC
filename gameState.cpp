#include"windows.cpp"
#include"colors.cpp"


enum Gamestate{
    MAIN_MENU,
    GAME,
    GAME_END,
    
};

Gamestate state = MAIN_MENU;





void HANDLESTATE(){
        switch (state) {
            case MAIN_MENU:
                DrawText("MAIN MENU", 200, 150, 40, WHITE);
                DrawText("PRESS [ENTER] TO START", 180, 250, 20, WHITE);
                DrawText("PRESS [ESC] TO QUIT", 200, 300, 20, WHITE);
                break;

            case GAME:
                DrawText("PLAYING GAME...", 180, 200, 30, GREEN);
                DrawText("PRESS [ESC] TO RETURN TO MENU", 80, 300, 20, WHITE);
                break;

            case GAME_END:
                DrawText("GAME OVER", 180, 200, 30, RED);
                break;
        }
}

