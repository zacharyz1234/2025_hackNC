#include"windows.cpp"
#include"colors.cpp"
#include<queue>
extern Texture2D frames[2];
extern int currentFrame;


enum Gamestate{
    MAIN_MENU,
    GAME,
    GAME_END,
    
};

Gamestate state = MAIN_MENU;


Vector2 generateRandomPOS(){
    float rand = (float)GetRandomValue(10, 200);
    float rand2 = (float)GetRandomValue(10, 200);
    Vector2 r;
    r.x = rand;
    r.y = rand2;
    return r;
}


room generateNewRoom(){
    room r;
    r.roomID = nextRoomId;
    nextRoomId++;
    return r;
}


monster generateNewMonster(){
    monster r;
    r.health = currentDif;
    r.position = generateRandomPOS();
    return r;
}

void monsterQueue(std::queue<monster> monstersToUpdate){
while(!monstersToUpdate.empty()){
    monster r = monstersToUpdate.front();
    updateMonsterPOS(r);
}

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

