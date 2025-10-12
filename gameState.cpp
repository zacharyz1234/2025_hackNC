#include"windows.cpp"
#include"colors.cpp"
#include<queue>
#include "cStructs.h"
#include <cstdlib> 
#include <ctime> 
extern Texture2D frames[2];
extern int currentFrame;



Vector2 generateRandomPOS(int screenWidth, int screenHeight) {
    Vector2 r = { 0 };
    int side = GetRandomValue(0, 3); // 0=top, 1=bottom, 2=left, 3=right

    switch (side) {
        case 0: // top
            r.x = (float)GetRandomValue(0, screenWidth);
            r.y = -50.0f; // just above the screen
            break;
        case 1: // bottom
            r.x = (float)GetRandomValue(0, screenWidth);
            r.y = (float)screenHeight + 50.0f; // just below
            break;
        case 2: // left
            r.x = -50.0f;
            r.y = (float)GetRandomValue(0, screenHeight);
            break;
        case 3: // right
            r.x = (float)screenWidth + 50.0f;
            r.y = (float)GetRandomValue(0, screenHeight);
            break;
    }

    return r;
}

monster generateNewMonster() {
    monster m;
    Vector2 pos = generateRandomPOS(screenWidth, screenHeight); 
    m.position.x = pos.x + GetRandomValue(20, 50);
    m.position.y = pos.y;
    return m;
}

void updateMonsterPOS(monster &m, Vector2 playerPos) {
    Vector2 dir = { playerPos.x - m.position.x, playerPos.y - m.position.y };
    float len = sqrtf(dir.x * dir.x + dir.y * dir.y);
    if (len > 0.01f) {
        dir.x /= len;
        dir.y /= len;
        m.position.x += dir.x * DEFAULTMONSTERSPEED;
        m.position.y += dir.y * DEFAULTMONSTERSPEED;
    }
}

room generateNewRoom() {
    room r;
    r.init = true;
    r.roomID = nextRoomId++;
    r.isPlayerIn = false;
    r.hasPlayerVisted = false;

    r.toLeft = -1;
    r.toRight = -1;
    r.toUP = -1;
    r.toDown = -1;


    //Generate monsters
    int monsterCount = 4;
    for (int i = 0; i < monsterCount; i++) {
        r.monsterNumber.push_back(generateNewMonster());
    }

    return r;
}



void populateRoomWithMonsters(std::vector<monster> &mons, int count) {
    for (int i = 0; i < count; i++) {
        mons.push_back(generateNewMonster());
    }
}

void genFirstRoom(){
    room firstRoom = generateNewRoom();
    firstRoom.isPlayerIn = true;
    roomVec.push_back(firstRoom);
}

void gameRunning(PlayerStats player){
     Texture2D FloorTiles = LoadTexture("floor.png");
    DrawTexture(FloorTiles, 0, 0, WHITE);
    //DrawRoom(((GetScreenWidth()/2) - 20), ((GetScreenHeight()/2)+20));
    updatePlayerPOS(theUser);
    drawMonsters(roomVec, theUser);
    DrawRetroHUD(player, GetScreenWidth(), GetScreenHeight());
    DrawTexture(frames[currentFrame], theUser.x, theUser.y, WHITE);

}

void drawMenu(){
    //DrawText("Press [F] to toggle fullscreen", 40, 40, 20, RAYWHITE);
    //DrawText("Press [ESC] to quit", 70, 70, 20, RAYWHITE);
    DrawRectangle(740, 300, 430, 65, GRAY);
    DrawText("MAIN MENU", 750, 300, 70, WHITE);
    DrawText("PRESS [ENTER] TO START", 815, 380, 20, WHITE);
    DrawText("PRESS [ESC] TO QUIT", 845, 425, 20, WHITE);
}


void HANDLESTATE(PlayerStats player){
        switch (state) {
            case MAIN_MENU:
                drawMenu();
                if(IsKeyPressed(KEY_ENTER)){
                    state = GAME;
                }
                break;

            case GAME:
                gameRunning(player);
                break;

            case GAME_END:
                DrawText("GAME OVER", 180, 200, 30, RED);
                break;
        }
}

